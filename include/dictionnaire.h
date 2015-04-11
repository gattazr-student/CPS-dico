
dictionnaire_t* make_dico();

void inserer_dico (dictionnaire_t **dico, char *mot, int *nb_l, int *nb_c); // que penses tu de la spécification ?

void liberer_dico (dictionnaire_t *tete);

void afficher_dico (dictionnaire_t *dico);
