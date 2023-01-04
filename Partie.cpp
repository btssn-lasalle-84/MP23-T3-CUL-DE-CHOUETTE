#include "Partie.h"

Partie::Partie() : objectifNombre(OBJECTIF_PAR_DEFAUT), difficulte(DIFFICULTE_PAR_DEFAUT), nombreDeJoueurs(NB_JOUEURS_PAR_DEFAUT), numeroDeTour(0)
{
}

Partie::Partie(int nombreDeJoueurs, unsigned int difficulte, int objectifNombre) : nombreDeJoueurs(nombreDeJoueurs),
                                                                                   objectifNombre(objectifNombre),
                                                                                   difficulte(difficulte),
                                                                                   numeroDeTour(0)
{
}