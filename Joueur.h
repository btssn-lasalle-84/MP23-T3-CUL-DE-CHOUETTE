#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <vector>

#define NOMBRE_DE_DES    3
#define NOMBRE_DE_POINTS 0
#define DEBUG_JOUEUR

class De;

class Joueur
{
  private:
    std::string      nomDuJoueur;
    std::vector<De*> des;
    unsigned int     compteurDePoints;

  public:
    Joueur(std::string nomDuJoueur = "");
    ~Joueur();
    unsigned int getScore() const;
    void         setScore();
    std::string  getNomJoueur() const;
    void         lancerDes();
    void         setNomduJoueur(std::string const nomDuJoueur);
};

#endif