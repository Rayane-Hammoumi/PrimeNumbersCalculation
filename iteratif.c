#if defined(iterative) || defined(iterative_avec_table_recherche)
#include "header.h"

// renvoie 1 si le nombre est premier, 0 sinon
// compteur2 commence à 2 au premier appel de est_premier
int est_premier(int n, int compteur2)
{
    for (; compteur2 < n; compteur2++)
    {
        // si le reste de la division euclidienne de n par compteur2 est 0
        if (n % compteur2 == 0)
        {
            return 0; // n n'est pas premier car on a trouvé un diviseur autre que 1 et n
        }
    }

    return 1;
}
#endif

#ifdef iterative
int nb_entiers_positifs_premiers_inferieurs_x(int x, int compteur, int res)
{
    if ((x == 0) || (x == 1))
    {
        return 0;
    }

    for (; compteur < x; compteur++)
    {
        if (est_premier(compteur, 2))
        {
            res++;
        }
    }

    return res;
}

#endif
