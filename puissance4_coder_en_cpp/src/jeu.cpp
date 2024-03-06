#include "declaration.h"
#include "verification.h"
#include <iostream>
#include <array>
#include <string>

// Fonction qui affiche le plateau de jeu
void affiche_plateau(const table_jeu& jeu) {
    for(int j = 1; j <= nbColonne; j++) {
        std::cout << "   " << j;
    }
    std::cout << "\n";
    for(int i = 0; i < nbLigne; i++) {
        for(int j = 0; j < nbColonne; j++) {
            std::cout << " | " << jeu.la_matrice[i][j];
        }
        std::cout << " |\n";           
    }
}

// Initialisation d'une matrice
void init_matrice(matrice &m) {
    for(int i = 0; i < nbLigne; i++)
        for(int j = 0; j < nbColonne; j++)
            m[i][j] = ' ';
}

// Valider et saisir le nom du joueur
std::string saisir_nom_joueur(const table_jeu& k, int joueurActuel) {
    std::string nom;
    bool nomValide;
    do {
        std::cout << "Nom du Joueur N°" << joueurActuel + 1 << ": ";
        std::cin >> nom;
        nomValide = !verif_presence_nom(k, nom, joueurActuel);
        if (!nomValide) {
            std::cout << "Nom déjà présent. Veuillez saisir un nom différent.\n";
        }
    } while (!nomValide);
    return nom;
}

// Valider et saisir l'étiquette du joueur
char saisir_etiquette_joueur(const table_jeu& k, int joueurActuel) {
    char etiquette;
    bool etiquetteValide;
    do {
        std::cout << "Étiquette pour le Joueur N°" << joueurActuel + 1 << " (un caractère) : ";
        std::cin >> etiquette;
        etiquetteValide = !verif_presence_etiquette(k, etiquette, joueurActuel);
        if (!etiquetteValide) {
            std::cout << "Étiquette déjà prise. Veuillez en choisir une autre.\n";
        }
    } while (!etiquetteValide);
    return etiquette;
}

void init_table_de_jeu(table_jeu &k, int nb_joueur) {
    k.table_joueur = new joueur[nb_joueur];

    for (int i = 0; i < nb_joueur; ++i) {
        std::string nom = saisir_nom_joueur(k, i);
        char etiquette = saisir_etiquette_joueur(k, i);
        
        k.table_joueur[i].nom_joueur = nom;
        k.table_joueur[i].val = etiquette;
    }
    init_matrice(k.la_matrice);
}

// D'autres fonctions comme mettre_en_bas, position_case, fin_partie, partie_humain_contre_humain peuvent également être optimisées suivant une logique similaire.
