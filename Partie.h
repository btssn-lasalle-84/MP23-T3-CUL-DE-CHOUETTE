#ifndef PARTIE_H
#define PARTIE_H
#define NOMBRE_VICTOIRE_PAR_DEFAUT   343
#define NB_JOUEURS_PAR_DEFAUT 2
//#define DEBUG_PARTIE

#include <list>
#include <vector>

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
    unsigned int       nombreVictoire;
    Difficulte         difficulte;
    unsigned int       numeroDeTour;
    std::list<Joueur*> joueurs;
    Ihm*               ihm;

  public:
    Partie(unsigned int nombreDeJoueurs = NB_JOUEURS_PAR_DEFAUT,
           Difficulte   difficulte      = Difficulte::Normal,
           unsigned int NombreVictoire  = NOMBRE_VICTOIRE_PAR_DEFAUT);
    ~Partie();
    void         jouer();
    unsigned int getNombreVictoire() const;
    unsigned int getNumeroDeTour() const;
    bool         aGagne(unsigned int const& score);
};

#endif // !PARTIE_H