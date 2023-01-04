#include "Partie.h"

Partie::Partie() : objectifNombre(OBJECTIF_PAR_DEFAUT), difficulteDeLaPartie(normal), nombreDeJoueurs(NB_JOUEURS_PAR_DEFAUT), numeroDeTour(0)
{
}

Partie::Partie(int nombreDeJoueurs, difficulte difficulteDeLaPartie , int objectifNombre) : nombreDeJoueurs(nombreDeJoueurs),
                                                                                   objectifNombre(objectifNombre),
                                                                                   difficulteDeLaPartie(difficulteDeLaPartie),
                                                                                   numeroDeTour(0)
{
}