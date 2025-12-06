//MAIN DU PROJET ALGO-PROG EI25 ---- PAUL CHIRON - GABRIEL CHATELAIN
#include "header.h"


int main(){

    //création et affichage de deux polynomes P1 et P2
    Polynome P1 = creer_polynome();
    printf("\n");
    printf("P1 = ");
    afficher_polynome(P1);
    /*
    Polynome P2 = creer_polynome();
    printf("P2 = ");
    afficher_polynome(P2);
    
    //création et affichage de la dérivée de P1
    Polynome P1_prime = derivee(P1);
    printf("derivée de P1 = ");
    afficher_polynome(P1_prime);
    printf("\n");
    
    //addition P1 + P2
    Polynome P1plusP2 = addition(P1, P2);
    printf("P1 + P2 = ");
    afficher_polynome(P1plusP2);
    printf("\n");

    //produit P1*P2
    Polynome P1foisP2 = produit(P1, P2);
    printf("P1 * P2 = ");
    afficher_polynome(P1foisP2);
    printf("\n");

    //integration de P1 sur [1, 2]
    float d, f; //début et fin de l'intervalle d'intégration
    printf("Bornes de l'intervalle d'intégration [d, f]:\n");
    printf("d = ");
    scanf("%f", &d);
    printf("f = ");
    scanf("%f", &f);
    printf("l x'intégrale de P1 sur [%f, %f] est %f\n", d, f, intergration(d, f, P1));
    
     //création et affichage de la dérivée_nième de P1
    Polynome DL = DL_enA_ordreN(P1, 2, 3);
    printf("DL de P1 au point 2 à l'ordre 3 : ");
    afficher_polynome(DL);
    */
    //calcul d'une racine d'un polynome sur [a, b];
    float racine = Racine_P(P1, -4, 4, 0.001);
    if(racine >= -4){
        printf("racine de P1 sur [-4, 4] : %f\n", racine);
        printf("P(%f) = %f\n", racine, evaluation_polynome(P1, racine));
    }

    /*
    //libération des listes de coéfficients de tous les polynomes créés et nettoyage de l'historique 
    free(P1.liste);
    free(P2.liste);
    free(P1_prime.liste);
    free(P1plusP2.liste);
    free(P1foisP2.liste);
    free(DL.liste);
    */    
    //reset_log();
    return 0;
}
