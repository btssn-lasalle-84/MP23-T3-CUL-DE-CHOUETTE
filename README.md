[![C/C++ make](https://github.com/btssn-lasalle84/MP23-T3/actions/workflows/c-cpp.yml/badge.svg?branch=develop)](https://github.com/btssn-lasalle84/MP23-T3/actions/workflows/c-cpp.yml) [![C/C++ format](https://github.com/btssn-lasalle84/MP23-T3/actions/workflows/cppformat.yml/badge.svg?branch=develop)](https://github.com/btssn-lasalle84/MP23-T3/actions/workflows/cppformat.yml)

# Mini-Projet : CUL DE CHOUETTE

---

<p align="center">
<img src="https://365idees.jf-blog.fr/files/2019/07/cul_de_chouette.png" width="150">

## Présentation

Le **[Cul de chouette](https://fr.wikibooks.org/wiki/Bo%C3%AEte_%C3%A0_jeux/Le_cul_de_chouette)** est un jeu originaire de la série [Kaamelott](https://fr.wikipedia.org/wiki/Kaamelott) et se joue avec trois dés à 6 faces. Le but du jeu est d'atteindre ou dépasser 343 points, le score à atteindre provenant des initiales du nom du jeu (CDC), soit les 3e, 4e et 3e lettres de l'alphabet.

Les points sont obtenus en utilisant des combinaisons grâce aux résultats des dés, par exemple : la Velute, la Chouette, la Suite, etc....

---

> Ceci est un mini-projet de 2 étudiants de BTS SN option Informatique & Réseaux développé en C++. L'objectif était la mise en oeuvre d'une méthode agile [Kanban](https://fr.wikipedia.org/wiki/Kanban_(d%C3%A9veloppement)) avec les outils **Jira / Github** et en appliquant le _workflow_ [Gitflow](https://btssn-lasalle84.github.io/guides-developpement-logiciel/jira.html#ancre-gitflow). L'application devait être limitée à une interface en ligne de commande (console).

---

## Exemple

```bas
$ make
g++ -std=c++11 -Wall -I. -c culDeChouette.cpp
g++ -std=c++11 -Wall -I. -c De.cpp
g++ -std=c++11 -Wall -I. -c Partie.cpp
g++ -std=c++11 -Wall -I. -c Joueur.cpp
g++ -std=c++11 -Wall -I. -c Ihm.cpp
g++ -o culDeChouette.out culDeChouette.o De.o Partie.o Joueur.o Ihm.o

$ ./culDeChouette.out
-----Bienvenue sur le jeu du Cul De Chouette ! Version 2-----

 Pouvons nous commencer ?

Si vous êtes prêt à jouer, Entrez (1)
Si vous souhaitez quitter, Entrez (2)
Si vous souhaitez voir les règles, Entrez (3)
Si vous voulez voir les difficulté, Entrez (4)

...
```

## Jira

Intégration avec Github :

![](images/mp23-t3-jira-code.png)

### Les versions

![](images/mp23-t3-jira-versions.png)

### Feuille de route

![](images/mp23-t3-jira-roadmap.png)

### Tickets

#### Version 1.0

![](images/mp23-t3-jira-version-1.0.png)

#### Version 1.1

![](images/mp23-t3-jira-version-1.1.png)

#### Version 2.0

![](images/mp23-t3-jira-version-2.0.png)



## Recette

| Fonctionnalitées                     | oui | non |
| ------------------------------------ | :---: | :---: |
| Jouer une partie                     | X   | |
| Saisir le nom d'un joueur            | X   | |
| Afficher le déroulement d'une partie | X   | |
| Jouer plusieurs parties              | X   | |
| Choisir un niveau de difficulté      | X   | |
| Jouer contre un ordinateur           | X   | |

## Exemple d'une partie 
 -----Bienvenue sur le jeu du Cul De Chouette ! Version 2-----
 
 Pouvons nous commencez ? 

Si vous êtes prêt à jouer, Entrez (1)
Si vous souhaitez quitter, Entrez (2)
Si vous souhaitez voir les règles, Entrez (3)
Si vous voulez voir les difficulté, Entrez (4)
Votre réponse : 1

Types de Partie : Si vous faites un autre choix que 1 ou 2, par défaut on lance une partie contre un BOT

Partie 1 vs 1 = (1) / Partie 1 vs BOT = (2) : 1
Choisir une difficulté :  1->normal, 2->difficile, 3->extreme
1

Entrez le nom du joueur : matthieu

Entrez le nom du joueur : celian

 Lancer pour savoir qui commence !
matthieu : C'est à votre tour !

Pour lancer les dés, appuyez sur (1) / Pour quittez, appuyez sur (2) : 1

matthieu lance les dès !


                                ______
                               /O    O/\
                              /      /O \
                             /O____O/    \
                             \O    O\    /
                              \O    O\ O/
                               \O____O\/
                                        

Lancer pour savoir qui commence !
celian : C'est à votre tour !

Pour lancer les dés, appuyez sur (1) / Pour quittez, appuyez sur (2) : 1

celian lance les dès !


                                ______
                              /     O/\
                             /      /  \
                            /O____ /    \
                            \O    O\  O /
                             \O    O\  /
                              \O____O\/
                                        
celian : C'est à votre tour !

Pour lancer les dés, appuyez sur (1) / Pour quittez, appuyez sur (2) : 1

celian lance les dès !


                                ______
                              /O    O/\
                             /   O  /O \
                            /O____O/    \
                            \O    O\    /
                             \O    O\ O/
                              \O____O\/
                                        

                                ______
                               /O    O/\
                              /O    O/O \
                             /O____O/    \
                             \O    O\    /
                              \      \ O/
                               \O____O\/
                                        

                                ______
                               /      /\
                              /   O  /O \
                             /_____ /    \
                             \O    O\    /
                              \O    O\ O/
                               \O____O\/
                                        
dé n° 1 = 5
dé n° 2 = 6
dé n° 3 = 1

La combinaison réalisée est : Velute

le score de ce lancé est de : 72
 le score total de celian est de : 72

matthieu : C'est à votre tour !
 
 Etc ...
## Auteurs

- Matthieu Salaun <<matthieu.salaun30@gmail.com>>
- Célian Subirana <<celian.subirana.pro@gmail.com>>

---
©️ BTS SNIR LaSalle Avignon 2023
