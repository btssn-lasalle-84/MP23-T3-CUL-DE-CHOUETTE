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
              << "LE CUL DE CHOUETTE -- version 1.0\n"
              << std::endl;
        std::cout << R"(
-----------------------------------------------------------------------------------------------------------------------------------------------------

                                                                Déroulement du jeu

-----------------------------------------------------------------------------------------------------------------------------------------------------

Le but du jeu est d'atteindre ou dépasser 343 points en réalisant différentes combinaisons et en relevant différents défis, chacun à son tour de jeu.

Le score à atteindre (343 points) provient des initiales du nom du jeu : C-D-C, soit les 3e, 4e et 3e lettres de l'alphabet.

Les règles ont été divisées en deux catégories : les combinaisons d'une part, les actions et défis de l'autre,
et ne sont donc pas classées par niveau de difficulté.

Le système d'étoiles mis en place dans le sommaire est donc une indication permettant d'apprendre les règles par étapes,
et il est conseillé de maîtriser toutes les règles d'un niveau avant de passer au niveau suivant, les niveaux allant d'une étoile à quatre étoiles.

Il est cependant tout à fait possible de jouer en ne maîtrisant les règles que d'un niveau.

Chaque joueur lance un dé, celui qui fait le plus petit score commence. Si plusieurs joueurs ont fait le plus petit score,
ils recommencent pour se départager. Le tour de jeu s'effectue ensuite dans le sens inverse des aiguilles d'une montre.

À son tour de jeu, le joueur lance deux dés (les chouettes), puis le troisième (le cul).

On applique alors la règle correspondant à la combinaison formée par les trois dés, sans tenir compte de l'ordre dans lequel les dés ont été tirés.

Sauf cas particulier, le joueur lançant les dés remporte les points de la combinaison réalisée.

-----------------------------------------------------------------------------------------------------------------------------------------------------

                                                                Les combinaisons

-----------------------------------------------------------------------------------------------------------------------------------------------------

La Chouette : Deux dés identiques

La Chouette a pour valeur le chiffre des deux dés identiques.

La valeur de la Chouette correspond au carré de la Chouette :

    1. 1 pt
    2. 4 pts
    3. 9 pts
    4. 16 pts
    5. 25 pts
    6. 36 pts

La Velute : La somme de deux dés est égale à la valeur du troisième dé

La Velute a pour valeur le chiffre le plus élevé des trois.

La valeur de la Velute correspond au double du carré de la Velute :

    1. 8 pts (seulement pour une Chouette Velute)
    2. 18 pts
    3. 32 pts
    4. 50 pts
    5. 72 pts

Attention, la combinaison 1, 2, 3 est à première vue une suite, et bien que la règle de la suite soit applicable, c'est également une Velute (1+2 = 3).

La Chouette Velute : Une Chouette + une Velute

La Chouette Velute a la valeur de sa Velute. Le premier joueur qui frappe dans ses mains en criant “Pas mou le caillou!” gagne les points de la Chouette Velute.

Si plusieurs joueurs sont à égalité lors de l'annonce, alors les points de la Chouette Velute sont soustraits des scores des joueurs concernés.
Le Cul de Chouette : trois dés identiques

La valeur du Cul de Chouette correspond à 40 pts + 10* la valeur du Cul de Chouette :

    1. 50 pts
    2. 60 pts
    3. 70 pts
    4. 80 pts
    5. 90 pts
    6. 100 pts

La Suite : trois dés qui se suivent

Tous les joueurs doivent taper du poing sur la table en criant “Grelotte ça picote!”. Le dernier joueur à le faire perd 10 pts.

En cas d'égalité, les joueurs concernés se départagent en criant “Sans fin est la moisissure des bières bretonnes!”.
S'il y a toujours égalité, les joueurs concernés se départagent en lançant chacun un dé, et celui qui aura fait le plus grand score perd les 10 pts.

Si un joueur annonce jusqu'à “bretonnes” sans qu'il n'y ait eu d'égalité, il y a Bévue.

S’il y a plusieurs joueurs qui ont fait le plus grand score, ils recommencent pour se départager, mais cette fois pour perdre 20 pts, puis 30 pts, etc.

)"<< std::endl;
}

void Ihm::afficherDifficulte() const
{
    std::cout << std::endl;
    std::cout
      << "Normal -> atteindre 343 points avec toutes les combinaisons activé"
      << std::endl
      << "Difficile -> atteindre 543 points. Pas de combinaison pas de points"
      << std::endl
      << "Extreme -> atteindre 543 points. Pas de combinaison pas de points, "
         "et la chouette est désactivé"
      << std::endl;
}

void Ihm::afficherMenuPrincipal() const
{
    std::cout << "-----Bienvenue sur le jeu du Cul De Chouette ! Version "
              << VERSION << "-----\n " << std::endl;
    int choix;
    do
    {
        std::cout << " Pouvons nous commencez ? \n" << std ::endl;
        std::cout << "Si vous êtes prêt à jouer, Entrez (1)" << std::endl;
        std::cout << "Si vous souhaitez quitter, Entrez (2)" << std::endl;
        std::cout << "Si vous souhaitez voir les règles, Entrez (3)"
                  << std::endl;
        std::cout << "Si vous voulez voir les difficulté, Entrez 4"
                  << std::endl;
        std::cout << "Votre réponse : ";
        std::cin >> choix;

        switch(choix)
        {
            case 4:
                afficherDifficulte();
                break;
            case 3:
                afficherRegle();
                break;
            case 2:
                exit(EXIT_SUCCESS);
                break;
            default:
                break;
        }
    } while(choix != 1);
}

std::string Ihm::rentrerNomDuJoueur() const
{
    std::string nomDuJoueur;
    std::cout << "\nEntrez le nom du joueur : ";
    std::cin >> nomDuJoueur;
    return nomDuJoueur;
}

void Ihm::afficherGagnant(const std::string& nomDujoueur,
                          unsigned int       nombreDeTour,
                          unsigned int       score) const
{
    std::cout << "Le gagnant est : " << nomDujoueur << " en " << nombreDeTour
              << " coups."
              << " Avec un score de : " << score << ", Bravo a lui ! \n"
              << std::endl;
}

void Ihm::afficherQuiLance(const std::string& nomDuJoueur) const
{
    std::cout << nomDuJoueur << " : C'est à votre tour !\n" << std::endl;
    if(nomDuJoueur != NOM_BOT)
    {
        int choix;
        do
        {
            std::cout << "Pour lancer les dés, appuyez sur (1) / Pour quittez, "
                         "appuyez sur (2) : ";
            std::cin >> choix;
            if(choix == 2)
            {
                std::cout << "Partie terminé !\n" << std::endl;
                sleep(VITESSE_DEFILEMENT_TEXTE);
                exit(EXIT_SUCCESS);
            }
        } while(choix != 1);
        std::cout << "\n" << nomDuJoueur << " lance les dès !\n" << std::endl;
    }

    else
    {
        sleep(VITESSE_DEFILEMENT_TEXTE);
        std::cout << "\n" << nomDuJoueur << " lance les dès !\n" << std::endl;
    }
}

void Ihm::afficherScoreTotal(const std::string& nomDujoueur,
                             unsigned int       scoreTotal,
                             unsigned int       scoreLance) const
{
    std::cout << "le score de ce lancé est de : " << scoreLance << std::endl
              << " le score total de " << nomDujoueur
              << " est de : " << scoreTotal << "\n"
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
            nomCombinaison = "Suite";
            break;
        case 3:
            nomCombinaison = "CulDeChouette";
            break;
        case 4:
            nomCombinaison = "Aucune";
            break;

        default:
            break;
    }
    std::cout << "La combinaison réalisée est : " << nomCombinaison << "\n"
              << std::endl;
}

void Ihm::afficherScoreDuJoueur(const Joueur& joueur) const
{
    std::cout << joueur.getScore();
}

void Ihm::afficherLesDes(unsigned int des0,
                         unsigned int des1,
                         unsigned int des2) const
{
    std::vector<unsigned int> lesDes;
    lesDes.push_back(des0);
    lesDes.push_back(des1);
    lesDes.push_back(des2);

    for(size_t i = 0; i < lesDes.size(); i++)
    {
        switch(lesDes[i])
        {
            case 1:
                std::cout << R"(
                                ______
                               /      /\
                              /   O  /O \
                             /_____ /    \
                             \O    O\    /
                              \O    O\ O/
                               \O____O\/
                                        )"<< std::endl;
                break;

            case 2:
                std::cout << R"(
                                ______
                              /     O/\
                             /      /  \
                            /O____ /    \
                            \O    O\  O /
                             \O    O\  /
                              \O____O\/
                                        )"<< std::endl;
                break;
            case 3:
                std::cout << R"(
                                ______
                               /     O/\
                              /   O  /O \
                             /O____ /    \
                             \O    O\    /
                              \O    O\ O/
                               \O____O\/
                                        )"<< std::endl;
                break;
            case 4:
                std::cout << R"(
                                ______
                               /O    O/\
                              /      /O \
                             /O____O/    \
                             \O    O\    /
                              \O    O\ O/
                               \O____O\/
                                        )"<< std::endl;
                break;
            case 5:
                std::cout << R"(
                                ______
                              /O    O/\
                             /   O  /O \
                            /O____O/    \
                            \O    O\    /
                             \O    O\ O/
                              \O____O\/
                                        )"<< std::endl;
                break;
            case 6:
                std::cout << R"(
                                ______
                               /O    O/\
                              /O    O/O \
                             /O____O/    \
                             \O    O\    /
                              \      \ O/
                               \O____O\/
                                        )"<< std::endl;
                break;
            default:
                break;
        }
        sleep(VITESSE_DEFILEMENT_TEXTE);
    }

    std::cout << "dé n° " << 1 << " = " << des0 << std::endl;
    std::cout << "dé n° " << 2 << " = " << des1 << std::endl;
    std::cout << "dé n° " << 3 << " = " << des2 << "\n" << std::endl;
}

void Ihm::afficherLanceDe(unsigned int de) const
{
    switch(de)
    {
        case 1:
                std::cout << R"(
                                ______
                               /      /\
                              /   O  /O \
                             /_____ /    \
                             \O    O\    /
                              \O    O\ O/
                               \O____O\/
                                        )"<< std::endl;
                break;

        case 2:
                std::cout << R"(
                                ______
                              /     O/\
                             /      /  \
                            /O____ /    \
                            \O    O\  O /
                             \O    O\  /
                              \O____O\/
                                        )"<< std::endl;
                break;
        case 3:
                std::cout << R"(
                                ______
                               /     O/\
                              /   O  /O \
                             /O____ /    \
                             \O    O\    /
                              \O    O\ O/
                               \O____O\/
                                        )"<< std::endl;
                break;
        case 4:
                std::cout << R"(
                                ______
                               /O    O/\
                              /      /O \
                             /O____O/    \
                             \O    O\    /
                              \O    O\ O/
                               \O____O\/
                                        )"<< std::endl;
                break;
        case 5:
                std::cout << R"(
                                ______
                              /O    O/\
                             /   O  /O \
                            /O____O/    \
                            \O    O\    /
                             \O    O\ O/
                              \O____O\/
                                        )"<< std::endl;
                break;
        case 6:
                std::cout << R"(
                                ______
                               /O    O/\
                              /O    O/O \
                             /O____O/    \
                             \O    O\    /
                              \      \ O/
                               \O____O\/
                                        )"<< std::endl;
                break;
        default:
            break;
    }
}

unsigned int Ihm::entrerChoixTypePartie()
{
    unsigned int choixUtilisateur;
    std::cout
      << "\nTypes de Partie : Si vous faites un autre "
         "choix que 1 ou 2, par défaut on lance une partie contre un BOT"
      << std::endl;
    std::cout << "\nPartie 1 vs 1 = (1) / Partie 1 vs BOT = (2) : ";
    std::cin >> choixUtilisateur;
    if((choixUtilisateur == 1) || (choixUtilisateur == 2))
    {
        return choixUtilisateur;
    }

    else
        return 2;
}

void Ihm::afficherJoueur(const std::string& nomJoueur) const
{
    std::cout << "joueur : " << nomJoueur << std::endl;
}

unsigned int Ihm::choisirDifficulte()
{
    int choix = 0;
    std::cout << "Choisir une difficulté :  1->normal, 2->difficile, 3->extreme"
              << std::endl;
    std::cin >> choix;

    return choix;
}

void Ihm::afficherLancerDeQuiCommence() const
{
    std::cout << std::endl << " Lancer pour savoir qui commence !" << std::endl;
}