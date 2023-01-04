#ifndef PARTIE_H
#define PARTIE_H

#include <list>

#define OBJECTIF_PAR_DEFAUT   343
#define NB_JOUEURS_PAR_DEFAUT 2

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
    int                nombreDeJoueurs;
    int                objectifNombre;
    Difficulte         difficulte;
    int                numeroDeTour;
    std::list<Joueur*> joueurs;
    Ihm*               ihm;

  public:
    Partie(int        nombreDeJoueurs = NB_JOUEURS_PAR_DEFAUT,
           Difficulte difficulte      = Difficulte::Normal,
           int        objectifNombre  = OBJECTIF_PAR_DEFAUT);
    ~Partie();
};

#endif // !PARTIE_H