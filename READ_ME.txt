COMMENT PARCOURIR LE DOSSIER DU PROJET ?

Le projet est modularisé, c'est pourquoi le dossier est composé de quatre fichiers (sans compter le READ ME).
Les fichiers ont des noms explicites : main.c est le main, fonctions.c regroupe les fonctions, etc...
Pour connaitre les spécifications des fonctions, lire le header.
Le main comprend les débugs réalisés à mesure que le projet fut écrit. 



FORME DES POLYNOMES :

Les polynomes sont des des structures de données ayant deux paramètres : la liste des coéfficients réels
et le degré du polynome. 

L'exposant de X pour un coéfficient donné est l'indice de ce dernier dans la liste de la structure
de donnée. 

A chque définition d'un nouveau polynome, on alloue dynamiquement un tableau d'entiers de taille 
degre + 1. On libère tous ces tableaux à la fin du main.


IMPRESSION D'UN POLYNOME : 

On met les polynomes entre crochets dans log.txt pour faciliter la lecture (en particulier 
lors d'une somme ou d'un produit).
