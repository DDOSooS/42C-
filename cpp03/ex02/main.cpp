#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

int main()
{
    ClapTrap player("ABDE");
    ClapTrap t = player;
    ScavTrap s("ahmed");
    FragTrap f("player42");

    player.attack("imade");
    s.attack("player2");
    f.highFivesGuys();
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    // player.attack("imade");
    player.takeDamage(4);
    player.beRepaired(20);
    return 0;
}