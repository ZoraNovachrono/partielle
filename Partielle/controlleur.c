#include <SDL.h>
#include <stdio.h>

#include "controlleur.h"

#define TAILLE  50

//interpreter les inputs du joueur
void action(SDL_Event evenement, int* player1_up, int* player1_down,
    int* player1_right, int* player1_left, int valeur) {
    switch (evenement.key.keysym.sym) {
    case SDLK_z:
        *player1_up = valeur;
        break;
    case SDLK_s:
        *player1_down = valeur;
        break;
    case SDLK_d:
        *player1_right = valeur;
        break;
    case SDLK_q:
        *player1_left = valeur;
        break;
    }
}

//récupère les inputs du joueur
void controller(int* continuer, int* player1_up, int* player1_down,
    int* player1_left, int* player1_right) {
    // Gestion des événements
    SDL_Event event;

    // Récupération de tous les événements en attente
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            *continuer = 0;
        }
        else if (event.type == SDL_KEYDOWN) {
            action(event, player1_up, player1_down, player1_right,
                player1_left, 1);
            printf("get input ");
        }
        else if (event.type == SDL_KEYUP) {
            action(event, player1_up, player1_down, player1_right,
                player1_left, 0);
            printf("get input ");
        }
    }
}



//utilise les interpretation des inputs pour bouger le gameObj
int deplacementDiagonale(int player1_left, int player1_right, int x) {
    if (player1_left && x >= 0) {
        x -= 10;
    }
    else if (player1_right && x + TAILLE <= 1920) {
        x += 10;
    }
    return x;
}

void deplacement(int* y, int* x, int player1_up
    , int player1_left, int player1_down, int player1_right) {

    if (player1_up && *y >= 0) {
        *x = deplacementDiagonale(player1_left, player1_right, *x);
        *y -= 10;
        printf("go up ");
    }
    else if (player1_down && *y + TAILLE <= 1080) {
        *x = deplacementDiagonale(player1_left, player1_right, *x);
        *y += 10;
        printf("go down ");
    }
    else if (player1_left && *x >= 0) {
        *x -= 10;
        printf("go left ");
    }
    else if (player1_right && *x + TAILLE <= 1920) {
        *x += 10;
        printf("go right ");
    }
}