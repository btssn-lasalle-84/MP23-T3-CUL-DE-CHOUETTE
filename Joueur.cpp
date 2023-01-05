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

void Joueur::setScore()
{
    for(size_t i = 0; i < des.size(); i++)
    {
        this->des[i]->lancerDe();
        /*chouette*/
        if(des[0]->getValeurDe() == des[1]->getValeurDe())
        {
            int tamponChouette = pow(des[0]->getValeurDe(), 2);
        }
        else if(des[0]->getValeurDe() == des[2]->getValeurDe())
        {
            int tamponChouette = pow(des[0]->getValeurDe(), 2);
        }
        else if(des[1]->getValeurDe() == des[2]->getValeurDe())
        {
            int tamponChouette = pow(des[1]->getValeurDe(), 2);
        }
        /*velute*/
    }
}

void Joueur::setNomduJoueur(std::string nomDuJoueur)
{
    this->nomDuJoueur = nomDuJoueur;
}