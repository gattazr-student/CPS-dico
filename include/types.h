#include <stdint.h>

/* Emplacement d'un mot */
typedef struct emplacement {
	unsigned int pLigne;
	unsigned int pColonne;
} emplacement_t;

/* Liste de d'emplacements */
typedef struct lEmplacement{
	emplacement_t pPos;
	struct lEmplacement *pNext;
} lEmplacement_t;

/* Maillon contenant les lettres d'un mot */
#ifdef INT8
typedef uint8_t maillon_t;
#elif INT16
typedef uint16_t maillon_t;
#elif INT64
typedef uint64_t maillon_t;
#else
typedef uint32_t maillon_t;
#endif

/* Liste de maillon toutes les lettres d'un mot */
typedef struct lLettres{
	maillon_t  pMaillon;
	struct lLettres *pNext;
} lLettres_t;

/* Mot du dictionnaire */
typedef struct mot{
	lLettres_t *pTeteMot;
	lLettres_t *pQueueMot;
	lEmplacement_t *pTeteListe;
	lEmplacement_t *pQueueListe;
} mot_t;

/* Dictionnaire */
typedef struct dictionnaire{
	mot_t *pMot;
	struct dictionnaire *pNext;
} dictionnaire_t;
