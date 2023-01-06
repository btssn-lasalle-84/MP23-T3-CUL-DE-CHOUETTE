#ifndef IHM_H
#define IHM_H

#define VITESSE_DEFILEMENT_TEXTE 8

class Ihm
{
  private:
  public:
    Ihm();
    ~Ihm();

    void afficherRegle() const;
    void afficherMenuPrincipal() const;
    void afficherNomDuJoueur() const;
    void afficherLancerDe() const;
    void afficherScoreDuJoueur() const;
};

#endif