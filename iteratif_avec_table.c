#ifdef iterative_avec_table_recherche

#include "header.h"

int mode = 0;
int nb_elements_dans_table_recherche = 0;

void charger_table(int *table_recherche, int nombre_elements)
{
    FILE *fichier;
    fichier = fopen("table_recherche", "r");

    for (int i = 0; i < nombre_elements; i++)
    {
        fscanf(fichier, "%d", &table_recherche[i]);
    }
}

int nb_entiers_positifs_premiers_inferieurs_x(int x, int compteur, int res, int *table_recherche)
{
    if ((x == 0) || (x == 1))
    {
        return 0;
    }
    else if (mode == 0) // aucun élément dans la table de recherche
    {
        FILE *fichier;
        fichier = fopen("table_recherche", "a+");

        for (; compteur < x; compteur++)
        {
            if (est_premier(compteur, 2))
            {
                fprintf(fichier, "1 ");
                res++;
            }
            else
            {
                fprintf(fichier, "0 ");
            }
        }
        fclose(fichier);
    }
    else if (mode == 2) // tous les éléments sont dans la table de recherche
    {
        for (; compteur < x; compteur++)
        {
            if (table_recherche[compteur] == 1)
            {
                res++;
            }
        }
    }
    else
    {
        FILE *fichier;
        fichier = fopen("table_recherche", "a+");

        for (; compteur < nb_elements_dans_table_recherche; compteur++)
        {
            if (table_recherche[compteur] == 1)
            {
                res++;
            }
        }

        for (; nb_elements_dans_table_recherche < x; compteur++)
        {
            if (est_premier(compteur, 2))
            {
                fprintf(fichier, "1 ");
                res++;
            }
            else
            {
                fprintf(fichier, "0 ");
            }
        }
        fclose(fichier);
    }

    return res;
}

#endif