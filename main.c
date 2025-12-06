//MAIN DU PROJET ALGO-PROG EI25 ---- PAUL CHIRON - GABRIEL CHATELAIN
#include "header.h"


int main(){
    /*
    //Affichage du menu  
    printf("Librairie d'opérateurs polynomiaux de Paul CHIRON et Gabriel CHATELAIN\nBienvenu.\n\n");
    Polynome liste_polynomes[NB_MAX];
    int nb_P = nb_polynomes(liste_polynomes);
    int choix = 1;
    while(choix != 0){
        printf("Que voulez-vous faire ?\n");
        printf(" 1 - Créer un polynome ;\n");
        printf(" 2 - Additionner deux polynomes ;\n");
        printf(" 3 - Multiplier deux polynomes ;\n");
        printf(" 4 - Dériver un polynome ;\n");
        printf(" 5 - Dériver n fois un polynome, avec n au choix ;\n");
        printf(" 6 - Intégrer un polynome sur un intervalle ;\n");
        printf(" 7 - Trouver une racine d'un polynome sur un intervalle ;\n");
        printf(" 8 - Calculer le D.L. d'un polynome en un point, à un ordre choisi ;\n");
        printf(" 9 - Effacer l'historique ;\n");
        printf(" 10 - Effacer la liste des polynomes\n");
        printf(" 0 - Sortir du menu ;\n");

        printf("\nVotre choix : ");
        scanf("%d", &choix);

        switch(choix){
            case 0 :
                printf("A plus tard !\n");
                break;

            case 1 : //Création d'un polynome P
                
                Polynome P = creer_polynome();
                printf("\n");
                printf("Création de P = ");
                afficher_polynome(P);
                archivage_creation(P);
                printf("\n");
                break;

            case 2:
                Polynome P1 = creer_polynome(), P2 = creer_polynome();
                Polynome P1plusP2 = addition(P1, P2);
                printf("P1 + P2 = ");
                afficher_polynome(P1plusP2);
                archivage_addition(P1, P2, P1plusP2);
                free(P1.liste);
                free(P2.liste);
                printf("\n");
                break;
            
            case 3:
                Polynome P3 = creer_polynome(), P4 = creer_polynome();
                Polynome P3foisP4 = produit(P3, P4);
                printf("P3 * P4 = ");
                afficher_polynome(P3foisP4);
                archivage_produit(P3, P4, P3foisP4);
                free(P3.liste);
                free(P4.liste);
                printf("\n");
                break;

            case 4: //Dérivation d'un polynome P
                Polynome P5 = creer_polynome();
                Polynome P5_prime = derivee(P5);
                printf("derivée de P5 = ");
                afficher_polynome(P5_prime);
                free(P5.liste);
                free(P5_prime.liste);
                printf("\n");
                break;
            
            case 6:
                Polynome P7 = creer_polynome();
                float d, f; //début et fin de l'intervalle d'intégration
                printf("Bornes de l'intervalle d'intégration [d, f]:\n");
                printf("d = ");
                scanf("%f", &d);
                printf("f = ");
                scanf("%f", &f);
                float integrale = intergration(d, f, P7);
                printf("Intégrale de P1 sur [%f, %f] = %f\n", d, f, integrale);
                archivage_integrale(P7, d, f, integrale);
                free(P7.liste);
                printf("\n");
                break;

            case 7:
                Polynome P8 = creer_polynome();
                float a;
                int n;
                printf("Point de DL : a = ");
                scanf("%f", &a);
                printf("Ordre du DL n = ");
                scanf("%d", &n);
                Polynome DL = DL_enA_ordreN(P8, a, n);
                printf("DL de P1 au point %f à l'ordre %d : ", a, n);
                afficher_polynome(DL);
                archivage_DL(P8, DL, a, n);
                free(P8.liste);
                free(DL.liste);
                printf("\n");
                break;

            case 8:
                Polynome P9 = creer_polynome();
                float D, F, precision;
                printf("Bornes de l'intervalle [d, f]:\n");
                printf("d = ");
                scanf("%f", &D);
                printf("f = ");
                scanf("%f", &F);
                printf("Précision : p = ");
                scanf("%f", &precision);

                float racine = Racine_P(P9, D, F, precision);
                if(racine >= D){
                    printf("racine de P1 sur [%f, %f] : %f\n", D, F, racine);
                    printf("P(%f) = %f\n", racine, evaluation_polynome(P9, racine));
                }
                else printf("Le polynome n'a pas de racine réelle sur [%f, %f].\n", D, F);
                free(P9.liste);
                printf("\n");
                break;
            
            case 9:
                reset_log();
                printf("Historique effacé.\n");
                printf("\n");
                break;
            
            default :
                printf("Ce choix n'est pas dans la liste\n");
                break;
        }
    }
    /*
    Polynome P;
    P.degre = 7;
    P.liste = (float*)malloc(P.degre*sizeof(float));
    P.liste[0] = 7.5;
    P.liste[1] = 5.5;
    P.liste[2] = 0; 
    P.liste[3] = 66.13;
    P.liste[4] = 0;
    P.liste[5] = 0;
    P.liste[6] = 0;
    P.liste[7] = -45;
    printf("%f\n", intergration(-7, 2.3, P));
    */
    
    return 0;
}
