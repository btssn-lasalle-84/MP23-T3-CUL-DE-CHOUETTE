#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include <string>

#define NOMBRE_DE_DES    3
#define NOMBRE_DE_POINTS 0

class De;
class Joueur
{
  private:
    std::vector<De> de[NOMBRE_DE_DES];
    unsigned int    compteurDePoint;
    std::string     nomDuJoueur;

  public:
    Joueur(std::string nomDuJoueur);
};
#endif
