
dictionnaire_t* make_dico();

void inserer_mot_dico (dictionnaire_t **dico, char *mot, int nb_l, int nb_c);

void liberer_dico (dictionnaire_t *tete);

void afficher_dico (dictionnaire_t *dico);

void afficher_maillons_dico (dictionnaire_t *dico);
