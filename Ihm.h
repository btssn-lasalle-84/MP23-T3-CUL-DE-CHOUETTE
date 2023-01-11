#ifndef IHM_H
#define IHM_H

#define VITESSE_DEFILEMENT_TEXTE 2
#include <string>
#include "Joueur.h"

class Joueur;

class Ihm
{
  private:
  public:
    Ihm();
    ~Ihm();

    void        afficherRegle() const;
    void        afficherMenuPrincipal() const;
    std::string rentrerNomDuJoueur() const;
    void        afficherGagnant(std::string nomDujoueur) const;
    void        afficherScoreTotal(std::string  nomDujoueur,
                                   unsigned int scoreTotal) const;
    void        afficherCombinaison(TypeCombinaison combinaison) const;
    void        afficherLanceDes(std::string const nomDuJoueur) const;
    void        afficherScoreDuJoueur(const Joueur& joueur) const;
    void        afficherLesDes(unsigned int des0,
                               unsigned int des2,
                               unsigned int des3);
};

#endif // IHM_H