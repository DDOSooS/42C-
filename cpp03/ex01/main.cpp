#include "./ScavTrap.hpp"

int main()
{
    ClapTrap player("ABDE");
    ClapTrap t = player;
    ScavTrap s("ahmed");

    player.attack("imade");
    s.attack("player2");
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