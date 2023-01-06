#ifndef IHM_H
#define IHM_H

#define VITESSE_DEFILEMENT_TEXTE 8

class Joueur;

class Ihm
{
  private:
  public:
    Ihm();
    ~Ihm();

    void afficherRegle() const;
    void afficherMenuPrincipal() const;
    void afficherNomDuJoueur(const Joueur& joueur) const;
    void afficherResultatLanceDes(unsigned int total) const;
    void afficherScoreDuJoueur(const Joueur& joueur) const;
};

#endif // IHM_H