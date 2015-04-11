Rapport
===============

Présentation du sujet
---------------------

Nous souhaitons faire un lexique de tous les mots présents dans un texte, et pour les retrouver facilement nous ajoutons à chaque mot le numéro de la ligne où il est présent et après combien de caractères le mot commence sur cette ligne. Etant donée que nous ne connaissons pas la taille du texte avant de le lire en entier alors nous devons créer une structure dynamique qui aura exactement la taille nécessaire permettant de contenir tous le lexique.

Choix de conception
-------------------
(structure des données et fonctions)

Nous pouvons modéliser la structure de donnée nécessaire à notre problème de gestion de mémoire par un embriquement de listes chaînées. Nous avons donc choisi de gérer un dictionnaire comme un pointeur vers la permière case chainée. Il est important d'avoir un pointeur vers ce dictionnaire car lors d'un ajout en tête il serai trop couteux de devoir déplacer tout le contenue d'un dictionnaire pour créer une place libre en début liste chainée. Ainsi avec un pointeur nous pouvons nous abstraire de se problème facilement.
Ensuite nous devons spécifier ce que chaque case contient. La case est coupée en deux, la deuxième partie servant à trouver la case suivante par un pointeur vers cette case. La première doit cond contenir un mot avec toutes les informations.

Un mot est composé d'une suite de lettres mais aussi des emplacements où il est présent dans le texte.
Commençons par modéliser les positions. Nous ne savons pas si le mot va être présent plusieurs fois dans le texte nous avons donc besoin ici aussi d'une liste chaînée qui grandi en fonction de la répétion du mot dans le texte. Nous avons contruit cette structure de listes d'emplacement sur le même principe que le dictionnaire, avec la deuxième partie de la case qui pointe vers la suivante et la première qui contient un emplacement (couple d'entiers ligne, colonne).
Il nous reste à voir ce qu'est la suite de lettres. Le sujet nous oblige à jouer avec des entiers de différents tailles pour mettre nos lettres dedans. Ceci est basé sur le fait que dans notre alphabet nous n'avons que 26 lettres et donc que nous pouvons les représenter sur seulement 5 bits alors que normalement un caractère simple (char) est sur 8 bits. Nous devons donc gérer une liste d'entiers

Choix de programmation
----------------------

Afin de pouvoir changer facilement la taille des maillons plus tard, nous avons décidé de définir dans le fichier maillon.c un constante. Appelé NB_LETTRES_MAILLON, cette constante contient le nombre de lettres qu'il est possible de mettre dans un maillon. Cette constante est calculé en divisant le nombre de bit

Grâce à cette constante, il a suffit de changer le typedef maillon_t pour chager la taille du maillon et que cela soit appliqué dans tous le programme.


Organisation logicielle
-----------------------

TODO

Exemples d'éxecution
--------------------

TODO

Comment utiliser notre application, la compiler
-----------------------------------------------

L'application dico dépend de la librairie tokenize. Cette librairie est présente dans le dossier lib et le makefile a été écris afin que la compilation fonctionne sur les plateformes Linux et Mac OS X. Pour pouvoir executer le programme, il est cependant necessaire d'ajouter le chemin vers le dossier lib correspondant dans la variable d'environnement LD_LIBRARY_PATH pour linux et DYLD_LIBRARY_PATH pour OSX. Sourcer le fichier setenv.sh à la racine permet d'effectuer cette opération pour les linux 64 bits et Mac OS X

La compilation et l'exécution de notre projet se fait donc de la façon suivante :
```sh
$ source ../setenv.sh
$ make
$ ./dico [fichier]
```
Le paramètre [fichier] est optionnel.

Le programme permet de récupérer le texte entrés au clavier par un utilisateur et de faire le dictionnaire contenant tous les mots de ce texte. Si le nom d'un fichier est fourni et que celui ci est valide, alors c'est ce fichier qui sera utilisé comme texte.

Dans le cas ou la constante DEBUG est défini pendant la compilation, en plus de l'affichage classique, le dictionnaire sera affiché sous formes de liste de mots. Cela permet de visualiser facilement les structures de données utilisés pour stocker les mots dans le dictionnaires.


Limites / Extentions
--------------------

Par défault, les maillons utilisés pour stocker les lettres de chaque mot du dictionnaire ont une taille de 32 bits. Il est cependant possible d'utiliser des maillons de 8, 16 ou 64 bits. Pour cela, il faut définir pendant la compilation la constant INT8, INT16 ou INT64.


Types définis :
---------------

- couple entier : emplacements
- liste position : lEmplacements
- maillon : entier 8/16/32/64 bits (uint)
- liste de maillon : lLettres
- liste de maillon, liste emplacements : mot_t
- liste mots : t_dictionnaire

Fonctions :
-----------

- print_dictionnaire                                [DONE]
- compare_mots                                      [DONE]
- make_dico                                         [DONE]
- make_mot -> création + allocation                 [DONE]
- free d'une liste (récursif)                       [DONE]
- char_to_num + num_to_char                         [DONE]
- get_charnum & set_charnum                         [DONE]
- print_mot -> print_lLettres + print_lPositions    [DONE]
- afficher_maillons [DONE]
