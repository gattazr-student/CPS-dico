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
		insere_dico(wDico, next_word(wInput, wLine, wCols);
	}
	do{
		printf("\tLecture finie, voulez-vous afficher le dictionnaire ? Y(y) / N(n)\n");
		if(scanf("%c",&reponse)!=1){
			printf("Y -> avec affichage\nN -> sans affichage\n");
		}
	}while( (reponse!='Y') || (reponse!='y') || (reponse!='N') || (reponse!='n'));
	if(reponse == 'Y' || reponse == 'y'){
		afficher_dico(wDico);
	}
	liberer_dico(wDico);

	/* Ferme le fichier input si il ne s'agit pas de stdin */
	if(fileno(wInput) != fileno(stdin)){
		fclose(wInput);
	}

	return 0;
}
