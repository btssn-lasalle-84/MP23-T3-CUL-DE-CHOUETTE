#include "Partie.h"
#include "Joueur.h"
#include "Ihm.h"

Partie::Partie(int        nombreDeJoueurs /*= NB_JOUEURS_PAR_DEFAUT*/,
               Difficulte difficulte /*= Difficulte::Normal*/,
               int        objectifNombre /*= OBJECTIF_PAR_DEFAUT*/) :
    nombreDeJoueurs(nombreDeJoueurs),
    objectifNombre(objectifNombre), difficulte(difficulte), numeroDeTour(0),
    joueurs(nombreDeJoueurs, new Joueur()), ihm(new Ihm())
{
}

Partie::~Partie()
{
    // delete joueurs !!!
    delete ihm;
}