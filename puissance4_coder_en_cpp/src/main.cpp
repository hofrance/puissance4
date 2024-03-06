#include "jeu.h"
#include"ia.h"
#include"verification.h"
#include<iostream>
#include<string>



int main()
{

 


  bool oui;
  std::string choix;

//par défaut le nombre de joueur est de deux;
 table_jeu notreMatrice;
 init_table_de_jeu(notreMatrice,2);

 
 partie_humain_ia(notreMatrice,2);
    do{
            std::cout<<" Souhaitez vous refaire une nouvelle manche(oui/non)";
            std::cin>>choix;
            if(choix=="oui" )
                
                {
                    init_matrice(notreMatrice.la_matrice);
                    partie_humain_ia(notreMatrice,2);
                     oui=true;

                 }

              else
                oui=false;


    }while (oui==true);

   
 return 0;
}


