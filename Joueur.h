#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>

#define NOMBRE_DE_DES 3
#define NOMBRE_DE_POINTS 343

class De;
class Joueur
{
  private:
    std::vector<De*> de[NOMBRE_DE_DES];
    unsigned int     compteurDePoint;
    std::string      nomDuJoueur;

  public:
    Joueur();
    Joueur(std::string nomDuJoueur);
};
