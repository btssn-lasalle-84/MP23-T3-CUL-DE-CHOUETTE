#ifndef DE_H
#define DE_H
#define NOMBRE_DE_FACES 6
#define INDEFINI        0
#define NOMBRE_MIN_DE   1
#define NOMBRE_MAX_DE   6

#include <string>

class De
{
  private:
    unsigned int valeur;
    unsigned int nombreDeFaces;

  public:
    De(unsigned int nombreDeFaces = NOMBRE_DE_FACES);
    ~De();

    int  getValeurDe() const;
    void lancerDe();
    void setDe(unsigned int valeur);
};

#endif // !DES_H