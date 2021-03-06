#include <types.h>
#define MAILLON_SRC
#include <maillon.h>
#include <stdlib.h>

int NB_LETTRES_MAILLON = sizeof(maillon_t)*8/TAILLE_LETTRE;

/*  
 * set_charnum
 * Permet de mettre une lettre dans le maillon en effaçant ce qu'il y avait avant
 * @param maillon_t* : le maillon a modifier
 * @param int : numéro de la lettre à changer dans le maillon
 * @param uint8_t : correspond à l'entier codant la lettre initiale
 * @Invariant bon_indice : 0<= num <= sizeof(maillon_t)/TAILLE_LETTRE
 */
void set_charnum (maillon_t *maillon, int num, uint8_t l){
	maillon_t mask = 0x1F; /* COMENTAIRE : MAKE A FUNCTION TO PRODUCE IT WITH NB_LETTRES_MAILLON */
	maillon_t charnum = (maillon_t)l;

	/* On décale le masque et la lettre à la bonne place */
	mask <<= (TAILLE_LETTRE * (NB_LETTRES_MAILLON - num - 1));
	charnum = charnum << (TAILLE_LETTRE * (NB_LETTRES_MAILLON - num - 1));
	/* inversion du mask pour faire une initialisation avant l'écriture */
	mask = ~mask;
	*maillon = *maillon & mask; /* Effacement de l'ancienne valeur */
	*maillon = *maillon | charnum;
}

/*
 * get_charnum
 * Donne le chiffre qui code la lettre à la position donnée dans le maillon donné
 * @param maillon_t* : Pointeur sur le maillon d'où l'on veut extraire une lettre
 * @param int : numéro de la lettre en partant de poids forts de l'entier de stockage
 * @Invariant bon_indice : 0<= num <= sizeof(maillon_t)/TAILLE_LETTRE
 */
uint8_t get_charnum (maillon_t *maillon, int num){
	maillon_t mask = 0x1F; /* COMENTAIRE : MAKE A FUNCTION TO PRODUCE IT WITH NB_LETTRES_MAILLON */
	int depl;

	depl = (TAILLE_LETTRE * (NB_LETTRES_MAILLON - num - 1));
	mask <<= depl;
	mask = *maillon & mask;

	/* On décale le masque vers le bits de poids faibles pour le cast */
	mask >>= depl;

	return (uint8_t)mask;
}

/**
 * char_to_num
 * Convertit un caractère en un entier
 * Si le charatère est une lettre de l'alphabet (en majuscule ou minuscule),
 * l'entier retourné est sa position dans l'alphabet. Sinon, 0 est retourné.
 * @param aChar : lettre à convertir
 * @return : entier correspondant à la position de la lettre aChar dans
 *           l'alphabet
 */
uint8_t char_to_num (char aChar){
	if(aChar >= 'a' && aChar <= 'z'){
		return aChar - 'a' + 1;
	}else if (aChar >= 'A' && aChar <= 'Z'){
		return aChar - 'A' + 1;
	}
	return 0;
}

/**
 * num_to_char
 * Convertit un entier en un caractère
 * Si l'entier passé en paramètre n'est pas compris entre 1 et 26, le caractère
 * '\0' est retourné. Sinon, il s'agit de la lettre de l'alphabet correspondante.
 * @param aNum : entier à transformer
 * @return char : lettre de l'alphabet à la position aNum dans l'alphabet
 */
char num_to_char (uint8_t aNum){
	if ( aNum > 0 && aNum < 27){
		return 'a' + aNum - 1;
	}
	return '\0';
}
