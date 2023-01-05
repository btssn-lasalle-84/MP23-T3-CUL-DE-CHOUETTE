#ifndef IHM_H
#define IHM_H

#include <iostream>
#include <iomanip>
class Ihm
{
  private:
  public:
    Ihm();
    ~Ihm();

    void afficherRegle() const;
    void afficherDebutJeu() const;
    void afficherJoueur() const;
    void afficherLancer() const;
    void afficherScoreDuJoueur() const;
};

#endif