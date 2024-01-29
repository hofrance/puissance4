
#include "declaration.h"
#include "verification.h"

// on véifie si une étiquette n'a pas déjà été saisie
bool verif_presence_etiquette(table_jeu t, char x, int rang_joueur)
{
    if (rang_joueur == 0) // si c'est le premier du rang
        return true;
    else
    {
        bool aux = true;
        for (int i = 0; i < rang_joueur; ++i)
        {
            if (t.table_joueur[i].val == x)
                aux = false;
        }
        return aux;
    }
}

// on vérifie si un nom n'a pas déjà été saisie
bool verif_presence_nom(table_jeu t, std::string x, int rang_joueur)
{
    if (rang_joueur == 0) // si c'est le premier du rang
        return true;
    else
    {
        bool aux = true;
        for (int i = 0; i < rang_joueur; ++i)
        {
            if (t.table_joueur[i].nom_joueur == x)
                aux = false;
        }

        return aux;
    }
}

// on vérifie si une colonne est remplie
bool est_remplie(matrice m, int num_colonne)
{
    if (m[0][num_colonne] != ' ')
        return true;
    else
        return false;
}

// on verifie si une case est valide ou existante
bool point_existe(matrice m, int num_colonne, int num_ligne)
{
    if (num_colonne >= nbColonne or num_colonne < 0 or num_ligne >= nbLigne or num_ligne < 0)
        return false;
    else
        return true;
}

// fonction qui vérifie si il rest des cases vides
bool reste_case_vide(table_jeu jeu)
{

    int aux = 0;
    for (int i = 0; i < nbLigne; ++i)
        for (int j = 0; j <= nbLigne; ++j)
        {
            if (jeu.la_matrice[i][j] == ' ')
                aux++;
        }
    // on vérifie si on a toujours une case libre
    if (aux > 0)
        return true;

    else
        return false;
}

// le nombres d'occurences générale
int nb_occurence_direction(matrice m, int num_colonne, int num_ligne, int x_ligne, int y_colonne)
{
    if (point_existe(m, num_colonne + y_colonne, num_ligne + x_ligne) == false)
        return 0;
    else
    {
        if (m[num_ligne + x_ligne][num_colonne + y_colonne] == m[num_ligne][num_colonne])
            return (1 + nb_occurence_direction(m, num_colonne + y_colonne, num_ligne + x_ligne, x_ligne, y_colonne));
        else
            return 0;
    }
}

// le nombres d'occurences mligne
int les_occurences_ligne(matrice m, int num_colonne, int num_ligne)
{
    int oX = nb_occurence_direction(m, num_colonne, num_ligne, 0, 1);
    int ox = nb_occurence_direction(m, num_colonne, num_ligne, 0, -1);
    return (oX + ox);
}

// Nombre dd'occurences sur la colonne
int les_occurences_colonne(matrice m, int num_colonne, int num_ligne)
{
    int oy = nb_occurence_direction(m, num_colonne, num_ligne, 1, 0);
    int oY = nb_occurence_direction(m, num_colonne, num_ligne, -1, 0);

    return (oY + oy);
}

// Nombre d'occurences sur la premiere diagonale
int les_occurences_premiere_diag(matrice m, int num_colonne, int num_ligne)
{
    int oy = nb_occurence_direction(m, num_colonne, num_ligne, -1, -1);
    int oY = nb_occurence_direction(m, num_colonne, num_ligne, 1, 1);

    return (oY + oy);
}

// Nombre d'occurences sur la seconde diagonale
int les_occurences_seconde_diag(matrice m, int num_colonne, int num_ligne)
{
    int oy = nb_occurence_direction(m, num_colonne, num_ligne, 1, -1);
    int oY = nb_occurence_direction(m, num_colonne, num_ligne, -1, 1);

    return (oY + oy);
}

// detection de la victoire
bool victoire(matrice m, int num_colonne, int num_ligne)
{
    int aux1, aux2, aux3, aux4;

    aux1 = les_occurences_colonne(m, num_colonne, num_ligne);
    aux2 = les_occurences_ligne(m, num_colonne, num_ligne);
    aux3 = les_occurences_seconde_diag(m, num_colonne, num_ligne);
    aux4 = les_occurences_premiere_diag(m, num_colonne, num_ligne);

    if ((aux1 >= 3) or (aux2 >= 3) or (aux3 >= 3) or (aux4 >= 3))
        return true;
    else
        return false;
}

// procédure qui permet de resaisir une colonne si elle est pas valide

void colonne_valide(table_jeu jeu, joueur j, int numCol)
{
    if (est_remplie(jeu.la_matrice, numCol) == true)
    {
        do
        {
            std::cout << j.nom_joueur << " la colonne est pleine choisissez une nouvelle ! ";
            std::cin >> numCol;

        } while (est_remplie(jeu.la_matrice, numCol) == true);
        colonne_valide(jeu,j,numCol);
    }

    else if (numCol >= nbColonne or numCol < 0)
    {
        do
        {
            std::cout << j.nom_joueur << " la colonne est invalide,choisissez une autre colonne ! ";
            std::cin >> numCol;

        } while (numCol >= nbColonne or numCol < 0);
         colonne_valide(jeu,j,numCol);
    }
    // saisie d'une colonne invalide
  
}
