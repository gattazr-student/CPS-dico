#include <types.h>
#include <dictionnaire.h>
#include <mot.h>
#include <stdlib.h>
#include <stdio.h>


/**
 * inserer_mot_dico
 * Permet de mettre un string dans le dictionnaire
 * @param dictionnaire_t ** : un pointeur vers le point de tête du dictionnaire car la tête peux changer au cours de l'éxécution de la fonction
 * @param nb_l, nb_c : donnés comme valeur car on ne les modifie pas, nous utilisons juste les valeurs pour les ajouter
 */
void inserer_mot_dico (dictionnaire_t **dico, char *mot, int nb_l, int nb_c){
	dictionnaire_t *wDico_courant;
	dictionnaire_t *wDico_precedent;
	mot_t *wMot;
	int wCompare=1; /* on doit inserer en tête si jamais le dico est vide */

	wDico_courant = *dico; /* on récupère le premier élement du dictionnaire */

	if(wDico_courant != NULL){ /* Si le dictionnaire n'est pas vide */
		wMot = wDico_courant->pMot; /* on récupère le premier mot */
		/* on fait cela pour savoir si l'on fait un ajout en tête du dictionnaire */
		wCompare = compare_mots(mot, wMot);
	}
	if(wCompare > 0){ /* cas de l'ajout en tête, qu'il soit vide ou pas */
		wMot = make_mot(mot, nb_l, nb_c); /* wMot pointe vers le premier mot du dictionnaire */
		*dico = make_dico(); /* création d'une nouvelle cellule du dictionnaire */
		(*dico)->pMot = wMot; /* mise en place du premier mot */
		(*dico)->pNext = wDico_courant; /* mise en place du reste du dictionnaire */
	}else if(wCompare == 0){ /* cas ou l'on ajout à la liste de position */
		update_mot(wMot, nb_l, nb_c); /* Ajout d'un emplacement dans la liste du mot */
	}else{ /* on continue de cherche la place dans le dictionnaire */
		wDico_precedent = wDico_courant;
		wDico_courant = wDico_courant->pNext; /* on avance d'une position */
		wCompare = -1;
		while(wDico_courant != NULL && wCompare < 0){
			wMot = wDico_courant->pMot;
			wCompare = compare_mots(mot, wMot);
			wDico_precedent = wDico_courant; /* on garde en mémoire la cellule d'avant */
			wDico_courant = wDico_courant->pNext; /* on avance d'une position */
		}
		if(wCompare == 0){ /* on vient de trouver le mot donc on met à jour sa liste de positions */
			update_mot(wMot, nb_l, nb_c);
		}else{ /* on est arrivé à la fin du dictionnaire ou on est bien placé */
			wMot = make_mot(mot, nb_l, nb_c); /* On crée une case pour le mot */
			wDico_precedent->pNext = make_dico(); /* On crée une case du dictionnaire */
			/* On renseigne la case */
			(wDico_precedent->pNext)->pMot = wMot;
			(wDico_precedent->pNext)->pNext = wDico_courant; /* Avec la case suivante que l'on avait sauvée' */
		}
	}
}

/**
 * make_dico
 * Création d'une case vide d'un dictionnaire
 * @return dictionnaire_t*: pointeur sur un dictionnaire vide
 */
dictionnaire_t* make_dico(){
	 dictionnaire_t* wDico;
	 wDico = (dictionnaire_t*) malloc(sizeof(dictionnaire_t));
	 wDico->pMot = NULL;
	 wDico->pNext = NULL;
	 return wDico;
}

/**
 * liberer_dico
 * Libération d'une case de dictionnaire
 * @param tete : tete du dictionnaire_t à libérer
 */
void liberer_dico (dictionnaire_t *tete){
	dictionnaire_t *courant;
	while(tete != NULL){
		courant = tete;
		tete = tete->pNext;
		liberer_mot(courant->pMot);
		free(courant);
	}
}

/**
 * afficher_dico
 * Affichage de tous les mots d'un dictionnaire
 * @param : pointeur vers un dictionnaire
 */
void afficher_dico (dictionnaire_t *dico){
	dictionnaire_t *courant = dico;
	while(courant != NULL){
		afficher_mot(courant->pMot);
		courant = courant->pNext;
	}
}

/**
 * afficher_maillons_dico
 * Affichage de tous les maillons de tous les mots d'un dictionnaire
 * @param : pointeur vers un dictionnaire
 */
void afficher_maillons_dico (dictionnaire_t *dico){
	dictionnaire_t *courant = dico;
	while(courant != NULL){
		afficher_maillons(courant->pMot);
		courant = courant->pNext;
	}
}
