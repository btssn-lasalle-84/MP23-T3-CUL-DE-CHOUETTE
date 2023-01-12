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
    void        afficherGagnant(const std::string& nomDujoueur,
                                unsigned int       nombreDeTour) const;
    void        afficherScoreTotal(const std::string& nomDujoueur,
                                   unsigned int       scoreTotal) const;
    void        afficherCombinaison(TypeCombinaison combinaison) const;
    void        afficherLanceDes(const std::string& nomDuJoueur) const;
    void        afficherScoreDuJoueur(const Joueur& joueur) const;
    void        afficherLesDes(unsigned int des0,
                               unsigned int des1,
                               unsigned int des2);
};

#endif // IHM_H