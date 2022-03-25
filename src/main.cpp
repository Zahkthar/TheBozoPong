/*
    Idées :
        Menus : Menu Principal, Partie principale, Game Over
        Partie contre le mur : La balle va de plus en plus vite et le but est de tenir le plus longtemps
        Ajouter des items qui pop au milieu du terrain qui peuvent changer le comportement du jeu
        Faire accélérer la balle à chaque collision dans le mode de jeu normal
*/

#include "Game.hpp"

int main()
{
    Game game;
    game.run();

    return 0;
}