#ifndef DE_H
#define DE_H

#include <string>

//#define DEBUG_DE

#define NOMBRE_DE_FACES 6
#define INDEFINI        0
#define NOMBRE_MIN_DE   1
#define NOMBRE_MAX_DE   6

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
};

class TriAscendant
{
  public:
    bool operator()(De* a, De* b) const
    {
        return (a->getValeurDe() < b->getValeurDe());
    }
};

#endif // !DES_H