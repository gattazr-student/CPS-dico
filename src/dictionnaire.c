#include <types.h>
#include <mot.h>
#include <stdlib.h>

/**
 * make_dico
 * Initialisation d'un dico vide
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
 * Libération d'un dictionnaire
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
