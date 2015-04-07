#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <types.h>
#include <dictionnaire.h>
#include <maillon.h>

#define TAILLE_LETTRE 5 /* COMENTAIRE : USE GLOBAL */


/*
 * TODO: comments
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

void liberer_positions (lEmplacement_t *tete){
	lEmplacement_t *courant;
	while(tete != NULL){
		courant = tete;
		tete = tete->pNext;
		free(courant);
	}
}

void liberer_lettres (lLettres_t *tete){
	lLettres_t *courant;
	while(tete != NULL){
		courant = tete;
		tete = tete->pNext;
		free(courant);
	}
}

void liberer_mot (mot_t *mot){
	liberer_positions(mot->pTeteListe);
	liberer_lettres(mot->pTeteMot);
	free(mot);
}

void liberer_dico (dictionnaire_t *tete){
	dictionnaire_t *courant;
	while(tete != NULL){
		courant = tete;
		tete = tete->pNext;
		liberer_mot(courant->pMot);
		free(courant);
	}
}

void afficher_liste_positions (lEmplacement_t *tete){
	lEmplacement_t *courant = tete;
	emplacement_t *lieu;
	while(courant != NULL){
		lieu = &(courant->pPos);
		printf(" (%i,%i)", lieu->pLigne, lieu->pColonne);
		courant = courant->pNext;
	}
	printf("\n");
}

void afficher_liste_lettres (lLettres_t *tete){
	lLettres_t *courant = tete;
	maillon_t *maillon;
	int position;
	char l;
	int nb_lettre = sizeof(maillon_t)/TAILLE_LETTRE; /* COMENTAIRE : USE GLOBAL */
	while(courant != NULL){
		maillon = &(courant->pMaillon);
		position=0;
		do{
			l=num_to_char(get_charnum(maillon,position));
			if(l != '\0'){
				printf("%c", l);
			}
			position++;
		}while((l != '\0') && (position <= nb_lettre));
		courant = courant->pNext;
	}
}
