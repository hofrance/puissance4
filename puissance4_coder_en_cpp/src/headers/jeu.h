#pragma once
#include"declaration.h"
#include<iostream>
#include<array>
#include<string>




//fonction qui affiche le plateau de jeu
void affiche_plateau(table_jeu jeu);

//initialisation d'une matrice
void init_matrice(matrice &m);




//procedure permettant de mettre un pions dans une colonne
void mettre_en_bas(joueur j, matrice &m, int numCol) ;// on place l'étiquette le plus bas possible

int position_case(matrice jeu, int num_colonne, char x);


//on faitl'initialisation des joueurs, et de(des) la  matrice(s);
void init_table_de_jeu(table_jeu &k, int nb_joueur);

//procedure qui permet de faire jouer l'ia
void partie_humain_contre_humain(table_jeu & jeu,int nb_joueur);


void fin_partie(table_jeu & jeu);


