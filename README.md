# Prime number calculations
 Calcul en C le nombre de positifs premiers inférieur à l'argument. 3 versions : récursive, itérative et itérative avec table de recherche. Voir le rapport (pdf) pour les calculs de complexité, les mesures de performance et les preuves d'algorithmes

---------------------------

Compilation: "make" produira 3 exécutables:

- version_recursive
- version_iterative
- version_iterative_avec_table_recherche

Le fichier "table_recherche" ne contient que des 0 et des 1.
1er chiffre = 0 car 0 n'est pas premier, 3ème chiffre = 1 car 2 est premier etc ...

Cette table a été remplie exclusivement grâce à l'exécution de version_iterative_avec_table_recherche. 

S'il n'y a pas assez de valeurs dans la table, vous irez plus vite en utilisant version_iterative. La version_iterative_avec_table_recherche remplira tout de même les valeurs manquantes qu'elle trouve au fur et à mesure. Vous pouvez donc supprimer tous les caractères contenus dans ce fichier manuellement pour comparer les performance. 

La table est longue à remplir. Par contre, une fois assez remplie, l'exécution pour n'importe quel argument est quasiment instantanée.


---------------------------

Exécution: "./version_nom_version nombre_entier"