
#include"declaration.h"
#include"verification.h"
#include<iostream>
#include<array>
#include<string>



//fonction qui affiche le plateau de jeu

void affiche_plateau(table_jeu jeu)
{
    for(int j=1;j<=nbColonne;j++)
    {
        std::cout<<"   "<<j;
    }
    std::cout<<" "<<std::endl;
    for(int i=0;i<nbLigne;++i)
        {
            
            for(int j=0;j<nbColonne;j++)
            {
                
                std::cout<<" | "<<jeu.la_matrice[i][j];
            }

            std::cout<<"|"<<std::endl;           
        }
}


//initialisation d'une matrice
void init_matrice(matrice &m)
{
    for(int i=0;i<nbLigne;++i )
        for(int j=0;j<nbColonne;++j)
            {
                m[i][j]=' ';
            }
}



void init_table_de_jeu(table_jeu &k, int nb_joueur)
{

    //on déclare un tableau dynamique de joueur
    k.table_joueur=new joueur[nb_joueur];

    //on déclare un tableau dynamique  qui contiendra les étiquettes des joueurs
    

    //variables auxiliaires
    std::string nom; 
    char etiquette;

    for (int i=0;i<nb_joueur;++i )
        {
            std::cout<<" Nom du Joueur N°"<<i+1<<" ";
            std::cin>>nom;
            //on vérifie la validité de la saisie
            if( verif_presence_nom(k,nom,i)==false)
            {
                do{
                    std::cout<<"Vous avez rentrez un nom déjà présent ! Refaite la saisie ";
                     std::cin>>nom;
                }while(verif_presence_nom(k,nom,i)==false);
            }

            else if(nom=="ia" or nom=="Ia" or nom=="iA" or nom=="IA")
                {
                    
                    std::string choix="non";
                    do
                    {
                        std::cout<<"Souhaitez-vous faire jouer une intelligence artificielle(oui/non)";
                        std::cin>>choix;
                    } while (choix=="non");
                    
                }

            std::cout<<" Son étiquette(char): ";
            std::cin>>etiquette;

            //on vérifie la validité de la saisie
            if( verif_presence_etiquette(k,etiquette,i)==false)
            {
                do{
                    std::cout<<"Vous avez rentrez une étiquette déjà présente ! Refaite la saisie ";
                     std::cin>>etiquette;
                }while(verif_presence_etiquette(k,etiquette,i)==false);
            }           

            k.table_joueur[i].nom_joueur=nom;
            k.table_joueur[i].val=etiquette;

           

     }

     //initialisation de la table de jeu
     init_matrice(k.la_matrice);

}





    



//procedure permettant de mettre un pions dans une colonne
void mettre_en_bas(joueur j, matrice &m, int numCol) 
{
        bool aux=true;
        int i=nbLigne-1;

        while(aux==true and i>=0)//#### l'erreur etait au niveau du signe ! 
        {
            //ON VERIFIE la dernière case de la colonne
            if(m[i][numCol]==' ')
                {
                    //on fait l'echange et on sort de la boucle
                    m[i][numCol]=j.val;
                    aux=false;
                }
            //si la derniere case n'est pas un ' ' on decremente et on regardera l'avant dernière
            --i;
        }
    
}



int position_case(matrice jeu, int num_colonne, char x)
{
    int i=0;
    bool aux=true;
    do
        {
            if(jeu[i][num_colonne]==x)
                aux=false;
            else
                ++i;

        } while ((aux==true) and (i<nbLigne));
    
    return i;

}


void fin_partie(table_jeu & jeu)
{
    delete jeu.table_joueur;
}

void partie_humain_contre_humain(table_jeu & jeu,int nb_joueur)
{

    int numCol;
    bool arret=false;   
    std::string result="personne";

    do{
        int i=0;//cette declaration permet de déclarer un nouveau tour de jeu (rejouer tout le monde)
        do{

            std::cout << jeu.table_joueur[i].nom_joueur << " dans quelle colonne souhaitez vous jouer ? ";
            std::cin >> numCol;

            //ici on vérifie la validité de la colonne donner si elle est pleine ou pas
            if (est_remplie(jeu.la_matrice, numCol-1) == true)
            {
                do
                {
                    std::cout << jeu.table_joueur[i].nom_joueur << " la colonne est pleine choisissez une nouvelle ! ";
                    std::cin >> numCol;
                    
                                    
                } while (est_remplie(jeu.la_matrice, numCol-1) == true);
            }

            else if(numCol>nbColonne or numCol<=0)
                            {
                             do
                                {
                                    std::cout << jeu.table_joueur[i].nom_joueur << " la colonne est invalide,choisissez une autre colonne ! ";
                                    std::cin >> numCol;
                                    
                                } while (numCol>nbColonne or numCol<=0); 
                            }


            //saisie d'une colonne invalide
         if(numCol>nbColonne or numCol<=0)
            {
             do
                {
                    std::cout << jeu.table_joueur[i].nom_joueur << " la colonne est invalide,choisissez une autre colonne ! ";
                    std::cin >> numCol;
                    
                } while (numCol>nbColonne or numCol<=0);   
            }

            mettre_en_bas(jeu.table_joueur[i], jeu.la_matrice,( numCol-1));
             std::cout << " Etat d'avancement: " << std::endl;
            
            
                        

            //affichage de l'avancement
            std::cout<<"================================"<<std::endl;
            affiche_plateau(jeu);

           
            


            //on verifie si le joueur a gagner ou pas
            int pos = position_case(jeu.la_matrice, numCol-1, jeu.table_joueur[i].val);

            if ((victoire(jeu.la_matrice, numCol-1, pos)) == true)
                {
                    result = jeu.table_joueur[i].nom_joueur;
                            // return result;
                    arret = true;
                }
            else
                {
               
                std::cout<<"================================"<<std::endl;
                std::cout << " la partie continue ! "<<std::endl;
                    ++i;
                }

         } while(arret == false and i<nb_joueur);//on sort  de cette boucle lorsque tous les joueurs ont joué ou que un joueur a gagner

    }while(arret==false and reste_case_vide(jeu));//si jamais toutes les ccolonne sont pleine :on sortira de la boucle ou s'il y'a un vainqueur
           
//le resultat à la sortie de la boucle


if(result=="personne")
    std::cout<<" dommage il n'y a pas de vainqueur"<<std::endl;
else
    std::cout<<"Felicitation "<<result<<" vous êtes le vainqueur"<<std::endl;
    

}



