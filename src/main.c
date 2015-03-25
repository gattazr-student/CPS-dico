#include <stdio.h>
#include <stdlib.h>
#include <read_word.h>
#include <types.h>

int main(int aArgc, char** aArgv){
	FILE *wInput;
	char *wWord;
	unsigned int wLine, wCols;

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
		fprintf(stdout, "%s (%d,%d)\n", wWord, wLine, wCols);
	}

	/* Ferme le fichier input si il ne s'agit pas de stdin */
	if(fileno(wInput) != fileno(stdin)){
		fclose(wInput);
	}

	return 0;
}