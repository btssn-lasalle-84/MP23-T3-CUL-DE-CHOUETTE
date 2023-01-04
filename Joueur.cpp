#include "Joueur.h"
#include "De.h"

Joueur::Joueur(std::string nomDuJoueur) :
    nomDuJoueur(nomDuJoueur), des(NOMBRE_DE_DES, new De()),
    compteurDePoints(NOMBRE_DE_POINTS)
{
}
