#ifndef IHM_H
#define IHM_H

#define VITESSE_DEFILEMENT_TEXTE 1
#define NOM_BOT                  "BOT"
#define VERSION                  2

#include <string>
#include "Joueur.h"

class Joueur;

class Ihm
{
  private:
  public:
    Ihm();
    ~Ihm();

    void         afficherRegle() const;
    void         afficherMenuPrincipal() const;
    std::string  rentrerNomDuJoueur() const;
    void         afficherGagnant(const std::string& nomDujoueur,
                                 unsigned int       nombreDeTour,
                                 unsigned int       score) const;
    void         afficherScoreTotal(const std::string& nomDujoueur,
                                    unsigned int       scoreTotal,
                                    unsigned int       scoreLance) const;
    void         afficherCombinaison(TypeCombinaison combinaison) const;
    void         afficherQuiLance(const std::string& nomDuJoueur) const;
    void         afficherScoreDuJoueur(const Joueur& joueur) const;
    void         afficherLesDes(unsigned int des0,
                                unsigned int des1,
                                unsigned int des2);
    void         afficherLanceDe(unsigned int de);
    unsigned int entrerChoixTypePartie();
    void         afficherJoueur(const std::string& nomJoueur);
};

#endif // IHM_H