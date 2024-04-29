#include <SDL.h>
#include <stdio.h>

#include "init.h"
#include "affichage.h"
#include "controlleur.h"


int main(int argc, char* argv[]) {

    initSDL();

    // create SDL window & render
    SDL_Window* window = initWindow();
    SDL_Renderer* renderer = initRender(window);

    int x = 50;
    int y = 50;
    int taille = 50;
    int continuer = 1;
    int player_up=0;
    int player_down=0;
    int player_right=0;
    int player_left=0;
    int dx = 5;
    int dy = 0;

    while (continuer)
    {
        clearRendu(renderer);

        draw(renderer, x, y, taille, taille,0,255,0);

        controlleur(&continuer, &player_up, &player_down, &player_right,
            &player_left, taille, &dy, &dx);

        x += dx;
        y += dy;

        // update rendu
        SDL_RenderPresent(renderer);
        SDL_Delay(10);

    }

    void freeAll(renderer, window);


    return 0;
}