#include <stdio.h>
#include <stdlib.h>
#include <read_word.h>
#include <types.h>
#include <maillon.h>
#include <mot.h>
#include <string.h>
#include <dictionnaire.h>


/*
 * Application pour lire un texte et donner les mots contenus dedans avec leurs emplacements
 * Peut prendre un nom de fihcier en argument ou pas
 * Extension : lors de la compilation, donner -DDEBUG permet de voir comment s'articlue les maillons
 * EXtension : lors de la compilation, donner -DINTX pour un eniter de sockage sur X bits (X = 8, 16, 32, 64)
 */
int main(int aArgc, char** aArgv){
	FILE *wInput;
	unsigned int wLine, wCols;
	dictionnaire_t *wDico;
	char* wWord;

	/* Ouverture du fichier en paramètre si il existe. utilisation de stdin sinon */
	if(aArgc > 1){
		wInput = fopen(aArgv[1], "r");
		if(wInput == NULL){
			fprintf(stderr, "%s : The specified file does not exist\n", aArgv[0]);
			exit(127);
		}
	}else{
		wInput = stdin;
	}

	wLine = 0;
	wCols = 0;

	/* Traite les mots entrant dans stdin */
	while(!feof(wInput)){
		wWord = next_word(wInput, &wLine, &wCols);
		inserer_mot_dico(&wDico, wWord, wLine, wCols);
		free(wWord);
	}

	printf("\n\nDictionnaire :\n");
	afficher_dico(wDico);

#ifdef DEBUG
		printf("\n\nMaillons :\n");
		afficher_maillons_dico(wDico);
#endif

	/* Libération de la mémoire qui a été alloué */
	liberer_dico(wDico);

	/* Ferme le fichier input si il ne s'agit pas de stdin */
	if(fileno(wInput) != fileno(stdin)){
		fclose(wInput);
	}

	return 0;
}
