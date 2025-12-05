//HEADER DU PROJET ALGO-PROG EI25 ---- PAUL CHIRON - GABRIEL CHATELAIN
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>



// CREATION ET CALCULS DE POLYNOMES //

typedef struct Polynome{
    int degre;
    float* liste;
}Polynome;

Polynome creer_polynome(); 
//Crée un polynome par saisie dans le terminal.

float evaluation_polynome(Polynome P, float antecedant);
//Evalue le polynome en une valeur donnée par le paramètre "antécédant".

bool P_nul_test(Polynome P);
//Renvoie 1 si le polynome est nul, 0 sinon.

Polynome addition(Polynome P1, Polynome P2); 
//Addition des polynomes P1 et P2.

Polynome produit(Polynome P1, Polynome P2);
//Produit des polynomes P1 et P2.

Polynome puissance_polynomiale(Polynome P, int puissance);
//Calcule un polynome élevé à une puissance entrée en paramètre.

Polynome derivee(Polynome P); 
//Crée la dérivée du polynome passé en argument.

Polynome derivee_nieme(Polynome P, int n);
////Crée la dérivée n-ième du polynome passé en argument.

float intergration(float d, float f, Polynome P);
//Intègre le polynome P sur [d, f].

Polynome DL_enA_ordreN(Polynome P, float a, int n);
//Calcule le DL à l'ordre n au point a du polynome P.


// OPERATEUR MATHEMATIQUES NON-POLYNOMIAUX //

int maxm(int a, int b); 
//Renvoie l'entier max entre a et b.

int minm(int a, int b);
//Renvoie l'entier max entre a et b.

float puissance_n(float puissance, int exposant);
//Calcul de puissance à l'exposant n.

int factorielle(int n);
//Calcule n! = n*(n-1)*(n-2)*...*2*1.



// IMPRESSION DANS LE LOG //

void impression_polynome(FILE* fichier, Polynome P);
//Print un polynome sous la forme aX^2 + bX + c (par exemple). Sert à alléger le code dans les fonctions qui suivent.

void archivage_creation(Polynome P);
//Print une phrase de la forme CREATION : [polynome] dans le log

void archivage_addition(Polynome P1, Polynome P2, Polynome P_res);
//Print une phrase de la forme ADDITION : [polynome1] + [polynome2] = [polynome résultat] dans le log

void archivage_produit(Polynome P1, Polynome P2, Polynome P_res);
//Print une phrase de la forme ADDITION : [polynome1] x [polynome2] = [polynome résultat] dans le log

void archivage_derivation(Polynome P, Polynome P_deriv);
//Print une phrase de la forme DERIVATION de [polynome] : P' = [polynome dérivé] dans le log

void archivage_integrale(Polynome P, float d, float f, float integrale);
//Print une phrase de la forme INTEGRATION : intégrale sur [d, f] de [polynome] = [intégrale] dans le log

void reset_log();
//Efface tous les archivages de l'historique.



// AFFICHAGE DANS LE TERMINAL //

void afficher_coeff(Polynome P, int indice); 
//Affiche un coeff dans le polynome. N'affiche pas les coefficient nuls, ni les coéfficients unitaires

void afficher_polynome(Polynome P); 
//Utilise afficher_coeff pour afficher tout le polynome.




