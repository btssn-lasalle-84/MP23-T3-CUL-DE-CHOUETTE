#include "Joueur.h"
#include "De.h"

#ifdef DEBUG_JOUEUR
#include <iostream>
#endif

Joueur::Joueur(std::string nomDuJoueur) :
    nomDuJoueur(nomDuJoueur), compteurDePoints(NOMBRE_DE_POINTS)
{
#ifdef DEBUG_JOUEUR
    std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__ << " " << this
              << std::endl;
#endif
    for(size_t i = 0; i < NOMBRE_DE_DES; i++)
    {
        des.push_back(new De());
    }
}

Joueur::~Joueur()
{
    for(size_t i = 0; i < des.size(); i++)
    {
        delete des[i];
    }
#ifdef DEBUG_JOUEUR
    std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__ << " " << this
              << std::endl;
#endif
}

unsigned int Joueur::getScore() const
{
    return this->compteurDePoints;
}

void Joueur::setScore()
{
}

std::string Joueur::getNomJoueur() const
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
#ifdef DEBUG_JOUEUR
    for(size_t i = 0; i < des.size(); i++)
    {
        this->des[i]->getValeurDe();
    }
#endif
}
