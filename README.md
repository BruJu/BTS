# ABR

## Java

Un étudiant m'a demandé de l'aide pour l'aider à implémenter un Arbre Binaire
de Recherche en C++. 3 jours plus tard, il ne comprenait toujours pas comment
réaliser une insertion, donc j'ai développé ce code en 5 minutes pour pouvoir
lui montrer les idées derrières l'implémentation (ici en Java).

### Licence

TreeSet fait basiquement ce que fait ce code en mieux et avec plus de
services.


## C++

Cet étudiant ayant des difficultés à coder les constructeurs par copie /
opérateur d'affectations … Je me suis demandé si j'avais en fait bien le niveau
pour réaliser la tâche qu'il s'était donné (avoir un ABR en C++ avec insertion,
suppression et un itérateur). 1h30 plus tard, je me retrouvais avec ce code.

N'ayant pas trouvé de tutoriel clair et simple pour créer un iterator, j'ai fait
le choix d'en coder un très simple qui implémente le strict minimum pour être
un iterator output utilisable avec `begin`. N'ayant pas de parent dans ma
structure de noeud, j'utilise une `std::stack` pour simuler la récursion.


### Licence

`std::set` fait basiquement ce que fait ce code en mieux.
