#ifndef _READ_WORD_H_
#define _READ_WORD_H_

/**** Variables globales et fonction pour l'analyse du fichier de texte ****/

#include <stdio.h>
#define SEP " ,.?"    /* Tous les separateurs prevus */

/* numeros courants de ligne et de colonne dans le fichier en cours
d'analyse (variables globales mises a jour par la fonction next_word) */
extern unsigned int current_line, current_col;

/* chaine contenant tous les separateurs prevus (utilisee par la
fonction next_word) */
extern char *separators;

/* Fonction pour l'analyse lexicale du fichier.
 * Chaque appel a cette fonction renvoie le prochain mot du texte contenu
 * dans le fichier repere par le descripteur f.
 * @param f: descripteur de fichier a analyser
 * @param nblin: adresse d'entier, pour ramener le numero de ligne du mot lu
 * @param nbcol: adresse d'entier, pour ramener le numero de colonne du mot lu
 * @return
 */
char *next_word(FILE *f, unsigned int *nblin, unsigned int *nbcol);

#endif
