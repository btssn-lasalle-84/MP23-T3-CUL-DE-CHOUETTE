#ifndef PARTIE_H
#define PARTIE_H

#include <list>

#define OBJECTIF_PAR_DEFAUT        343
#define OBJECTIF_DIFFICILE_EXTREME 543
#define NB_JOUEURS_PAR_DEFAUT      2
#define CONSTANTE_BOUCLE_INFINI    1
#define DEBUG_PARTIE

enum Difficulte
{
    Normal    = 0, // DIFFICULTE_PAR_DEFAUT
    Difficile = 1,
    Extreme   = 2
};

class Joueur;
class Ihm;

class Partie
{
  private:
    unsigned int       nombreDeJoueurs;
    unsigned int       objectifNombre;
    Difficulte         difficulte;
    unsigned int       numeroDeTour;
    unsigned int       choixDuTypeDePartie;
    std::list<Joueur*> joueurs;
    Ihm*               ihm;

  public:
    Partie(unsigned int nombreDeJoueurs     = NB_JOUEURS_PAR_DEFAUT,
           Difficulte   difficulte          = Difficulte::Normal,
           unsigned int objectifNombre      = OBJECTIF_PAR_DEFAUT,
           unsigned int choixDuTypeDePartie = 0,
           Ihm*         ihm                 = nullptr);
    ~Partie();
    void         jouer();
    void         joueur1Commence();
    void         joueur2Commence();
    unsigned int getObjectifNombre() const;
    unsigned int getNumeroDeTour() const;
    bool         aGagne(unsigned int const& score);
    void         quiCommence();
    void         choixPartie(unsigned int choixDuJoueur);
    void         creerJoueurEtBot();
    void         creerJoueurEtJoueur();
    unsigned int getChoixDuTypeDePartie();
    void         setDifficulte(unsigned int difficulte);
    Difficulte   getDifficulte() const;
};

#endif // !PARTIE_H