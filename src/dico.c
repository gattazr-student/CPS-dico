#include <stdio.h>
#include <stdlib.h>
#include <read_word.h>

int main(int aArgc, char** aArgv){
	FILE *wInput;
	int wOpened;

	char *wWord;
	unsigned int wLine, wCols;

	/* Ouverture du fichier en paramètre si il existe. utilisation de stdin sinon */
	if(aArgc == 2){
		wInput = fopen(aArgv[1], "r");
		wOpened = 1;
		if(wInput == 0){
			fprintf(stderr, "%s : The specified file does not exist\n", aArgv[0]);
			exit(127);
		}
	}else{
		wInput = stdin;
		wOpened = 0;
	}

	wLine = 0;
	wCols = 0;

	while(!feof(wInput)){
		wWord = next_word(wInput, &wLine, &wCols);
		fprintf(stdout, "%s (%d,%d)\n", wWord, wLine, wCols);
	}

	/* Ferme le fichier input si il ne s'agit pas de stdin */
	if(wOpened){
		fclose(wInput);
	}

	return 0;
}