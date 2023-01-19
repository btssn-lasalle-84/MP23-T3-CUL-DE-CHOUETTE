#include "Joueur.h"
#include "De.h"
#ifdef DEBUG_JOUEUR
#include <iostream>
#endif
#include <cmath>

Joueur::Joueur(const std::string& nomDuJoueur) :
    nomDuJoueur(nomDuJoueur), scoreLance(0), compteurDePoints(NOMBRE_DE_POINTS)
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

void Joueur::setNomduJoueur(const std::string& nomDuJoueur)
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
        std::cout << __PRETTY_FUNCTION__
                  << "valeur Dé : " << this->des[i]->getValeurDe() << std::endl;
    }

#endif
}

void Joueur::lancerDe()
{
    des[0]->lancerDe();
}

unsigned int Joueur::getDes(int numeroDe) const
{
    return des[numeroDe]->getValeurDe();
}

void Joueur::trierDes()
{
    for(size_t i = 0; i < des.size(); i++)
    {
        for(size_t j = i + 1; j < des.size(); j++)
        {
            if(des[j]->getValeurDe() < des[i]->getValeurDe())
            {
                unsigned int tampon = des[i]->getValeurDe();
                des[i]->setDe(des[j]->getValeurDe());
                des[j]->setDe(tampon);
            }
        }
    }
}

unsigned int Joueur::getScorelance() const
{
    return this->scoreLance;
}

TypeCombinaison Joueur::identifierCombinaison()
{
    this->scoreLance = 0;
    this->trierDes();
    if(identifierCombinaisonCulDeChouette())
        return TypeCombinaison::CulDeChouette;
    else if(identifierCombinaisonSuite())
        return TypeCombinaison::Suite;
    else if(identifierCombinaisonVelute())
        return TypeCombinaison::Velute;
    else if(identifierCombinaisonChouette())
        return TypeCombinaison::Chouette;
    else
    {
        this->scoreLance =
          (this->des[0]->getValeurDe() + this->des[1]->getValeurDe() +
           this->des[2]->getValeurDe());
        this->compteurDePoints +=
          (this->des[0]->getValeurDe() + this->des[1]->getValeurDe() +
           this->des[2]->getValeurDe());
        return TypeCombinaison::Aucune;
    }
}

bool Joueur::identifierCombinaisonChouette()
{
    if(this->des[1]->getValeurDe() == this->des[0]->getValeurDe() ||
       this->des[1]->getValeurDe() == this->des[2]->getValeurDe())
    {
        this->scoreLance = (pow(this->des[1]->getValeurDe(), 2) + 10);
        this->compteurDePoints += (pow(this->des[1]->getValeurDe(), 2) + 10);
        return true;
    }
    return false;
}

bool Joueur::identifierCombinaisonVelute()
{
    if((this->des[0]->getValeurDe() + this->des[1]->getValeurDe()) ==
       this->des[2]->getValeurDe())
    {
        this->scoreLance = pow(this->des[2]->getValeurDe(), 2) * 2;
        this->compteurDePoints += (pow(this->des[2]->getValeurDe(), 2) * 2);
        return true;
    }
    return false;
}

bool Joueur::identifierCombinaisonCulDeChouette()
{
    if(this->des[0]->getValeurDe() == this->des[1]->getValeurDe() &&
       this->des[0]->getValeurDe() == this->des[2]->getValeurDe())
    {
        this->scoreLance = (40 + 10 * this->des[0]->getValeurDe());
        this->compteurDePoints += (40 + 10 * this->des[0]->getValeurDe());
        return true;
    }
    return false;
}

bool Joueur::identifierCombinaisonSuite()
{
    if(this->des[1]->getValeurDe() == (this->des[0]->getValeurDe() + 1) &&
       this->des[2]->getValeurDe() == (this->des[1]->getValeurDe() + 1))
    {
        this->scoreLance = (5 * this->des[2]->getValeurDe());
        this->compteurDePoints += (5 * this->des[2]->getValeurDe());
        return true;
    }
    return false;
}