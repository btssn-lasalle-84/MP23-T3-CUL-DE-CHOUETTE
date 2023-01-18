#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <vector>

#define NOMBRE_DE_DES    3
#define NOMBRE_DE_POINTS 0
//#define DEBUG_JOUEUR

enum TypeCombinaison
{
    Chouette      = 0,
    Velute        = 1,
    Suite         = 2,
    CulDeChouette = 3,
    Aucune        = 4
};

class De;

class Joueur
{
  private:
    std::string      nomDuJoueur;
    std::vector<De*> des;
    unsigned int     scoreLance;
    unsigned int     compteurDePoints;
    bool             identifierCombinaisonChouette();
    bool             identifierCombinaisonVelute();
    bool             identifierCombinaisonCulDeChouette();
    bool             identifierCombinaisonSuite();

  public:
    Joueur(const std::string& nomDuJoueur = "");
    ~Joueur();
    unsigned int    getScore() const;
    std::string     getNomJoueur() const;
    void            lancerDes();
    void            lancerDe();
    unsigned int    getDes0() const;
    unsigned int    getDes1() const;
    unsigned int    getDes2() const;
    unsigned int    getScorelance() const;
    void            setNomduJoueur(const std::string& nomDuJoueur);
    void            setDe(unsigned int valeur);
    void            trierDes();
    TypeCombinaison identifierCombinaison();
};

#endif