#include "Partie.h"
#include "Joueur.h"
#include "Ihm.h"
#include <iostream>

Partie::Partie(unsigned int nombreDeJoueurs /*= NB_JOUEURS_PAR_DEFAUT*/,
               Difficulte   difficulte /*= Difficulte::Normal*/,
               unsigned int objectifNombre /*= OBJECTIF_PAR_DEFAUT*/) :
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
    ihm->afficherMenuPrincipal();
    for(std::list<Joueur*>::iterator joueur = joueurs.begin();
        joueur != joueurs.end();
        joueur++)
    {
        (*joueur)->setNomduJoueur(ihm->rentrerNomDuJoueur());
    }

    bool partieNonTerminee = true;
    while(partieNonTerminee)
    {
        for(std::list<Joueur*>::iterator joueur = joueurs.begin();
            joueur != joueurs.end();
            joueur++)
        {
            ihm->afficherLanceDes((*joueur)->getNomJoueur());
            (*joueur)->lancerDes();
            ihm->afficherLesDes((*joueur)->getDes0(),
                                (*joueur)->getDes1(),
                                (*joueur)->getDes2());
            ihm->afficherCombinaison((*joueur)->identifierCombinaison());
            ihm->afficherScoreTotal((*joueur)->getNomJoueur(),
                                    (*joueur)->getScore());
#ifdef DEBUG_PARTIE
            std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__
                      << " Joueur = " << *joueur << std::endl;
#endif
#ifdef DEBUG_PARTIE
            std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__
                      << " score : " << (*joueur)->getScore() << std::endl;
#endif
            this->numeroDeTour += 1;
            partieNonTerminee = this->aGagne((*joueur)->getScore());
            if(partieNonTerminee == false)
            {
                ihm->afficherGagnant((*joueur)->getNomJoueur(),
                                     this->numeroDeTour);
                break;
            }
        }
    }
}

bool Partie::aGagne(unsigned int const& score)
{
    for(std::list<Joueur*>::iterator joueur = joueurs.begin();
        joueur != joueurs.end();
        joueur++)
    {
        if(score > OBJECTIF_PAR_DEFAUT)
        {
            return false;
        }
    }
    return true;
}

unsigned int Partie::getObjectifNombre() const
{
    return objectifNombre;
}

unsigned int Partie::getNumeroDeTour() const
{
    return numeroDeTour;
}