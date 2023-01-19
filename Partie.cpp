#include "Partie.h"
#include "Joueur.h"
#include "Ihm.h"
#ifdef DEBUG_PARTIE
#include <iostream>
#endif

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
    do
    {
        ihm->afficherMenuPrincipal();
        for(std::list<Joueur*>::iterator joueur = joueurs.begin();
            joueur != joueurs.end();
            joueur++)
        {
            (*joueur)->setNomduJoueur(ihm->rentrerNomDuJoueur());
        }
        quiCommence();
    } while(CONSTANTE_BOUCLE_INFINI);
}

void Partie::quiCommence()
{
    std::vector<int> tamponJoueur;

    for(std::list<Joueur*>::iterator joueur = joueurs.begin();
        joueur != joueurs.end();
        joueur++)
    {
        (*joueur)->lancerDe();
        ihm->afficherQuiLance((*joueur)->getNomJoueur());
        ihm->afficherLanceDe((*joueur)->getDes(0));
        tamponJoueur.push_back((*joueur)->getDes(0));
    }

    while(tamponJoueur[0] == tamponJoueur[1])
    {
        tamponJoueur.erase(tamponJoueur.begin(), tamponJoueur.begin() + 2);

        for(std::list<Joueur*>::iterator joueur = joueurs.begin();
            joueur != joueurs.end();
            joueur++)
        {
            (*joueur)->lancerDe();
            ihm->afficherQuiLance((*joueur)->getNomJoueur());
            ihm->afficherLanceDe((*joueur)->getDes(0));
            tamponJoueur.push_back((*joueur)->getDes(0));
        }
    }

    if(tamponJoueur[0] < tamponJoueur[1])
    {
        joueur1Commence();
    }

    else
    {
        joueur2Commence();
    }
}

bool Partie::aGagne(unsigned int const& score)
{
    if(score >= OBJECTIF_PAR_DEFAUT)
    {
        return true;
    }
    return false;
}

void Partie::joueur1Commence()
{
    bool partieTerminee = false;
    while(!partieTerminee)
    {
        for(std::list<Joueur*>::iterator joueur = joueurs.begin();
            joueur != joueurs.end();
            joueur++)
        {
            ihm->afficherQuiLance((*joueur)->getNomJoueur());
            (*joueur)->lancerDes();
            ihm->afficherLesDes((*joueur)->getDes(0),
                                (*joueur)->getDes(1),
                                (*joueur)->getDes(2));
            ihm->afficherCombinaison((*joueur)->identifierCombinaison());
            ihm->afficherScoreTotal((*joueur)->getNomJoueur(),
                                    (*joueur)->getScore(),
                                    (*joueur)->getScoreLance());
#ifdef DEBUG_PARTIE
            std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__
                      << " Joueur = " << *joueur << std::endl;
#endif
#ifdef DEBUG_PARTIE
            std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__
                      << " score : " << (*joueur)->getScore() << std::endl;
#endif
            this->numeroDeTour += 1;
            partieTerminee = this->aGagne((*joueur)->getScore());
            if(partieTerminee)
            {
                ihm->afficherGagnant((*joueur)->getNomJoueur(),
                                     this->numeroDeTour,
                                     (*joueur)->getScore());
                break;
            }
        }
    }
}

void Partie::joueur2Commence()
{
    bool partieTerminee = false;
    while(!partieTerminee)
    {
        for(std::list<Joueur*>::reverse_iterator joueur = joueurs.rbegin();
            joueur != joueurs.rend();
            joueur++)
        {
            ihm->afficherQuiLance((*joueur)->getNomJoueur());
            (*joueur)->lancerDes();
            ihm->afficherLesDes((*joueur)->getDes(0),
                                (*joueur)->getDes(1),
                                (*joueur)->getDes(2));
            ihm->afficherCombinaison((*joueur)->identifierCombinaison());
            ihm->afficherScoreTotal((*joueur)->getNomJoueur(),
                                    (*joueur)->getScore(),
                                    (*joueur)->getScoreLance());
#ifdef DEBUG_PARTIE
            std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__
                      << " Joueur = " << *joueur << std::endl;
#endif
#ifdef DEBUG_PARTIE
            std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__
                      << " score : " << (*joueur)->getScore() << std::endl;
#endif
            this->numeroDeTour += 1;
            partieTerminee = this->aGagne((*joueur)->getScore());
            if(partieTerminee)
            {
                ihm->afficherGagnant((*joueur)->getNomJoueur(),
                                     this->numeroDeTour,
                                     (*joueur)->getScoreLance());
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