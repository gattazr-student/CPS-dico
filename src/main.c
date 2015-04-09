#include <stdio.h>
#include <stdlib.h>
#include <read_word.h>
#include <types.h>
#include <maillon.h>
#include <mot.h>
#include <dictionnaire.h>


/*
 * TODO: comments
 */
int main(int aArgc, char** aArgv){
	FILE *wInput;
	char *wWord;
	unsigned int wLine, wCols;
	mot_t* wMot;


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
		wMot = make_mot(wWord, wLine, wCols);

		fprintf(stdout, "%s (%d,%d)\n", wWord, wLine, wCols);
		afficher_mot(wMot);
		liberer_mot(wMot);
	}

	/* Ferme le fichier input si il ne s'agit pas de stdin */
	if(fileno(wInput) != fileno(stdin)){
		fclose(wInput);
	}

	return 0;
}
