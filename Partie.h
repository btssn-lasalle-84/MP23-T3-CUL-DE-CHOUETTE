#ifndef PARTIE_H
#define PARTIE_H

#include <string>

#define OBJECTIF_PAR_DEFAUT 343
#define DIFFICULTE_PAR_DEFAUT 0
#define NB_JOUEURS_PAR_DEFAUT 2
class Partie
{
  private:
    int nombreDeJoueurs;
    int objectifNombre;
    enum difficulte
    {
      normal = 0,
      difficile = 1,
      extreme = 2
    };
    int numeroDeTour;

  public:
    Partie();
    Partie(int nombreDeJoueurs, unsigned int difficulte, int objectifNombre);
};

#endif // !PARTIE_H