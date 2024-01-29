#pragma once
#include<iostream>
#include<array>
#include<string>


//définition de la matrice
const int nbLigne=6;
const int nbColonne=7;
using colonne=std::array<char,nbColonne>;
using matrice=std::array<colonne,nbLigne>;




//définition d'un joueur
struct joueur
{
    char val;
    std::string nom_joueur;

};



//définition  d'une table de jeu
struct table_jeu{
     matrice la_matrice;
     joueur * table_joueur;
};

// DECLARATION DU TABLEAU QUI SERA UTILISER DANS  MEILLEURE CHOIX
using table = std::array<int, nbColonne>;

