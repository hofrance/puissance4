
#include "verification.h"
#include <random>
#include <cstdlib>
#include<ctime>


const int coef_choix=1000;


void init_table(table &t)
{
    for (int i = 0; i < nbColonne; ++i)
        t[i] = 0;
}

void copie_matrice(matrice a_copier, matrice &copie)
{
    for (int i = 0; i < nbLigne; ++i)
    {
        for (int j = 0; j < nbColonne; ++j)
            copie[i][j] = a_copier[i][j];
    }
}




/*
    Les coups avantageux sont des cas exceptionels où l'on peut avoir des victoires
    
    ici le le 'o' represente un ezspace vide c'est a  dire que l'on  peut mettre un jeton biensûr si c'est possible

     coup_avantageux0 ----> si on a OOOXO       alors on joue OXOXO
     coup_avantageux1 ----> si on a OXOXO       alors on joue OXXXO
     coup_avantageux2 ---->  si on a OOXXO      alors on joue OXXXO
     
*/
int coup_avantageux0(matrice m,char x)
{
     for(int i=0;i<nbLigne;++i)
    {
        for(int j=0;j<nbColonne;++j)
            {
                if(m[i][j]==x)
                    {
                        //premier cas on veux former un x une case vide un x et une case vide
                        if(point_existe(m,j-3,i)==true and point_existe(m,j-2,i)==true and point_existe(m,j-1,i)==true and point_existe(m,j+1,i)==true)
                            {
                                if(m[i][j-3]==' ' and m[i][j-2]==' '  and m[i][j-1]==' ' and m[i][j+1]==' '  )
                                    {
                                        if(i==nbLigne-1)
                                            return(j-2)  ;
                                        else
                                            {
                                                //on vérifie on peut jouer ses cases
                                                if(m[i+1][j-3]!=' ' and m[i+1][j-2]!=' '  and m[i+1][j-1]!=' ' and m[i+1][j+1]!=' '  )
                                                    return(j-2)  ;

                                            } 
                                    }
                            }
                        else if(point_existe(m,j+3,i)==true and point_existe(m,j+2,i)==true and point_existe(m,j+1,i)==true and point_existe(m,j-1,i)==true)
                            {
                                if(m[i][j+3]==' ' and m[i][j+2]==' '  and m[i][j+1]==' ' and m[i][j-1]==' '  )
                                    {
                                        if(i==nbLigne-1)
                                            return(j+2)  ;
                                        else
                                            {
                                                //on vérifie on peut jouer ses cases
                                                if(m[i+1][j+3]!=' ' and m[i+1][j+2]!=' '  and m[i+1][j+1]!=' ' and m[i+1][j-1]!=' '  )
                                                    return(j+2)  ;

                                            } 
                                    }
                            }
                    }
            }
    }

    return -1;
}

//1
int coup_avantageux1(matrice m,char x)
{
    for(int i=0;i<nbLigne;++i)
    {
        for(int j=0;j<nbColonne;++j)
            {
                if(m[i][j]==x)
                    {
                        //on verifie si les points existent bien
                        if(point_existe(m,j-1,i)==true and point_existe(m,j+1,i)==true and point_existe(m,j+2,i)==true and point_existe(m,j+3,i))
                            {
                                if(m[i][j-1]==' ' and m[i][j+1]==' ' and m[i][j+2]==x  and m[i][j+3]==' ')
                                {

                                    //on verifie si on est pas en bas du plateau
                                    if(i==nbLigne-1)
                                        return (j+1);
                                    else
                                        {
                                            if(point_existe(m,j-1,i)==true and point_existe(m,j+1,i)==true and point_existe(m,j+2,i)==true)
                                                {
                                                    if(m[i+1][j-1]!=' ' and m[i+1][j+1]!=' ' and m[i+1][j+2]!=' ' and m[i][j+3]!=' ')
                                                    //on regarde si o peut former une diagonale avantageuse
                                                    {
                                                            return (j+1);// return (j-1);
                                                    }
                                                         
                                                }
                                        }
                                }
                            }
                    }
            }
    }

    return -1;//si on trouve pas de cout avantageux;

}



int coup_avantageux2(matrice m,char x)
{
    for(int i=0;i<nbLigne;++i)
    {
        for(int j=0;j<nbColonne;++j)
            {
                if(point_existe(m,j+1,i)==true and m[i][j+1]==x)
                    {
                         //if((point_existe(m,j+1,i)==true and m[i][j+1]==' ') and (point_existe(m,j-1,i)==true and m[i][j-1]==' ')and (point_existe(m,j-2,i)==true and m[i][j-2]==' ') )
                        if((point_existe(m,j-1,i) and m[i][j-1]==' ') and (point_existe(m,j-2,i) and m[i][j-2]==' ')and (point_existe(m,j+2,i) and m[i][j+2]==' ') )
                                {
                                    if(i==nbLigne-1)
                                        return (j-1);
                                    else
                                        {
                                           if((point_existe(m,j-1,i+1)==true and m[i+1][j-1]!=' ') and (point_existe(m,j+2,i+1)==true and m[i+1][j+2]!=' ')and (point_existe(m,j-2,i+1)==true and m[i+1][j-2]!=' ') ) 
                                                return(j-1);
                                        }
                           
                                }


                        else if ((point_existe(m,j-1,i) and m[i][j-1]==' ') and (point_existe(m,j+2,i) and m[i][j+2]==' ')and (point_existe(m,j+3,i) and m[i][j+3]==' ') )
                            {
                                    if(i==nbLigne-1)
                                        return (j+2);
                                    else
                                        {
                                           if((point_existe(m,j-1,i+1) and m[i+1][j-1]==' ') and (point_existe(m,j+2,i+1) and m[i+1][j+2]==' ')and (point_existe(m,j+3,i+1) and m[i+1][j+3]==' ') )
 
                                                return(j+2);
                                        }
                           
                                }
                    

                    }
                    
                    
            }
    }


    return -1;
}





void meilleure_choix(matrice &m, joueur ordi, joueur autre_j, table &t, int nb_coup)

{

    // init_table(t);
    matrice copie;
    // c'est pour conserver une copie de la matrice initiale
    copie_matrice(m, copie);

    for (int aux1 = 0; aux1 < nbColonne; ++aux1)
    {
        // AVANT DE METTRE EN BAs EN VERIFIE SI LA COLONNE EST REMPLIE OU PAS

        if (est_remplie(m, aux1) == false) // on vérifie si la colonne dans laquelle on veut jouer n'est déjà remplie
            {
                // on joue en premier
                mettre_en_bas(ordi, m, aux1);
                int pos = position_case(m, aux1, ordi.val);

                // SI ON GAGNNE
                if (((victoire(m, aux1, pos)) == true))
                    t[aux1]++; // on augmente la valeur de la case aux1

                else
                {

                    for (int aux2 = 0; aux2 < nbColonne; aux2++)
                    {
                        if (est_remplie(m, aux2) == false)

                        {
                            // on fait jouer l'autre
                            mettre_en_bas(autre_j, m, aux2);
                            int pos = position_case(m, aux2, autre_j.val);

                            // on va continuer notre exploration si jamais il est perdant
                            if (((victoire(m, aux2, pos)) == true))
                                t[aux1]--;
                            else
                            {
                                for (int aux3 = 0; aux3 < nbColonne; ++aux3)
                                {
                                    // on vérifie si la colonne n'est pas remplie
                                    if (est_remplie(m, aux3) == false)

                                    {
                                        mettre_en_bas(ordi, m, aux3);
                                        int pos = position_case(m, aux3, ordi.val);
                                        if (((victoire(m, aux3, pos)) == true))
                                            t[aux1]++;

                                        else
                                        {
                                            for (int aux4=0; aux4 < nbColonne; aux4++)
                                            {
                                                if (est_remplie(m, aux4) == false)

                                                {
                                                    mettre_en_bas(autre_j, m, aux4);
                                                    int pos = position_case(m, aux4, autre_j.val);

                                                    if (((victoire(m, aux4, pos)) == true))
                                                        t[aux1]--;
                                                    else
                                                    {
                                                        for (int aux5 = 0; aux5 < nbColonne; ++aux5)
                                                        {
                                                            if (est_remplie(m, aux5) == false)
                                                            {
                                                                mettre_en_bas(ordi, m, aux5);
                                                                int pos = position_case(m, aux5, ordi.val);
                                                                if (((victoire(m, aux5, pos)) == true))
                                                                    t[aux1]++;

                                                                else

                                                                {
                                                                    for (int aux6 = 0; aux6 < nbColonne; ++aux6)
                                                                        if (est_remplie(m, aux6) == false)
                                                                        {

                                                                              mettre_en_bas(autre_j, m, aux6);
                                                                            int pos = position_case(m, aux6, autre_j.val);
                                                                            if (((victoire(m, aux6, pos)) == true))
                                                                                t[aux1]--;
                                                                            else
                                                                            {

                                                                                for (int aux7 = 0; aux7 < nbColonne; ++aux7)
                                                                                {
                                                                                    if (est_remplie(m, aux7) == false)

                                                                                    {
                                                                                        mettre_en_bas(ordi, m, aux7);
                                                                                        int pos = position_case(m, aux7, ordi.val);
                                                                                        if (((victoire(m, aux7, pos)) == true))
                                                                                            t[aux1]++;
                                                                                        else
                                                                                            {
                                                                                                for(int aux8=0;aux8<nbColonne;++aux8)
                                                                                                    if(est_remplie(m,aux8)==false)
                                                                                                        {
                                                                                                            mettre_en_bas(autre_j,m,aux8);
                                                                                                            int pos=position_case(m,aux8,autre_j.val);
                                                                                                            if(victoire(m,aux8,pos))
                                                                                                                t[aux1]--;
                                                                                                            else
                                                                                                                for(int aux9=0;aux9<nbColonne;++aux9)
                                                                                                                    {
                                                                                                                        if(est_remplie(m,aux9)==false)
                                                                                                                            {
                                                                                                                                mettre_en_bas(ordi, m, aux9);
                                                                                                                                int pos = position_case(m, aux9, ordi.val);
                                                                                                                                if (((victoire(m, aux9, pos)) == true))
                                                                                                                                    t[aux1]++;
                                                                                                                                else
                                                                                                                                    for(int aux10=0;aux10<nbColonne;++aux10)
                                                                                                                                        if(est_remplie(m,aux10)==false)
                                                                                                                                            {               
                                                                                                                                               mettre_en_bas(autre_j,m,aux10);
                                                                                                                                            int pos=position_case(m,aux10,autre_j.val);
                                                                                                                                            if(victoire(m,aux10,pos)==true)
                                                                                                                                                t[aux1]--; 
                                                                                                                                            else
                                                                                                                                                {
                                                                                                                                                    for(int aux11=0;aux11<nbColonne;++aux11)
                                                                                                                                                        {
                                                                                                                                                            if(est_remplie(m,aux11)==false)
                                                                                                                                                            {
                                                                                                                                                                mettre_en_bas(ordi,m,aux11);
                                                                                                                                                                int pos=position_case(m,aux11,ordi.val);
                                                                                                                                                                if(victoire(m,aux11,pos)==true)
                                                                                                                                                                    t[aux11]++;

                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                                                                                
                                                                                                                            }

                                                                                                                    }


                                                                                                        }

                                                                                            }

                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }


               // on remet la matrice initiale
    copie_matrice(copie, m);

    }

 
}


void colonne_gagnante(matrice &m, joueur ordi, joueur autre_j,table & t,int nb_coup)
{
    srand(time(NULL));

   init_table(t);
    matrice cop;
    copie_matrice(m,cop);


    for(int i=0;i<nbColonne;++i)
    {
        mettre_en_bas(ordi,cop,i);
        int pos=position_case(cop,i,ordi.val);


    //On regarde si on gagne
        if(victoire(cop,i,pos)==true)
            {
                t[i]=9*coef_choix;//on attribue à cette colonne une grande  valeur
                cop[pos][i]=' ';
            }
        else
            {
                copie_matrice(m,cop);
                mettre_en_bas(autre_j,cop,i);
                int pos=position_case(cop,i,autre_j.val);

                //on regarde si l'autre gagne quelque part
                if(victoire(cop,i,pos)==true)
                    {
                        t[i]=8*coef_choix;
                        cop[pos][i]=' ';
                    }
            }
    }

   

/* En debut de partie*/



            /* on regarde le coup avantageux0 */

//si on peut faire un coup avantageux
    if(coup_avantageux0(m,ordi.val)!=-1)
        t[coup_avantageux0(m,ordi.val)]=t[coup_avantageux0(m,ordi.val)]+2*coef_choix;
//si c'est l'autre qui peut le faire

    else if(coup_avantageux0(m,autre_j.val)!=-1)
        t[coup_avantageux0(m,autre_j.val)]=t[coup_avantageux0(m,autre_j.val)]+3*coef_choix;//on empêche l'autre de le faire



            /* on regarde le coup avantageux1 */

//si on peut faire un coup avantageux
    if(coup_avantageux1(m,ordi.val)!=-1)
        t[coup_avantageux1(m,ordi.val)]=t[coup_avantageux1(m,ordi.val)]+4*coef_choix;
//si c'est l'autre qui peut le faire


    else if(coup_avantageux1(m,autre_j.val)!=-1)
        t[coup_avantageux1(m,autre_j.val)]=t[coup_avantageux1(m,autre_j.val)]+5*coef_choix;//on empêche l'autre de le faire



            /* on regarde le coup avantageux2 */

 //si on peut faire un coup avantageux
    if(coup_avantageux2(m,ordi.val)!=-1)
        t[coup_avantageux2(m,ordi.val)]=t[coup_avantageux2(m,ordi.val)]+6*coef_choix;
//si c'est l'autre qui peut le faire

    else if(coup_avantageux2(m,autre_j.val)!=-1)
        t[coup_avantageux2(m,autre_j.val)]=t[coup_avantageux2(m,autre_j.val)]+7*coef_choix;//on empêche l'autre de le faire

    
    if(nb_coup<8)
        {
           if(est_remplie(m,3)==false and est_remplie(m,4)==false and est_remplie(m,5)==false  )
                t[rand()%3+2]=+50;
          
        }
       
        

    else
         meilleure_choix(m,ordi,autre_j,t,nb_coup);
    
}
