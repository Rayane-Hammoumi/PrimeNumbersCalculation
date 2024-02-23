#include "header.h"

extern int nb_elements_dans_table_recherche;
extern int mode; // indique que la table de recherche n'est pas remplie

int main(int argc, char *argv[])
{
    if (argc < 2) // si il n'y a pas assez d'arguments dans la commande
    {
        printf("Veuillez spécifier tous les arguments.\nUtilisation: ./version_recursive nombre_entier\n");
        return 1;
    }

    char *verifie_strtol; // pointeur utilisé par strtol pour vérifier que la taille spécifiée est bien un nombre
    int x = strtol(argv[1], &verifie_strtol, 10);
    if (*verifie_strtol != '\0')
    {
        printf("L'argument spécifié n'est pas un nombre\nUtilisation: ./version_recursive nombre_entier\n");
        return 1;
    }
    else if (x < 0)
    {
        printf("Veuillez spécifier un nombre positif\n");
        return 0;
    }

#ifdef recursive
    else if (x > 115000)
    {
        printf("Attention, pour la version récursive, j'ai personnellement eu des segmentation fault au délà de x>115 000\n");
    }
#endif

    clock_t start, end;
    double temps_execution;

#ifdef iterative_avec_table_recherche
    FILE *fichier;
    fichier = fopen("table_recherche", "a+");
    fseek(fichier, 0, SEEK_END);
    nb_elements_dans_table_recherche = ftell(fichier) / 2;
    int *table_recherche = NULL;
    // s'il n'y a 0 élément dans la table de recherche
    if (nb_elements_dans_table_recherche == 0)
    {
        fprintf(fichier, "0 ");
        fprintf(fichier, "0 "); // car 0 et 1 ne sont pas premiers
        fclose(fichier);
    }
    else if (nb_elements_dans_table_recherche < x)
    {
        mode = 1;
        table_recherche = malloc(nb_elements_dans_table_recherche * sizeof(int));
        charger_table(table_recherche, nb_elements_dans_table_recherche);
    }
    else
    {
        mode = 2;
        table_recherche = malloc(x * sizeof(int));
        charger_table(table_recherche, x);
    }

    start = clock();
    int res = nb_entiers_positifs_premiers_inferieurs_x(x, 2, 0, table_recherche);

#else
    start = clock();
    int res = nb_entiers_positifs_premiers_inferieurs_x(x, 2, 0);
#endif

    printf("Nombre d'entiers positifs premiers inférieurs à %d: %d\n", x, res);

    end = clock();
    temps_execution = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Temps d'exécution: %f\n", temps_execution);
}