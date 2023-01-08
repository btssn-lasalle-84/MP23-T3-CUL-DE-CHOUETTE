#include "Partie.h"
#include "Joueur.h"
#include "Ihm.h"
#include <iostream>

Partie::Partie(unsigned int nombreDeJoueurs /*= NB_JOUEURS_PAR_DEFAUT*/,
               Difficulte   difficulte /*= Difficulte::Normal*/,
               int          objectifNombre /*= OBJECTIF_PAR_DEFAUT*/) :
    nombreDeJoueurs(nombreDeJoueurs),
    objectifNombre(objectifNombre), difficulte(difficulte), numeroDeTour(0),
    ihm(new Ihm())
{
    for(size_t i = 0; i < nombreDeJoueurs; i++)
    {
        joueurs.push_back(new Joueur());
    }
}

Partie::~Partie()
{
    for(std::list<Joueur*>::iterator joueur = joueurs.begin();
        joueur != joueurs.end();
        joueur++)
    {
        delete *joueur;
    }
    delete ihm;
}

void Partie::jouer()
{
    for(std::list<Joueur*>::iterator joueur = joueurs.begin();
        joueur != joueurs.end();
        joueur++)
    {
#ifdef DEBUG_PARTIE
        std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__
                  << " Joueur = " << *joueur << std::endl;
#endif
        (*joueur)->lancerDes();
#ifdef DEBUG_PARTIE
        std::cout << __PRETTY_FUNCTION__ <<  " ligne n° " << __LINE__ <<" combinaison n° "<<(*joueur)->identifierCombinaison()<< " score : "  << (*joueur)->getScore()<< std::endl;
#endif
    }
}