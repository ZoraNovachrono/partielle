#include <SDL.h>
#include <stdio.h>

#include "controlleur.h"


void mouvement(SDL_Event evenement, int* player_up, int* player_down,
    int* player_right, int* player_left, int valeur) {
    switch (evenement.key.keysym.sym) {
    case SDLK_LEFT:
        player_left = valeur;
        break;
    case SDLK_RIGHT:
        player_right = valeur;
        break;
    case SDLK_UP:
        player_up = valeur;
        break;
    case SDLK_DOWN:
        player_down = valeur;
        break;
    }
}

void controlleur(int* continuer, int* player_up, int* player_down,
    int* player_right, int* player_left, int taille, int* dy,
    int* dx) {
    // Controlleur
    SDL_Event evenement;
    int vitesse = 5;

    // Récupérer tous les événements en attente
    while (SDL_PollEvent(&evenement) != 0) {
        if (evenement.type == SDL_QUIT) {
            continuer = 0;
        }
        else if (evenement.type == SDL_KEYDOWN) {
            mouvement(evenement, *player_up, *player_down, *player_right, *player_left, 1);
        }
        else if (evenement.type == SDL_KEYUP) {
            mouvement(evenement, *player_up, *player_down, *player_right, *player_left, 0);
        }
    }
    if (player_up==1 && *dy > 0) {
        *dy = -(vitesse);
        *dx = 0;
        printf("go");
    }
    else if (player_up == 1 && *dy < 0) {
        *dy = -(vitesse);
        *dx = 0;
        printf("go");
    }
    if (player_down == 1 && *dy < 0) {
        *dy = vitesse;
        *dx = 0;
        printf("go");
    }
    else if (player_down == 1 && *dy > 0) {
        *dy = vitesse;
        *dx = 0;
        printf("go");
    }

    if (player_right == 1 && *dx > 0) {
        *dy = 0;
        *dx = vitesse;
        printf("go");
    }
    else if (player_right == 1 && *dx < 0) {
        *dy = 0;
        *dx = vitesse;
        printf("go");
    }
    if (player_left == 1 && *dx < 0) {
        *dy = 0;
        *dx = -(vitesse);
        printf("go");
    }
    else if (player_left == 1 && *dx > 0) {
        *dy = 0;
        *dx = -(vitesse);
        printf("go");
    }

}