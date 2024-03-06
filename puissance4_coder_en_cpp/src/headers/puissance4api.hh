#pragma once

#include <array>

/**	Largeur du plateau de jeu. */
const std::size_t p4largeur=7;
/**	Hauteur du plateau de jeu. */
const std::size_t p4hauteur=6;

/**	Jeton de puissance 4. La valeur particulière ' ' est utilisée pour
 * représenter une case vide. */
using p4jeton = char;

/**	Une colonne du plateau de jeu. */
using p4colonne = std::array<p4jeton, p4hauteur>;
/**	Un plateau de jeu de puissance 4 est représenté comme un tableau à deux
 * dimensions dans lequel la première dimension est la colonne et la seconde
 * dimension la ligne.
 * Ainsi soit, p un p4plateau, p[2][3] désignera la case du plateau située en
 * colonne 2, sur la ligne 3.
 * Les colonnes sont numérotées à partir de 0 en partant de la gauche, les
 * lignes sont numérotées à partir de 0 en partant du haut. */
using p4plateau = std::array<p4colonne, p4largeur>;

/**	Sous-programme d'initialisation d'un plateau de jeu.
 * Vous n'êtes pas obligés d'utiliser ce sous-programme, il est donné à titre
 * indicatif, mais peut vous être utile dans le cadre de tests. */
void p4initialiser(p4plateau & p);
/**	Sous programme d'affichage d'un plateau de jeu.
 * Vous n'êtes pas obligés d'utiliser ce sous-programme, il est donné à titre
 * indicatif, mais peut vous être utile dans le cadre de tests. */
void p4afficher(p4plateau p);
/**	Sous programme jouant dans une colonne.
 * Vous n'êtes pas obligés d'utiliser ce sous-programme, il est donné à titre
 * indicatif, mais peut vous être utile dans le cadre de tests. */
void p4jouer(p4plateau & p, std::size_t col, p4jeton j);

/**	Chacun de vos binômes a un numéro (attribué dans l'ordre alphabétique) :
 * 1 : Ammad
 * 2 : Abed Bouker
 * 3 : Abouakil Belhantri
 * 4 : Bankouezi Barry
 * Ce numéro est noté NB (numéro binôme) dans la suite de cette explication.
 * Dans un fichier qui s'appelle p4ia_NB.cc, vous déclarerez un sous-programme
 * appelé p4ia_NB qui aura cette signature :
std::size_t p4ia_NB(p4plateau plateau, p4jeton jia, std::size_t nbtours);
 * La paramètre plateau est bien évidemment l'état du plateau de jeu actuel.
 * Le parametre jia est le jeton utilisé par l'IA.
 * Le paramètre est le nombre de tours déjà joués (en d'autres termes, c'est le
 * nombre de jetons qu'il y a déjà dans le plateau, ça peut vous éviter de le
 * recalculer si vous en avez besoin).
 * La valeur à retourner est un entier compris entre 0 et p4largeur-1
 * représentant la colonne dans laquelle l'IA veut jouer. Attention, si vous
 * retournez une colonne invalide (>=p4largeur ou colonne pleine), la partie se
 * termine immédiatement et votre IA écope d'une pénalité.
 * Ne changez rien au code que vous avez écrit : gardez votre main, gardez vos * types de données et vos sous-programmes. Il vous suffit d'écrire un code
 * pour le sous-programme p4ia_NB qui "convertit" un p4plateau en la structure
 * de données que vous utilisez pour représenter le plateau, d'appeler votre
 * sous-programme qui calcule le jeu de l'IA et faire en sorte que p4ia_NB
 * retourne la colonne déterminée par votre sous-programme de jeu IA.
 * Le programme organisant le tournoi (que vous n'avez pas à écrire) appellera
 * à tour de rôle les sous-programmes p4ia_NB pour faire s'affronter deux IA.
 */

void p4charger(p4plateau & p, std::string nomfichier);
