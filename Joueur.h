#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <vector>
#include <cmath>

#define NOMBRE_DE_DES    3
#define NOMBRE_DE_POINTS 0

class De;

class Joueur
{
  private:
    std::string      nomDuJoueur;
    std::vector<De*> des;
    unsigned int     compteurDePoints;

  public:
    Joueur(std::string nomDuJoueur = "");
    unsigned int const getScore();
    std::string const  getNomJoueur();
    void               setScore();
    void               setNomduJoueur(std::string nomDuJoueur);
};

#endif