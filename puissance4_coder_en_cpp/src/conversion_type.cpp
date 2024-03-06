#include "puissance4api.hh"
#include"ia.h"



//on identifie le caractere de l'autre joueur;
char le_charactere_de_l_autre_joueur(p4plateau p,char le_char_connu)
{
    for (std::size_t l=0; l<p4hauteur; ++l)
		for (std::size_t c=0; c<p4largeur; ++c)
            {
                if(p[c][l]!=' ' and p[c][l]!=le_char_connu)
                    return p[c][l];
            }

    return 'x';
}




void copie_plateau(p4plateau a_copier, matrice& copie)
{
    for (std::size_t l=0; l<p4hauteur; ++l)
		for (std::size_t c=0; c<p4largeur; ++c)
            {
                //on convertie les valeurs
                int ligne=static_cast<int>(l);
                int colonne=static_cast<int>(c);
                
                copie[ligne][colonne]=a_copier[c][l];
            }

}