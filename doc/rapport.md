Rapport
===============

Présentation du sujet
---------------------

Nous souhaitons faire un lexique de tous les mots présents dans un texte, et pour les retrouver facilement nous ajoutons à chaque mot le numéro de la ligne où il est présent mais après combien de caractères le mot commence sur cette ligne. Nous ne connaissons pas la taille du texte avant de la lire en entier alors nous devons créer une structure dynamique pour ne pas avoir de problème de gestion de mémoire. 

Choix de conception
-------------------
(structure des données et fonctions)

Nous pouvons modéliser la structure de donnée nécessaire à notre problème de gestion de mémoire par un embriquement de listes chaînées. Nous avons donc choisi de gérer un dictionnaire comme un pointeur vers la permière case chainée. Il est important d'avoir un pointeur vers ce dictionnaire car lors d'un ajout en tête il serai trop couteux de devoir déplacer tout le contenue d'un dictionnaire pour créer une place libre en début liste chainée. Ainsi avec un pointeur nous pouvons nous abstraire de se problème facilement.
Ensuite nous devons spécifier ce que chaque case contient. La case est coupée en deux, la deuxième partie servant à trouver la case suivante par un pointeur vers cette case. La première doit cond contenir un mot avec toutes les informations.

Un mot est composé d'une suite de lettres mais aussi des emplacements où il est présent dans le texte. 
Commençons par modéliser les positions. Nous ne savons pas si le mot va être présent plusieurs fois dans le texte nous avons donc deboin ici aussi d'une liste chaînée qui grandi en fonction de la répétion du mot dans le texte. Nous avons contruit cette structure de listes d'emplacement sur le même principe que le dictionnaire, avec la deuxième partie de la case qui pointe vers la suivante et la première qui contient un emplacement (couple ligne, colonne).
Il nous reste à voir ce qu'est la suite de lettres. Le sujet nous oblige à jouer avec des entiers de différents tailles pour mettre nos lettres dedans. Ceci est basé sur le fait que dans notre alphabet nous n'avons que 26 lettres et donc que nous pouvons les représenter sur seulement 5 bits alors que normalement un caractère simple (char) est sur 8 bits. Nous devons donc gérer une liste d'entiers 

Choix de programmation
----------------------

TODO

Organisation logicielle
-----------------------

TODO

Exemples d'éxecution
--------------------

TODO

Comment utiliser notre application, la compiler
-----------------------------------------------

TODO

Limites / Extentions
--------------------

TODO





Types définis :
---------------

- couple entier : emplacements
- liste position :lEmplacements
- maillon : entier 32 bits
- liste de maillon : lLettres
- liste de maillon, liste emplacements : mot_t
- liste mots : t_dictionnaire

Fonctions :
-----------

Ce qui manque :
- insertion_dico
- autre chose ?

Ce qui n'est pas encore tester :
- print_dictionnaire                                [NO TEST]

Ce qui marche :
- compare_mots                                      [DONE]
- make_dico                                         [DONE]
- make_mot -> création + allocation                 [DONE]
- free d'une liste (récursif ?)                     [DONE]
- char_to_num + num_to_char                         [DONE]
- get_charnum & set_charnum                         [DONE]
- print_mot -> print_lLettres + print_lPositions    [DONE]
