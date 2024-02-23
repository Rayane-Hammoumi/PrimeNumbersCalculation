#ifdef recursive
#include "header.h"

// renvoie 1 si le nombre est premier, 0 sinon
// compteur2 commence à 2 au premier appel de est_premier
int est_premier(int n, int compteur2)
{
    // cas d'arrêt 1:
    // si on n'a pas trouvé de diviseur parmi tous les entiers positifs entre 1 exclu et n exclu
    // le nombre est premier
    if (compteur2 == n)
    {
        return 1;
    }
    // sinon si le reste de la division euclidienne de n par compteur2 n'est pas 0
    // alors compteur2 n'est pas un diviseur de n
    // On continue de vérifier les nombres suivants
    else if (n % compteur2 != 0)
    {
        compteur2++;
        return est_premier(n, compteur2);
    }

    // Cas d'arrêt 2: on a trouvé un diviseur de n autre que 1 et n
    // Le nombre n'est pas premier
    else
    {
        return 0;
    }
}

// Teste si chaque positif inférieur à x est premier.
// res représente le nombre des positifs premiers inférieurs à x
// compteur: nombre en cours de test (pour déterminer s'il est premier) dans cet appel
// compteur vaut 2 lors du 1er appel de cette fonction
int nb_entiers_positifs_premiers_inferieurs_x(int x, int compteur, int res)
{
    if ((x == 0) || (x == 1))
    {
        return 0;
    }

    else if (compteur == x) // cas d'arrêt: on a fini de vérifier tous les nombres inférieurs à x
    {
        return res;
    }

    else
    {
        if (est_premier(compteur, 2))
        {
            res++;
        }

        compteur++;

        return nb_entiers_positifs_premiers_inferieurs_x(x, compteur, res);
    }
}
#endif