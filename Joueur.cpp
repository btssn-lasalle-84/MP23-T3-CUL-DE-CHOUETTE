#include "Joueur.h"  

Joueur::Joueur() : nomDuJoueur(""), compteurDePoint(NOMBRE_DE_POINTS) 
{         
	de = new De; 
}  

Joueur::Joueur(std::string nomDuJoueur) : nomDuJoueur(nomDuJoueur), compteurDePoint(NOMBRE_DE_POINTS) 
{ 
	de = new De;
}
