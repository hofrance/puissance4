#pragma once
#include "puissance4api.hh"
#include"ia.h"



//fonction qui permet de retrouver le char de l'autre joueur
char le_charactere_de_l_autre_joueur(p4plateau p,char le_char_connu);

//on copie le p4platea dans notre structure matrice
void copie_plateau(p4plateau a_copier, matrice& copie);