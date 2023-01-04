#include <iostream>

class Partie
{
  private:
    int nombreDeJoueurs;
    const int objectifNombre = 343;
    std::string difficulte;
    int numeroDeTour;

  public:
    Partie();
    Partie(int nombreDeJoueurs);
};