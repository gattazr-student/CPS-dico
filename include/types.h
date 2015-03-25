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
typedef uint32_t maillon_t;

/* Liste de maillon toutes les lettres d'un mot */
typedef struct lLettres{
	maillon_t  pMaillon;
	maillon_t *pNext;
} lLettres_t;

/* Mot du dictionnaire */
typedef struct mot{
	lLettres_t *pTeteMot;
	lLettres_t *pQueueMote;
	lEmplacement_t *pTeteListe;
	lEmplacement_t *pQueueListe;
} mot_t;

/* Dictionnaire */
typedef struct dictionnaire{
	mot_t pMot;
	struct dictionnaire *pNext;
} t_dictionnaire;
