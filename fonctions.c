//FONCTIONS DU PROJET ALGO-PROG EI25 ---- PAUL CHIRON - GABRIEL CHATELAIN
#include "header.h"



// CREATION ET CALCULS DE POLYNOMES //

Polynome creer_polynome(){
    Polynome P;
    printf("\nSaisir le degré : ");
    scanf("%d", &P.degre);
    P.liste = (float*)malloc((P.degre + 1)*sizeof(float));
    if(P.degre == 0){
        printf("Saisir le coéfficient : ");
        scanf("%f", &P.liste[0]);
    }
    else{
        int i;
        printf("\nSaisir le coéfficient du rang associé.\nSi coéfficient nul, saisir 0.\n");
        for(i = 0; i <= P.degre; i++){
            printf("rang %d : ", i);
            scanf("%f", &P.liste[i]);
            //l'exposant correspond à l'indice du coéfficient dans le tableau.
        }
    }
    //archivage_creation(P);
    return P;
}

float evaluation_polynome(Polynome P, float antecedant){
    float result = 0;
    int i;
    for(i = 0; i <= P.degre; i++){
        result += P.liste[i]*puissance_n(antecedant, i);
    }
    return result;
}

bool P_nul_test(Polynome P){
    int est_nul = 1;
    int i;
    if(P.degre == 0 && P.liste[0] == 0)
        est_nul = 0;
    return est_nul;
}

Polynome addition(Polynome P1, Polynome P2){
    Polynome P_result;
    P_result.degre = maxm(P1.degre, P2.degre);
    P_result.liste = (float*)malloc((P_result.degre + 1)*sizeof(float));

    int deg = P_result.degre, deg_min = minm(P1.degre, P2.degre);

    int i;
    for(i = 0; i <= deg_min; i++)
        P_result.liste[i] = P1.liste[i] + P2.liste[i];
    
    if(P1.degre < P2.degre){
        int j;
        for(j = P1.degre + 1; j <= P2.degre; j++)
            P_result.liste[j] = P2.liste[j];
    }
    else if(P1.degre > P2.degre){
        int j;
        for(j = P2.degre + 1; j <= P1.degre; j++)
            P_result.liste[j] = P1.liste[j];
    }

    //archivage_addition(P1, P2, P_result);
    return P_result;
}
 
Polynome produit(Polynome P1, Polynome P2){
    Polynome P_result;
    P_result.degre = P1.degre + P2.degre;
    P_result.liste = (float*)malloc((P_result.degre + 1)*sizeof(float));
    //Initialisation de la liste des coéfficients
    int k;
    for(k = 0; k <= P_result.degre; k++)
        P_result.liste[k] = 0;
    //Remplissage de la liste des coéfficients
    int i;
    for(i = 0; i <= P1.degre; i++){
        int j;
        for(j = 0; j <= P2.degre; j++)
            P_result.liste[j+i] += P1.liste[i]*P2.liste[j]; 
            //Les coéfficients multipliant une même puissance de X s'additionnent sans se remplacer.
    }
    //archivage_produit(P1, P2, P_result);
    return P_result;
}

Polynome puissance_polynomiale(Polynome P, int puissance){
    Polynome P_result = P;
    int i;
    for(i = 1; i < puissance; i++)
        P_result = produit(P_result, P);
    return P_result;
}

Polynome derivee(Polynome P){
    Polynome derv;
    derv.degre = P.degre - 1;
    derv.liste = (float*)malloc((derv.degre + 1)*sizeof(float));
    derv.liste[0] = P.liste[1];
    int i;
    for(i = 1; i <= derv.degre; i++){
        derv.liste[i] = P.liste[i + 1]*(i + 1);
    }
    //archivage_derivation(P, derv);
    return derv;
}

Polynome derivee_nieme(Polynome P, int n){
    Polynome derv_n;
    if(P.degre >= n){
        derv_n = P;
        int i;
        for(i = 0; i < n; i++){
            derv_n = derivee(derv_n);
        }
    }
    else{
        derv_n.degre = 0;
        derv_n.liste = (float*)malloc(sizeof(float));
        derv_n.liste[0] = 0;    
    }
    return derv_n;
}

float intergration(float d, float f, Polynome P){
    float P_d, P_f;
    float integrale;

    int i; 
    for(i = 0; i <= P.degre; i++){
        if(P.liste[i] != 0){
            P_d += (P.liste[i]/((float)i+1))*puissance_n(d, i+1);
            //printf("%f\n", P.liste[i]/((float)i+1)); //Le programme ne renvoie pas le bon résultat jusqu'à l'insertion de cette ligne ???
            P_f += (P.liste[i]/((float)i+1))*puissance_n(f, i+1);
        }
    }
    //printf("%f - %f\n", P_f, P_d);
    integrale = P_f - P_d;
    //archivage_integrale(P, d, f, integrale);
    return P_f - P_d;
}

Polynome DL_enA_ordreN(Polynome P, float a, int n){
    Polynome DL;
    if(n <= P.degre){
        DL.degre = n;
        DL.liste = (float*)malloc((n + 1)*sizeof(float));
        DL.liste[0] = evaluation_polynome(P, a);
        int i;
        for(i = 1; i <= n; i++){
            DL.liste[i] = 0;
        }
        printf("degré du DL : %d\n", DL.degre);
        //Calcul du DL :
        Polynome Facteur; //Polynome de forme (X - a)
        Facteur.degre = 1;
        Facteur.liste = (float*)malloc(2*sizeof(float));
        Facteur.liste[0] = (-1)*a;
        Facteur.liste[1] = 1;
        
        int j;
        for(j = 1; j <= n; j++){ //Création et addition à DL des termes de la formule donnée.
            Polynome P_temp;
            P_temp = puissance_polynomiale(Facteur, j); //Polynome de la forme (X - a)^j
            float facteur_rang_j = evaluation_polynome(derivee_nieme(P, j), a)/(float)factorielle(j);

            int k;
            for(k = 0; k <= P_temp.degre; k++) //Création du terme complet de rang j dans le polynome de la formule
                P_temp.liste[k] *= facteur_rang_j;
            
            DL = addition(DL, P_temp);
            free(P_temp.liste);
        }
        free(Facteur.liste);
    }
    else
        DL = P; //Si l'ordre du DL est supérieur au degré du polynome, le DL est le polynome.
    //archivage_DL(P, DL, a, n);
    return DL;
}

float Racine_P(Polynome P, float a, float b, float precision){
    float racines[P.degre];
    float x_n = b;
    float P_xn = evaluation_polynome(P, x_n);
    float P_prime_xn = evaluation_polynome(derivee(P), x_n);
    while(val_abs(P_xn) >= precision && x_n >= a){
        x_n = x_n - (P_xn/P_prime_xn);
        P_xn = evaluation_polynome(P, x_n);
        P_prime_xn = evaluation_polynome(derivee(P), x_n);
    }
    if(x_n < a) printf("Le polynome n'a pas de racine réelle sur [%f, %f].\n", a, b);
    //archivage_racine(P, x_n, a, b, precision);
    return x_n;
}

// OPERATEURS MATHEMATIQUES NON-POLYNOMIAUX //

int maxm(int a, int b){
    int result;
    if(a > b) result = a;
    else result = b;
    return result;
}

int minm(int a, int b){
    int result;
    if(a < b) result = a;
    else result = b;
    return result;
}

float puissance_n(float puissance, int exposant){
    float result = 1;
    if(exposant != 0){
        int i;
        for(i = 1; i <= exposant; i++)
            result *= puissance;
    }
    return result;
}

int factorielle(int n){
    if(n == 0)
        return 1;
    else 
        return n*factorielle(n-1);
}

float val_abs(float x){
    float result;
    if(x < 0) result = (-1)*x;
    else result = x;
    return x;
}


// IMPRESSION DANS LE LOG //

void impression_polynome(FILE* fichier, Polynome P){
    if(P.liste[0] != 0) fprintf(fichier, "%s%f%s", "[", P.liste[0], " + ");
    int i;
    for(i = 1; i < P.degre; i++){
        if(P.liste[i] != 0) fprintf(fichier, "%f%s%d%s", P.liste[i], "X^", i, " + ");
    }
    fprintf(fichier, "%f%s%d%s", P.liste[i], "X^", i, "]");
}

void archivage_creation(Polynome P){
    FILE* fichier = fopen("log.txt", "a");
    fprintf(fichier, "%s", "CREATION : ");
    impression_polynome(fichier, P);
    fprintf(fichier, "\n\n");
    fclose(fichier);
}

void archivage_addition(Polynome P1, Polynome P2, Polynome P_res){
    FILE* fichier = fopen("log.txt", "a");
    fprintf(fichier, "%s", "ADDITION : ");
    impression_polynome(fichier, P1);
    fprintf(fichier, "%s", " + ");
    impression_polynome(fichier, P2);
    fprintf(fichier, "%s", " = ");
    impression_polynome(fichier, P_res);
    fprintf(fichier, "\n\n");
    fclose(fichier);
}

void archivage_produit(Polynome P1, Polynome P2, Polynome P_res){
    FILE* fichier = fopen("log.txt", "a");
    fprintf(fichier, "%s", "PRODUIT : ");
    impression_polynome(fichier, P1);
    fprintf(fichier, "%s", " x ");
    impression_polynome(fichier, P2);
    fprintf(fichier, "%s", " = ");
    impression_polynome(fichier, P_res);
    fprintf(fichier, "\n\n");
    fclose(fichier);
}

void archivage_derivation(Polynome P, Polynome P_deriv){
    FILE* fichier = fopen("log.txt", "a");
    fprintf(fichier, "%s", "DERIVATION de ");
    impression_polynome(fichier, P);
    fprintf(fichier, "%s", " : P' = ");
    impression_polynome(fichier, P_deriv);
    fprintf(fichier, "\n\n");
    fclose(fichier);
}

void archivage_integrale(Polynome P, float d, float f, float integrale){
    FILE* fichier = fopen("log.txt", "a");
    fprintf(fichier, "%s%f%s%f%s", "INTEGRATION : intégrale sur [", d, ", ", f, "] de ");
    impression_polynome(fichier, P);
    fprintf(fichier, "%s", " = ");
    fprintf(fichier, "%f", integrale);
    fprintf(fichier, "\n\n");
    fclose(fichier);
}

void archivage_DL(Polynome P, Polynome DL, float a, int n){
    FILE* fichier = fopen("log.txt", "a");
    fprintf(fichier, "DL : ");
    impression_polynome(fichier, P);
    fprintf(fichier, "%s", " = ");
    impression_polynome(fichier, DL);
    fprintf(fichier, " + o(X - %f)\n", a);
    fprintf(fichier, "\n\n");
    fclose(fichier);
}

void archivage_racine(Polynome P, float racine, float a, float b, float precision){
    FILE* fichier = fopen("log.txt", "a");
    if(racine >= a){
        fprintf(fichier, "RACINE : %f est une racine de ", racine);
        impression_polynome(fichier, P);
        fprintf(fichier, " sur [%f, %f] à une précision de %f", a, b, precision);
    }
    else{
        fprintf(fichier, "RACINE : ");
        impression_polynome(fichier, P);
        fprintf(fichier, "n'a pas de racine sur [%f, %f].", a, b);
    }
    fprintf(fichier, "\n\n");
    fclose(fichier);
}

void reset_log(){
    FILE* fichier = fopen("log.txt", "w");
    fclose(fichier);
}


// AFFICHAGE DANS LE TERMINAL //

void afficher_coeff(Polynome P, int indice){
    if(P.degre == 0)
        printf("%f\n", P.liste[0]);
    else{
        if(indice == 0 && P.liste[indice] != 0) //cas du premier coéff (pas de X)
            printf("%f + ", P.liste[0]);
        else if(indice != 0 && indice != P.degre && P.liste[indice] != 0){ //cas des coéff quelconques
            if(P.liste[indice] == 1) 
                printf("X^%d + ", indice);
            else 
                printf("%f.X^%d + ", P.liste[indice], indice);
        }
        else if(indice == P.degre && P.liste[indice] != 0){//cas du coeeficient dominant (pas de + à la suite)
            if(P.liste[indice] == 1) 
                printf("X^%d", indice);
            else 
                printf("%f.X^%d", P.liste[indice], indice);
        }
    }
}

void afficher_polynome(Polynome P){
    if(P.degre == 0) printf("%f\n", P.liste[0]);
    else{
        afficher_coeff(P, 0);
        int i;
        for(i = 1; i <= P.degre - 1; i++)
            afficher_coeff(P, i);
        afficher_coeff(P, P.degre);
        printf("\n");
    }
}
