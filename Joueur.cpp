#include "Joueur.h"
#include "De.h"

#ifdef DEBUG_JOUEUR
#include <iostream>
#endif
#include <algorithm>
#include <cmath>

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

TypeCombinaison Joueur::identifierCombinaison()
{
    if(identifierCombinaisonChouette())
        return TypeCombinaison::Chouette;
    else if(identifierCombinaisonVelute())
        return TypeCombinaison::Velute;
    else if(identifierCombinaisonCulDeChouette())
        return TypeCombinaison::CulDeChouette;
    else if(identifierCombinaisonSuite())
        return TypeCombinaison::Suite;
    else
        return TypeCombinaison::Aucune;
}

bool Joueur::identifierCombinaisonChouette()
{
    std::sort(des.begin(), des.end());

    if(this->des[0]->getValeurDe() == this->des[1]->getValeurDe())
    {
        return true;
    }
    else if(this->des[1]->getValeurDe() == this->des[2]->getValeurDe())
    {
        return true;
    }
    else if(this->des[2]->getValeurDe() == this->des[0]->getValeurDe())
    {
        return true;
    }
    return false;
}

bool Joueur::identifierCombinaisonVelute()
{
    if(this->des[0]->getValeurDe() + this->des[1]->getValeurDe() ==
       this->des[2]->getValeurDe())
    {
        return true;
    }
    else if(this->des[1]->getValeurDe() + this->des[2]->getValeurDe() ==
            this->des[0]->getValeurDe())
    {
        return true;
    }
    else if(this->des[2]->getValeurDe() == this->des[0]->getValeurDe() ==
            this->des[1]->getValeurDe())
    {
        return true;
    }
    return false;
}

bool Joueur::identifierCombinaisonCulDeChouette()
{
    if(this->des[0]->getValeurDe() == this->des[1]->getValeurDe() &&
       this->des[0]->getValeurDe() == this->des[2]->getValeurDe())
    {
        return true;
    }
    return false;
}