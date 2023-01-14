#include "Partie.h"
#include "Joueur.h"
#include "Ihm.h"
#include <iostream>

Partie::Partie(unsigned int nombreDeJoueurs /*= NB_JOUEURS_PAR_DEFAUT*/,
               Difficulte   difficulte /*= Difficulte::Normal*/,
               unsigned int nombreVictoire /*= NOMBRE_VICTOIRE_PAR_DEFAUT*/) :
    nombreDeJoueurs(nombreDeJoueurs),
    nombreAAtteindre(nombreAAtteindre), difficulte(difficulte), numeroDeTour(0),
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

    std::vector<unsigned int> valeursDesQuiCommence;
    unsigned int tampon1;
    unsigned int tampon2;
    for(std::list<Joueur*>::iterator joueur = joueurs.begin();
        joueur != joueurs.end();
        joueur++)
    {
        ihm->afficherLanceDes((*joueur)->getNomJoueur());
        (*joueur)->lancerUnDe();
        ihm->afficherUnDe((*joueur)->getPremierDe());
        (*joueur)->setScore((*joueur)->getPremierDe());
        valeursDesQuiCommence.push_back((*joueur)->getPremierDe());        
    }                
    for (unsigned int i = 0; i < valeursDesQuiCommence.size(); i++)
    {
        if (valeursDesQuiCommence[0] < valeursDesQuiCommence[1])
        {
            tampon1 = valeursDesQuiCommence[0];
        }
        else
        {
            tampon2 = valeursDesQuiCommence[0];
        }
    } 
        bool partieNonTerminee = true;
        while(partieNonTerminee)
        {
            if (tampon1 < tampon2)
            {
                for(std::list<Joueur*>::iterator joueur = joueurs.begin();
                joueur != joueurs.end();
                joueur++)
                {
                    std::cout << (*joueur)->getNomJoueur() <<" commence\n" << std::endl;
                    ihm->afficherLanceDes((*joueur)->getNomJoueur());
                    (*joueur)->lancerDes();
                    ihm->afficherLesDes((*joueur)->getPremierDe(),
                    (*joueur)->getDeuxiemeDe(),
                    (*joueur)->getTroisiemeDe());
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

            else
            {
                for(std::list<Joueur*>::reverse_iterator joueur = joueurs.rbegin();
                joueur != joueurs.rend();
                joueur++)
                {
                    std::cout << (*joueur)->getNomJoueur() <<" commence\n" << std::endl;
                    ihm->afficherLanceDes((*joueur)->getNomJoueur());
                    (*joueur)->lancerDes();
                    ihm->afficherLesDes((*joueur)->getPremierDe(),
                    (*joueur)->getDeuxiemeDe(),
                    (*joueur)->getTroisiemeDe());
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
}

bool Partie::aGagne(unsigned int const& score)
{
    for(std::list<Joueur*>::iterator joueur = joueurs.begin();
        joueur != joueurs.end();
        joueur++)
    {
        if(score > NOMBRE_VICTOIRE_PAR_DEFAUT)
        {
            return false;
        }
    }
    return true;
}

unsigned int Partie::getNombreAAtteindre() const
{
    return nombreAAtteindre;
}

unsigned int Partie::getNumeroDeTour() const
{
    return numeroDeTour;
}
