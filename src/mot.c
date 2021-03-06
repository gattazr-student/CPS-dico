#include <types.h>
#include <mot.h>
#include <maillon.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * compare_mot
 * Fonction de comparaison classique (cf. strcmp) entre un string et un maillon
 * @param aWord : mot à comparer
 * @param aMot : mot à comparer (convertis)
 * @return int : 0 si mot égaux, val négative si aWord <lex aMot,
 * val positive si aWord >lex aMot
 */
int compare_mots(char* aWord, mot_t* aMot){
	uint8_t wChar1, wChar2;
	lLettres_t *wCourant;
	int wEmplacement;
	int wI;

	wEmplacement = 0;
	wI = 0;
	wCourant = aMot->pTeteMot;

	/* Initialisation de wChar1 pour un résultat cohérent si aWord == NULL */
	wChar1 = -1;
	do{
		/* Récupération des deux caractères à tester */
		wChar1 = char_to_num(aWord[wI]);
		if(wCourant == NULL){
			wChar2 = 0;
			break;
		}
		wChar2 = get_charnum(&(wCourant->pMaillon), wEmplacement);

		/* Déplace courant sur le maillon suivant si necessaire*/
		if(wEmplacement == NB_LETTRES_MAILLON - 1){
			wEmplacement = 0;
			wCourant = wCourant->pNext;
		}else{
			wEmplacement++;
		}
		wI++;

		/* Vérifie que l'on a pas atteint la fin d'un des deux mots */
		if(wChar1 == '\0' || wChar2 == '\0'){
			break;
		}

	}while(wChar1 == wChar2); /* Boucle tant que les caractères récupéres sont égaux */

	if(wChar2 == '\0'){
		if(wChar1 == '\0'){
			/* aMot et aWord sont égaux (même longueur + meme contenu)*/
			return 0;
		}else{
			/* aMot est plus court que aMot et aMot est préfixe de aWord. Donc aMot <lew aWord  */
			return wChar1;
		}
	}

	/* Tous les autres cas (une lettre est différente ou aWord est plus court que aMot) */
	return wChar1 - wChar2;

}

/**
 * make_mot
 * Allocation de la mémoire pour créer un mot dans son ensemble
 * @param aWord : le string représentant le mot
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

	(wMot->pQueueListe)->pPos.pLigne = aLigne;
	(wMot->pQueueListe)->pPos.pColonne = aColonne;

	return wMot;
}

/**
 * update_mot
 * Permet de mettre un jour une liste de positions
 * @param aWord : le string représentant le mot
 * @param aLigne : Emplacement du mot (ligne)
 * @param aColonne : Emplacement du mot (colonne)
 */
void update_mot(mot_t* aMot, int aLigne, int aColonne){

	/* Allocation d'un nouvel element dans la liste de position */
	(aMot->pQueueListe)->pNext = malloc(sizeof(lEmplacement_t));
	aMot->pQueueListe = (aMot->pQueueListe)->pNext;
	aMot->pQueueListe->pNext = NULL;

	(aMot->pQueueListe)->pPos.pLigne = aLigne;
	(aMot->pQueueListe)->pPos.pColonne = aColonne;
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
		}while((l != '\0') && (position < NB_LETTRES_MAILLON));
		courant = courant->pNext;
	}
}

/**
 * afficher_mot
 * Affichage d'un mot : ses lettres puis les positions
 * @param mot : pointeur vers une structure de mot
 */
void afficher_mot (mot_t *mot){
	printf("\t");
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

#ifdef DEBUG
/**
 * afficher_maillons
 * Affichage des maillons d'un mot
 * @param tete : tete de la liste des maillons
 */
void afficher_maillons (mot_t *mot){
	lLettres_t *courantl = mot->pTeteMot;
	maillon_t *maillon;
	lEmplacement_t *courantp = mot->pTeteListe;
	emplacement_t *lieu;
	int position;
	char l;

	printf("|\t[ ");
	while(courantl != NULL){
		maillon = &(courantl->pMaillon);
		position=0;
		printf("{");
		do{
			l = num_to_char(get_charnum(maillon,position));
			if(l != '\0'){
				printf("%c", l);
			}
			position++;
		}while((l != '\0') && (position < NB_LETTRES_MAILLON));
		if(l=='\0'){
			while(position <= NB_LETTRES_MAILLON){
				printf(" ");
				position++;
			}
		}
		courantl = courantl->pNext;
		printf("}");
		if(courantl != NULL){
			printf(" -> ");
		}
	}
	printf("\n|\t  |\n|\t  |-->");


	while(courantp != NULL){
		lieu = &(courantp->pPos);
		printf(" {%i, %i}", lieu->pLigne, lieu->pColonne);
		courantp = courantp->pNext;
		if(courantp != NULL){
			printf(" -> ");
		}
	}

	printf("\t]\n|\n");
}
#endif
