#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>

class De;
class Joueur
{
  private:
    std::vector<De*> de[3];
    unsigned int     compteurDePoint;
    std::string      nomDuJoueur;

  public:
    Joueur();
    Joueur(std::string nomDuJoueur);
};
#endif