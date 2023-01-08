#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <vector>

#define NOMBRE_DE_DES    3
#define NOMBRE_DE_POINTS 0
#define DEBUG_JOUEUR

enum TypeCombinaison
{
    Chouette = 0,
    Velute = 1,
    CulDeChouette = 2,
    Aucune = 3
};

class De;

class Joueur
{
  private:
    std::string      nomDuJoueur;
    std::vector<De*> des;
    unsigned int     compteurDePoints;
    bool             identifierCombinaisonChouette();
    bool             identifierCombinaisonVelute();
    bool             identifierCombinaisonCulDeChouette();

  public:
    Joueur(std::string nomDuJoueur = "");
    ~Joueur();
    unsigned int    getScore() const;
    std::string     getNomJoueur() const;
    void            lancerDes();
    void            setNomduJoueur(std::string const nomDuJoueur);
    TypeCombinaison identifierCombinaison();
};

#endif