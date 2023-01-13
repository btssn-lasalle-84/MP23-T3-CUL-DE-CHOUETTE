#ifndef JOUEUR_H
#define JOUEUR_H
#define NOMBRE_DE_DES    3
#define NOMBRE_DE_POINTS 0
//#define DEBUG_JOUEUR

#include <string>
#include <vector>

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
    void            lancerUnDe();
    unsigned int    getPremierDe() const;
    unsigned int    getDeuxiemeDe() const;
    unsigned int    getTroisiemeDe() const;
    void            setNomduJoueur(const std::string& nomDuJoueur);
    unsigned int    setScore(unsigned int valeur);
    void            trierDes();
    TypeCombinaison identifierCombinaison();
};

#endif