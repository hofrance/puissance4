#include"p4ia_4.h"
#include"verification.h"
#include"jeu.h"
#include"declaration.h"
#include"ia.h"



std::size_t p4ia_4(p4plateau plateau, p4jeton jia, std::size_t nbtours)
{
    joueur ordi;
        ordi.nom_joueur="jia";
        ordi.val=jia;

    joueur autre_j;
        autre_j.nom_joueur="autre_j";
        autre_j.val=le_charactere_de_l_autre_joueur(plateau,ordi.val);


    table valeur_de_choix_ia;


    //on convertie en int
    int nb_coup = static_cast<int>(nbtours);

    //on copie le plateau actuelle
    matrice la_matrice;
    //on initialise notre matrice
    init_matrice(la_matrice);
    copie_plateau(plateau,la_matrice);


// on convertit en std::size_t avant de retourner notre valeur
    return (static_cast<std::size_t>(decision(la_matrice,ordi,autre_j,valeur_de_choix_ia,nb_coup)));
    
    
}




std::size_t p4ia_10(p4plateau plateau, p4jeton jia, std::size_t nbtours) {
	return rand()%p4largeur;
}
std::size_t p4ia_11(p4plateau plateau, p4jeton jia, std::size_t nbtours) {
	return rand()%p4largeur;
}


