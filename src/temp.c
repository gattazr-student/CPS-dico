#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <types.h>
#include <dictionnaire.h>
#include <maillon.h>



/**
 * insere_dico
 *
 */
void insere_dico(char* aWord, int aLigne, int aColonne){

}

/**
 * make_mot
 * @param aWord :
 * @param aLigne : Emplacement du mot (ligne)
 * @param aColonne : Emplacement du mot (colonne)
 * @return mot_t* : nouveau mot contenant
 */
mot_t* make_mot(char* aWord, int aLigne, int aColonne){
	int wLenght;
	mot_t* wMot;
	lLettres_t* wLettresCourant;
	lLettres_t* wNext;
	int wI, wEmplacement;
	int nb_lettre; /* COMMENTAIRE : USE GLOBAL OR MAKE FUNCTION */

	nb_lettre = sizeof(maillon_t)/5; /* COMMENTAIRE : USE GLOBAL */

	/* allocation du mot */
	wMot = (mot_t*) malloc(sizeof(mot_t));
	wMot->pTeteMot = NULL;
	wMot->pQueueMot = NULL;
	wMot->pTeteListe = NULL;
	wMot->pQueueListe = NULL;

	/* allocation des maillons contenant les lettres du mot */
	wMot->pTeteMot = malloc(sizeof(lLettres_t));
	(wMot->pTeteMot)->pNext = NULL;
	wMot->pQueueMot = wMot->pTeteMot;

	wI = 0;
	wEmplacement = 0;
	wLettresCourant = wMot->pTeteMot;
	wLenght = strlen(aWord);
	while(wI < wLenght){
		/* Remet wEmplacement à 0 et création d'un nouveau maillon */
		if(wEmplacement > nb_lettre){ /* COMMENTAIRE : USE GLOBAL */
			wEmplacement = 0;
			/* Créé un maillon supplémentaire */
			wNext = malloc(sizeof(lLettres_t));
			wNext->pNext = NULL;
			wNext->pMaillon = 0; /* Initialise le nouveau maillon à 0 */
			wLettresCourant->pNext = wNext;
			wLettresCourant = wNext;
			wMot->pQueueMot = wNext;
		}
		set_charnum(&(wLettresCourant->pMaillon), wEmplacement, char_to_num(aWord[wI]));
		wI++;
		wEmplacement++;
	}

	/* Allocation de la liste de position */
	wMot->pTeteListe = malloc(sizeof(lEmplacement_t));
	(wMot->pTeteListe)->pNext = NULL;
	wMot->pQueueListe = wMot->pTeteListe;

	(wMot->pTeteListe)->pPos.pLigne = aLigne;
	(wMot->pTeteListe)->pPos.pColonne = aColonne;

	return wMot;
}

/**
 * liberer_positions
 * Libération d'une liste de positions
 * @param tete : tete de la liste lEmplacement_t à libérer
 */
void liberer_positions (lEmplacement_t *tete){
	lEmplacement_t *courant;
	while(tete != NULL){
		courant = tete;
		tete = tete->pNext;
		free(courant);
	}
}

/**
 * liberer_lettres
 * Libération d'une listre de lettres
 * @param tete : tete de la liste lLettres_t à libérer
 */
void liberer_lettres (lLettres_t *tete){
	lLettres_t *courant;
	while(tete != NULL){
		courant = tete;
		tete = tete->pNext;
		free(courant);
	}
}

/**
 * liberer_mot
 * Libération d'un mot
 * @param mot : mot à libérer
 */
void liberer_mot (mot_t *mot){
	liberer_positions(mot->pTeteListe);
	liberer_lettres(mot->pTeteMot);
	free(mot);
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
 * afficher_liste_position
 * Affichage d'une liste de position
 * @param tete : tete de la liste lEmplacement_t à libérer
 */
void afficher_liste_position (lEmplacement_t *tete){
	lEmplacement_t *courant = tete;
	emplacement_t *lieu;
	while(courant != NULL){
		lieu = &(courant->pPos);
		printf(" (%i,%i)", lieu->pLigne, lieu->pColonne);
		courant = courant->pNext;
	}
	printf("\n");
}