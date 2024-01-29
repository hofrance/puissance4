#include"strategie.h"
#include "verification.h"
#include <random>
#include <cstdlib>
#include<ctime>


//c'est le coefficient de choix que l'on va multiplier  a chaque element afin de déterminer son importance
const int coef_choix=1000;

void affiche_t(table t)
{
    for (int i = 0; i < nbColonne; ++i)
        std::cout << t[i] << "|";
}


// on ecrit une fonction qui retoure la case contenant le plus d'occurences
int indice_avec_le_plus_d_occurences(table t)
{
    int le_plus_grand_indice;;
    int val = t[0];
    for (int i = 0; i < nbColonne; ++i)
    {
        if (t[i] >= val)
        {
            val = t[i];
            le_plus_grand_indice = i;
        }
    }

    return le_plus_grand_indice;
}





//on fait le choix d'une colonne
int decision(matrice &m, joueur ordi, joueur autre_j, table &t, int nb_coup)
{
   
    int resultat = 0;
    init_table(t);

    colonne_gagnante(m, ordi, autre_j, t, nb_coup);
    resultat = indice_avec_le_plus_d_occurences(t);
    if(est_remplie(m,resultat)==true)
        {
            for(int i=0;i<nbLigne;++i)
                {
                    for(int j=0;j<nbColonne;++j)
                        {
                            if(m[i][j]==' ')
                                return j;
                        }
                }
        }
    return resultat;
    
}

void partie_humain_ia(table_jeu &jeu, int nb_joueur)
{
    
    int numCol;
    bool arret = false;
    std::string result = "personne";
    table notre_table;

    int nb_coup = 0;

    do
    {
        int i = 0; // cette declaration permet de déclarer un nouveau tour de jeu (rejouer tout le monde)
        do
        {
            init_table(notre_table); // on initialise notre tableau
            std::string nom = jeu.table_joueur[i].nom_joueur;

            if (nom == "ia" or nom == "Ia" or nom == "iA" or nom == "IA")
            { //

                if (i == 0)
                    {

                        colonne_gagnante(jeu.la_matrice, jeu.table_joueur[i], jeu.table_joueur[i + 1],notre_table,nb_coup);

                        std::cout << "La table de déciqion de l'I.A " << std::endl;
                        affiche_t(notre_table);
                
                        numCol = decision(jeu.la_matrice, jeu.table_joueur[i], jeu.table_joueur[i + 1], notre_table, nb_coup);
                        std::cout << " l'ia a joué dans la colonne:" << numCol + 1 << std::endl;

                    }

                else
                    {
                    
                        colonne_gagnante(jeu.la_matrice, jeu.table_joueur[i], jeu.table_joueur[i - 1], notre_table, nb_coup);

                        std::cout << "La table de choix de l'I.A  " << std::endl;
                        affiche_t(notre_table);

                        numCol = decision(jeu.la_matrice, jeu.table_joueur[i], jeu.table_joueur[i - 1], notre_table, nb_coup);
                        std::cout << " l'ia a joué dans la colonne:" << numCol + 1 << std::endl;

                        
                    
                    }
            }

            else
                {
                    std::cout << jeu.table_joueur[i].nom_joueur << " dans quelle colonne souhaitez vous jouer ? ";
                    std::cin >> numCol;
                    numCol = numCol - 1;
                    // on contrôle la validité
                    colonne_valide(jeu, jeu.table_joueur[i], numCol);
                }

            mettre_en_bas(jeu.table_joueur[i], jeu.la_matrice, (numCol));

            std::cout << "================================" << std::endl;

            // affichage de l'avancement
            std::cout << " Etat d'avancement: " << std::endl;
            affiche_plateau(jeu);

            // on verifie si le joueur a gagner ou pas
            int pos = position_case(jeu.la_matrice, numCol, jeu.table_joueur[i].val);

            if ((victoire(jeu.la_matrice, numCol, pos)) == true)
                {
                    result = jeu.table_joueur[i].nom_joueur;
                
                    arret = true;
                }
                
            else
                {

                    std::cout << "================================" << std::endl;
                    std::cout << " la partie continue ! " << std::endl;
                    ++i;
                }

            ++nb_coup;                              // on augmente le coup afin d'évaluer si on est au début ou en fin

        } while (arret == false and i < nb_joueur); // on sort  de cette boucle lorsque tous les joueurs ont joué ou que un joueur a gagner

    } while (arret == false and reste_case_vide(jeu)); // si jamais toutes les ccolonne sont pleine :on sortira de la boucle ou s'il y'a un vainqueur

    // le resultat à la sortie de la boucle

    if (result == "personne")
        std::cout << " dommage il n'y a pas de vainqueur" << std::endl;
    else if (result == "ia" or result == "Ia" or result == "IA" or result == "iA" or result == "ia" or result == "ia")
        std::cout << "L'algorithme vous a battu !"<<std::endl;
    else
        std::cout << "Felicitation " << result << " vous êtes le vainqueur" << std::endl;
}
