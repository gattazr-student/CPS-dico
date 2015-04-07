#include <stdlib.h>
#include "types.h"

#define TAILLE_LETTRE 5 /* COMENTAIRE : USE GLOBAL */

/* @Invariant : 0<= num <= sizeof(maillon_t)/TAILLE_LETTRE */

void set_charnum (maillon_t *maillon, int num, uint8_t l){
	int nb_lettre = sizeof(maillon_t)/TAILLE_LETTRE; /* COMENTAIRE : USE GLOBAL */
	maillon_t mask = 0x1F; /* COMENTAIRE : USE GLOBAL */
	maillon_t charnum = (maillon_t)l;
	
	/* On décale le masque à la bonne place */
	mask <<= (TAILLE_LETTRE * (nb_lettre - num)); /* COMENTAIRE : USE GLOBAL */
	charnum = charnum << (TAILLE_LETTRE * (nb_lettre - num)); /* COMENTAIRE : USE GLOBAL */
	/* inversion du mask pour faire une initialisation avant l'écriture */
	mask = ~mask;
	*maillon = *maillon & mask;
	*maillon = *maillon | charnum;
}

uint8_t get_charnum (maillon_t *maillon, int num){
	int nb_lettre = sizeof(maillon_t)/TAILLE_LETTRE; /* COMENTAIRE : USE GLOBAL */
	maillon_t mask = 0x1F; /* COMENTAIRE : USE GLOBAL */
	
	mask <<= (TAILLE_LETTRE * (nb_lettre - num)); /* COMENTAIRE : USE GLOBAL */
	mask = *maillon & mask;
	/* On décale le masque vers le bits de poids faibles pour le cast */
	while(num!=nb_lettre){ /* COMENTAIRE : USE GLOBAL */
		mask >>= nb_lettre; /* COMENTAIRE : USE GLOBAL */
		num++;
	}
	return (uint8_t)mask;
}
