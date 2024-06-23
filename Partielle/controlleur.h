#pragma once
#ifndef CONTROLLEUR_H
#define CONTROLLEUR_H

void controller(int* continuer, int* player1_up, int* player1_down,
    int* player1_left, int* player1_right);

void deplacement(int* y, int* x, int player1_up
    , int player1_left, int player1_down, int player1_right);

#endif