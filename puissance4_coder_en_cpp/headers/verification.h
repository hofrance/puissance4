#pragma once
#include"jeu.h"
#include"declaration.h"
#include<iostream>
#include<array>
#include<string>
void init_table_de_jeu(table_jeu &k, int nb_joueur);
// on véifie si une étiquette n'a pas déjà été saisie
bool verif_presence_etiquette(table_jeu t,char x,int rang_joueur );

//on vérifie si un nom n'a pas déjà été saisie
bool verif_presence_nom(table_jeu t,std::string x,int rang_joueur);

//on vérifie si une colonne est remplie
bool est_remplie(matrice m,int num_colonne);

//on verifie si une case est valide ou existante
bool point_existe(matrice m,int num_colonne, int num_ligne);

//fonction qui vérifie si il rest des cases vides 
bool reste_case_vide(table_jeu jeu);


// le nombres d'occurences générale
int nb_occurence_direction(matrice m, int num_colonne, int num_ligne,int x_ligne,int y_colonne);


//fonction qui vérifie si une colonne est pleine ou pas;
bool est_remplie(matrice m,int num_colonne);

//le nombres d'occurences
int les_occurences_ligne(matrice m, int num_colonne,int num_ligne);
int les_occurences_premiere_diag(matrice m, int num_colonne,int num_ligne);
int les_occurences_colonne(matrice m, int num_colonne,int num_ligne);    
int les_occurences_seconde_diag(matrice m, int num_colonne,int num_ligne);

//procédure qui permet de resaisir une colonne si elle est pas valide
void colonne_valide(table_jeu jeu, joueur j,int numCol);



//detection de la victoire
bool victoire(matrice m,int num_colonne,int num_ligne);


//on vérifie si on peut faire (case vide suivie de notre jeton suivie d'une case vide suivie de notre jeton suivie s'une case vide)

