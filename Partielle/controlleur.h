#pragma once
#ifndef CONTROLLEUR_H
#define CONTROLLEUR_H

void mouvement(SDL_Event evenement, int* player_up, int* player_down,
    int* player_right, int* player_left, int valeur);

void controlleur(int* continuer, int* player_up, int* player_down,
    int* player_right, int* player_left, int taille, int* dy,
    int* dx);

#endif