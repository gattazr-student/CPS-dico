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
	unsigned int wLine, wCols;
	dictionnaire_t *wDico;
	char reponse;
	char* wWord;
	int wRepeat;


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
	wDico = make_dico();

	/* Traite les mots entrant dans stdin */
	while(!feof(wInput)){
		wWord = next_word(wInput, &wLine, &wCols);
		inserer_mot_dico(&wDico, wWord, wLine, wCols);
		free(wWord);
	}

	do{

		do{
			wRepeat = 1;
			printf("\tLecture finie, que voulez-vous faire ?\n");
			printf("\t 1 - afficher le dictionnaire\n");
			printf("\t 2 - afficher les maillons\n");
			printf("\t 3 - quitter\n");
			fflush(stdin);
			scanf("%c",&reponse);
			if(reponse < '1' || reponse > '3' ){
				wRepeat = 0;
				printf("Choix incorrect\n\n");
			}
		}while( wRepeat );
		switch(reponse){
			case '1':
				afficher_dico(wDico);
			break;
			case '2':
				/* TODO: afficher_maillons de chaque mots du dico */
			break;
		}
	}while(reponse != '3');


	liberer_dico(wDico);

	/* Ferme le fichier input si il ne s'agit pas de stdin */
	if(fileno(wInput) != fileno(stdin)){
		fclose(wInput);
	}

	return 0;
}
