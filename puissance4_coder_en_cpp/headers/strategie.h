#pragma once
#include "verification.h"
#include <random>
#include <cstdlib>
#include<ctime>

void init_table(table &t);

void copie_matrice(matrice a_copier, matrice &copie);
void colonne_gagnante(matrice &m, joueur ordi, joueur autre_j,table & t,int nb_coup);