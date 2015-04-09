
int compare_mots(char* aWord, mot_t* aMot);

mot_t* make_mot(char* aWord, int aLigne, int aColonne);

void update_mot(mot_t* aMot, int aLigne, int aColonne);

void afficher_mot (mot_t *mot);

void liberer_mot (mot_t *mot);
