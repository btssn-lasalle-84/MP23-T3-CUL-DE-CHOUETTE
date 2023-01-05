#include "Joueur.h"
#include "De.h"

Joueur::Joueur(std::string nomDuJoueur) :
    nomDuJoueur(nomDuJoueur), des(NOMBRE_DE_DES, new De()),
    compteurDePoints(NOMBRE_DE_POINTS)
{
}

unsigned int const Joueur::getScore()
{
    return this->compteurDePoints;
}

std::string const Joueur::getNomJoueur()
{
    return this->nomDuJoueur;
}

void Joueur::setNomduJoueur(std::string const nomDuJoueur)
{
    this->nomDuJoueur = nomDuJoueur;
}

void Joueur::lancerDes()
{
    for(size_t i = 0; i < des.size(); i++)
    {
        des[i]->lancerDe();
    }
}