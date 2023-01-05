#include "De.h"
#include <random>

De::De(unsigned int nombreDeFaces /*= NOMBRE_DE_FACES*/) :
    valeur(INDEFINI), nombreDeFaces(nombreDeFaces)
{
}

int De::getValeurDe()
{
    std::cout << this->valeur << std::endl;
    return this->valeur;
}

void De::lancerDe()
{
    std::random_device                 nombre;
    std::uniform_int_distribution<int> generer(NOMBRE_MIN_DE, NOMBRE_MAX_DE);
    this->valeur = generer(nombre);
}