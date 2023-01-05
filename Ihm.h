#ifndef IHM_H
#define IHM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>

#define VITESSE_DEFILEMENT_TEXTE 8

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