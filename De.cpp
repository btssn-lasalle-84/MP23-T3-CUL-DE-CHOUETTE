#include "De.h"
#include <chrono>
#include <random>

#ifdef DEBUG_DE
#include <iostream>
#endif

De::De(unsigned int nombreDeFaces /*= NOMBRE_DE_FACES*/) :
    valeur(INDEFINI), nombreDeFaces(nombreDeFaces)
{
#ifdef DEBUG_DE
    std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__ << " " << this
              << " valeur = " << valeur << std::endl;
#endif
}

De::~De()
{
#ifdef DEBUG_DE
    std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__ << " " << this
              << std::endl;
#endif
}

int De::getValeurDe() const
{
#ifdef DEBUG_DE
    std::cout << __PRETTY_FUNCTION__ << " ligne n° " << __LINE__ << " " << this
              << " valeur = " << valeur << std::endl;
#endif
    return this->valeur;
}

void De::lancerDe()
{
    static std::default_random_engine nombre(std::chrono::system_clock::now().time_since_epoch().count());
    static std::uniform_int_distribution<int> generer(NOMBRE_MIN_DE, NOMBRE_MAX_DE);
    valeur = generer(nombre);
}