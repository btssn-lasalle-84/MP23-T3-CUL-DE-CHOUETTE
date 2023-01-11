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

    bool partieTerminee = true;
    while(partieTerminee)
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
            if((*joueur)->getScore() >= OBJECTIF_PAR_DEFAUT)
            {
                ihm->afficherGagnant((*joueur)->getNomJoueur());
                partieTerminee = false;
                break;
            }
        }
    }
}

unsigned int Partie::getObjectifNombre() const
{
    return objectifNombre;
}

unsigned int Partie::getNumeroDeTour() const
{
    return numeroDeTour;
}