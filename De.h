#ifndef DE_H
#define DE_H

#define NOMBRE_DE_FACES 6
#define INDEFINI        0

class De
{
  private:
    int          valeur;
    unsigned int nombreDeFaces;

  public:
    De(unsigned int nombreDeFaces = NOMBRE_DE_FACES);
};

#endif // !DES_H