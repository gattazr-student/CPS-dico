
void set_charnum (maillon_t *maillon, int num, uint8_t l);

uint8_t get_charnum (maillon_t *maillon, int num);

uint8_t char_to_num (char aChar);

char num_to_char (uint8_t aNum);

/* Nombre de bits utilisés pour stocker 1 lettre dans un maillon */
#define TAILLE_LETTRE 5

#ifndef MAILLON_SRC
	extern int NB_LETTRES_MAILLON;
#endif
