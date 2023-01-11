#include "Ihm.h"
#include "Partie.h"
#include "Joueur.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>

Ihm::Ihm()
{
}

Ihm::~Ihm()
{
}

void Ihm::afficherRegle() const
{
    std::cout << std::setfill('-') << std::setw(10) << std::endl
              << "LE CUL DE CHOUETTE\n"
              << std::endl

              << "== Le jeu ==\n"
              << std::endl

              << "Le Cul De Chouette se joue avec trois dés, Le but du jeu est "
                 "d'atteindre le premier 343 points, en formant différentes "
                 "combinaisons, chacun à son tour de jeu.\n"
              << std::endl;
    sleep(VITESSE_DEFILEMENT_TEXTE);

    std::cout << "== Démarrage ==\n"
              << std::endl

              << "Chaque joueur lance 1 dé, le joueur qui a fait le plus petit "
                 "score commence. "
                 "S'il y a plusieurs joueurs qui ont fait le plus petit score, "
                 "ils recommencent pour se départager. "
                 "Le tour de jeu s'effectue ensuite dans le sens inverse des "
                 "aiguilles d'une montre.\n"
              << std::endl;
    sleep(VITESSE_DEFILEMENT_TEXTE);

    std::cout
      << "== Déroulement du jeu ==\n"
      << std::endl

      << "À son tour de jeu, le joueur lance d’abord 2 dés (les Chouettes), "
         "puis le 3e dé (le Cul). "
         "On applique alors la règle correspondant à la combinaison formée par "
         "les trois dés(cf.ci - dessous), "
         "sans tenir compte de l'ordre dans lequel les dés ont été tirés. "
         "On peut lancer les trois dés d'un coup pour aller plus vite "
         "et les règles de l'Achat de Dé et de la Banque ne s'appliquent pas "
         "lors de la partie.\n"
      << std::endl;
    sleep(VITESSE_DEFILEMENT_TEXTE);

    std::cout
      << "== Les combinaisons ==\n"
      << std::endl

      << "* La Chouette : 2 dés identiques"

         "La Chouette a pour valeur le chiffre des deux dés identiques. "
         "Le joueur qui a lancé les dés gagne les points correspondant au "
         "carré de la Chouette : "

         "Chouette de 1 = 1 pt, de 2 = 4 pts, "
         "de 3 = 9 pts,"
         "de 4 = 16 pts,"
         "de 5 = 25 pts,"
         "de 6 = 36 pts.\n"
      << std::endl;
    sleep(VITESSE_DEFILEMENT_TEXTE);

    std::cout
      << "* La Velute : la somme de 2 dés = le 3e dé "

         "La Velute a pour valeur le chiffre du 3e dé. "
         "Le joueur qui a lancé les dés gagne les points correspondant au "
         "double du carré de la Velute :"

         "Velute de 2 = 8 pts, de 3 = 18 pts, de 4 = 32 pts, de 5 = 50 pts, "
         "de 6 = 72 pts.\n"
      << std::endl

      << "* Le Cul de Chouette : 3 dés identiques "

         "Le Cul de Chouette a pour valeur le chiffre des trois dés "
         "identiques. "
         "Le joueur qui a lancé les dés gagne en points 40 + 10 * (le Cul de "
         "Chouette) : "

         "CDC de 1 = 50 pts, "
         "de 2 = 60 pts, "
         "de 3 = 70 pts, "
         "de 4 = 80 pts, "
         "de 5 = 90 pts, "
         "de 6 = 100 pts.\n"

      << std::endl;
    sleep(VITESSE_DEFILEMENT_TEXTE);

    std::cout
      << "== Fin du jeu ==\n"
      << std::endl

      << "Lorsqu'un joueur atteint 343 points (ou plus), il est déclaré "
         "gagnant (le score peut passer dans le négatif, "
         "mais on considèrera qu'un joueur ayant atteint -343 points devra "
         "sortir du jeu, il est impossible de miser (pari sur Sirotage, "
         "application d'un Civet, ...) "
         "avec un score négatif ou nul).\n"
      << std::endl;
    sleep(VITESSE_DEFILEMENT_TEXTE);
    std::cout << std::setfill('-') << std::setw(10) << std::endl;
}

void Ihm::afficherMenuPrincipal() const
{
    std::cout << "-----Bienvenue sur le jeu du CulDeChouette !-----\n "
              << std::endl;
    int choix;
    do
    {
        std::cout << " Pouvons nous commencez ? "
                     "Si vous êtes prêt, Entrez (1), si vous voulez "
                     "les règles, Entrez (2)"
                  << std::endl
                  << "Votre réponse : " << std::endl;
        std::cin >> choix;

        switch(choix)
        {
            case 2:
                afficherRegle();
                break;
            default:
                std::cout << "Démarrage..." << std::endl;
                break;
        }
    } while(choix != 1);
    sleep(VITESSE_DEFILEMENT_TEXTE);
}

std::string Ihm::rentrerNomDuJoueur() const
{
    std::string nomDuJoueur;
    std::cout << "Entrez le nom du joueur" << std::endl;
    std::cin >> nomDuJoueur;
    return nomDuJoueur;
}

std::string Ihm::afficherNomDuJoueur(std::string nomDujoueur) const
{
    std::cout << nomDujoueur << std::endl;
}

void Ihm::afficherLanceDes(std::string const nomDuJoueur) const
{
    std::cout << nomDuJoueur << " lance les dès !" << std::endl;
}

void Ihm::afficherScoreTotal(std::string  nomDujoueur,
                             unsigned int scoreTotal) const
{
    std::cout << "le score de " << nomDujoueur << " est de : " << scoreTotal
              << std::endl;
}

void Ihm::afficherCombinaison(TypeCombinaison combinaison) const
{
    std::string nomCombinaison;
    switch(combinaison)
    {
        case 0:
            nomCombinaison = "Chouette";
            break;
        case 1:
            nomCombinaison = "Velute";
            break;
        case 2:
            nomCombinaison = "CulDeChouette";
            break;
        case 3:
            nomCombinaison = "Aucune";
            break;

        default:
            break;
    }
    std::cout << "La combinaison réalisé est : " << nomCombinaison << std::endl;
}

void Ihm::afficherScoreDuJoueur(const Joueur& joueur) const
{
    std::cout << joueur.getScore();
}

void Ihm::afficherLesDes(unsigned int des0,
                         unsigned int des1,
                         unsigned int des2)
{
    std::cout << "dé numero " << 1 << " = " << des0 << std::endl;
    std::cout << "dé numero " << 2 << " = " << des1 << std::endl;
    std::cout << "dé numero " << 3 << " = " << des2 << std::endl;
}