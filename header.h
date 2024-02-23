#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int est_premier(int n, int compteur2);
int calcule_reste_division_euclidienne(int x, int y);

#ifdef iterative_avec_table_recherche
void charger_table(int *table_recherche, int nombre_elements);
int nb_entiers_positifs_premiers_inferieurs_x(int x, int compteur, int res, int *table_recherche);

#else
int nb_entiers_positifs_premiers_inferieurs_x(int n, int i, int res);

#endif