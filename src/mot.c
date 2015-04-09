#include <types.h>
#include <mot.h>
#include <maillon.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * compare_mot
 * @param aWord : mot à comparer
 * @param aMot : mot à comparer (convertis)
 * @return int : 0 si mot égaux, val négative si aWord1 <lex aWord2,
 * val positive si aWord1 >lex aWord2
 */
int compare_mots(char* aWord, mot_t* aMot){
	int wLength;
	uint8_t wChar2;
	uint8_t wChar1;
	lLettres_t *wCourant;
	int wEmplacement;
	int wI;

	wLength = strlen(aWord);
	wEmplacement = 0;
	wI = 0;
	wCourant = aMot->pTeteMot;
	wChar2 = get_charnum(&(wCourant->pMaillon), wEmplacement);
	wChar1 = char_to_num(aWord[wI]);
	while(wChar1 == wChar2){
		if(wEmplacement > NB_LETTRES_MAILLON){
			wEmplacement = 0;
			wCourant = wCourant->pNext;
		}else{
			wEmplacement++;
		}
		wI++;
		wChar2 = get_charnum(&(wCourant->pMaillon), wEmplacement);
		wChar1 = char_to_num(aWord[wI]);
	}

	if(wI == wLength-1){
		if(wChar2 == '\0'){
			return 0;
		}else{
			return -1;
		}
	}
	if(wChar2 == '\0'){
		return 1;
	}

	return wChar1 - wChar2;
}

/*
 * make_mot
 * @param aWord :
 * @param aLigne : Emplacement du mot (ligne)
 * @param aColonne : Emplacement du mot (colonne)
 * @return mot_t* : nouveau mot contenant
 */
mot_t* make_mot(char* aWord, int aLigne, int aColonne){
	int wLength;
	mot_t* wMot;
	lLettres_t* wLettresCourant;
	lLettres_t* wNext;
	int wI, wEmplacement;

	/* allocation du mot */
	wMot = (mot_t*) malloc(sizeof(mot_t));
	wMot->pTeteMot = NULL;
	wMot->pQueueMot = NULL;
	wMot->pTeteListe = NULL;
	wMot->pQueueListe = NULL;

	/* allocation des maillons contenant les lettres du mot */
	wMot->pTeteMot = (lLettres_t*) malloc(sizeof(lLettres_t));
	(wMot->pTeteMot)->pNext = NULL;
	wMot->pQueueMot = wMot->pTeteMot;

	wI = 0;
	wEmplacement = 0;
	wLettresCourant = wMot->pTeteMot;
	wLength = strlen(aWord);
	while(wI < wLength){
		/* Remet wEmplacement à 0 et création d'un nouveau maillon */
		if(wEmplacement >= NB_LETTRES_MAILLON){
			wEmplacement = 0;
			/* Créé un maillon supplémentaire */
			wNext = (lLettres_t*) malloc(sizeof(lLettres_t));
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

/**
 *TODO: comments
 */
void update_mot(mot_t* aMot, int aLigne, int aColonne){
	/* TODO: function */
	return;
}

/**
 * afficher_liste_position
 * Affichage d'une liste de position
 * @param tete : tete de la liste lEmplacement_t à afficher
 * @ensure affichage : permet aussi de passer à la ligne et de gérer les espaces
 */
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

/**
 * afficher_liste_lettres
 * Affichage des lettres d'un mot avec gestion des maillons
 * @param tete : tete de la liste des maillons
 */
void afficher_liste_lettres (lLettres_t *tete){
	lLettres_t *courant = tete;
	maillon_t *maillon;
	int position;
	char l;

	while(courant != NULL){
		maillon = &(courant->pMaillon);
		position=0;
		do{
			l = num_to_char(get_charnum(maillon,position));
			if(l != '\0'){
				printf("%c", l);
			}
			position++;
		}while((l != '\0') && (position <= NB_LETTRES_MAILLON));
		courant = courant->pNext;
	}
}

/**
 * afficher_mot
 * Affichage d'un mot : ses lettres puis les positions
 * @param mot : pointeur vers une structure de mot
 */
void afficher_mot (mot_t *mot){
	afficher_liste_lettres(mot->pTeteMot);
	afficher_liste_positions(mot->pTeteListe);
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
