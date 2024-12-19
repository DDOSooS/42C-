# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <limits.h>
#include <string.h>

// ls -la "|" cat -e ";" ls -la 

#define STDIN 0
#define STDOUT 1
#define STDERR 2
error: cannot execute executable_that_failed
enum TYPE
{
    ARG,
    PIPE,
    SEMC
};

typedef struct s_cmds
{
    char        **args;
    int         inFD;
    int         outFD;
    struct      s_cmds *next;
}   t_cmd;

typedef struct s_microshell
{
    t_cmd *cmd;
    struct s_microshell *next;
}   t_mshell;


void ftAddBackBcmd(t_mshell **root, t_mshell *new)
{
    if (!*root)
    {
        (*root) = new;
        return ;
    }
    t_mshell *tmp;

    tmp = (*root);
    while (tmp->next)
        tmp = tmp->next;
    tmp->next= new;
}

void ftAddCmd(t_cmd **root, t_cmd *new)
{

    if (!*root)
    {
        (*root) = new;
        return ;
    }
    t_cmd *tmp;
    
    tmp = *root;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

t_cmd   *newCmd(int start, int end, char **av)
{
    t_cmd   *new;
    char    **arg;

    new = malloc(sizeof(t_cmd));
    arg = malloc(sizeof(char *) * (end - start + 1));
    int i;
    i = 0;
    while (start < end)
        arg[i++] = av[start++];
    arg[i] = NULL;
    new->args = arg;
    new->next = NULL;
    return (new);
}

t_cmd   *ftGenCmds(int start, int end, char **av)
{
    t_cmd   *cmds;
    int     oldIndex;
    t_cmd   *tmp;

    oldIndex = start;
    cmds = NULL;
    while (start < end)
    {
        if (!strcmp(av[start], "|"))
        {
            tmp = newCmd(oldIndex, start, av);
            ftAddCmd(&cmds, tmp);
            oldIndex = start + 1;
        }
        start++;
    }
    tmp = newCmd(oldIndex, start,av);
    ftAddCmd(&cmds, tmp);
    return (cmds);
}

t_mshell *ftGenNewBlockCmd(int start, int end, char **args)
{
    t_mshell *new;

    new = malloc(sizeof(t_mshell));
    if (!new)
        return (NULL);
    new->cmd = ftGenCmds(start, end, args);
    new->next = NULL;
    return new;
}

int parse_args(int ac, char **av, t_mshell **cmds)
{
    int         i;
    int         old_index;
    t_mshell    *tmp;
    
    i = 0;
    old_index = 1;
    while (++i < ac)
    {
        if (!strcmp(av[i], ";"))
        {
            tmp = ftGenNewBlockCmd(old_index, i, av);        
            ftAddBackBcmd(cmds, tmp);
            old_index = i + 1;
        }
    }
    tmp = ftGenNewBlockCmd(old_index, ac, av);        
    ftAddBackBcmd(cmds, tmp);
    return (1);
}

void print_parsed_structure(t_mshell *blocks)
{
    int block_num = 1;

    if (blocks)
        printf(" === blocks exist == \n");
    else
        printf(" === blocks !exist == \n");
    while (blocks)
    {
        printf("Block %d:\n", block_num++);    
        t_cmd *cmd = blocks->cmd;
        int cmd_num = 1;
        
        while (cmd)
        {
            printf("  Command %d:\n", cmd_num++);
            for (int i = 0; cmd->args[i]; i++)
                printf(" %s\n", cmd->args[i]);
            printf("\n");
            cmd = cmd->next;
        }
        blocks = blocks->next;
    }
}

int ftCountNcmd(t_cmd *cmds)
{
    int counter;

    counter = 0;
    while (cmds)
    {
        counter++;
        cmds = cmds->next;
    }
    return (counter);
}


void executeCmd(t_cmd *cmds, char **env_p)
{
    // Count number of commands
    int counter = ftCountNcmd(cmds);
    
    // Allocate file descriptors for pipes
    int **fds = malloc(sizeof(int *) * (counter - 1));
    if (!fds) {
        perror("Memory allocation failed for pipe array");
        return;
    }

    // Initialize pipe file descriptors
    for (int tmp = 0; tmp < counter - 1; tmp++) {
        fds[tmp] = malloc(sizeof(int) * 2);
        if (!fds[tmp] || pipe(fds[tmp]) == -1) {
            perror("Pipe creation failed");
            // Cleanup previous allocations
            for (int i = 0; i < tmp; i++) {
                free(fds[i]);
            }
            free(fds);
            return;
        }
    }

    pid_t *pid = malloc(sizeof(pid_t) * counter);
    if (!pid) {
        perror("Memory allocation failed for pid array");
        // Cleanup pipe allocations
        for (int i = 0; i < counter - 1; i++) {
            free(fds[i]);
        }
        free(fds);
        return;
    }


   
    t_cmd *current = cmds;
    for (int i = 0; i < counter; i++)
    {
        pid[i] = fork();
        
        if (pid[i] == -1) {
            perror("Fork failed");
            break;
        }
        
        if (pid[i] == 0)
        { 
            if (i > 0) {
                if (dup2(fds[i-1][0], STDIN_FILENO) == -1) {
                    perror("Input redirection failed");
                    exit(1);
                }
            }
            
            if (i < counter - 1) {
                if (dup2(fds[i][1], STDOUT_FILENO) == -1) {
                    perror("Output redirection failed");
                    exit(1);
                }
            }
            for (int j = 0; j < counter - 1; j++) {
                close(fds[j][0]);
                close(fds[j][1]);
            }
            if (strcmp("cd", current->args[0]) == 0)  // Note the == 0
            {
                if (current->args[1] != NULL && current->args[2] == NULL)
                {
                    if (chdir(current->args[1]) != 0)
                    {
                        perror("cd failed");
                        exit(1);
                    }
                    exit(0);
                }
                else
                {
                    fprintf(stderr, "cd: incorrect number of arguments\n");
                    exit(1);
                }
            }
            execve(current->args[0], current->args, env_p);
            perror("Execution failed");
            exit(1);
        }
        current = current->next;
    }


    for (int j = 0; j < counter - 1; j++)
    {
        close(fds[j][0]);
        close(fds[j][1]);
    }

    // Wait for all child processes
    for (int i = 0; i < counter; i++)
    {
        int status;
        waitpid(pid[i], &status, 0);
        if (WIFEXITED(status))
        {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0) {
                fprintf(stderr, "Command exited with status %d\n", exit_status);
            }
        }
    }
}

void execute_cmds(t_mshell *cmds, char **env_p)
{
    while (cmds) {
        executeCmd(cmds->cmd, env_p);
        cmds = cmds->next;
    }    
}
int main(int ac, char **av, char **env)
{
    t_mshell *cmds = NULL;

    if (ac == 1)
        return (0);
    if (!parse_args(ac, av, &cmds))
        return (printf("=== PROGRAM FAILED ====\n"), 0);
    execute_cmds(cmds, env);
    return (0);
}