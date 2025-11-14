# Get Next Line — Lecture de fichier ligne par ligne (Projet 42)

## 🧾 Description

`get_next_line` (GNL) est un projet de l’école 42 dont l’objectif est d’implémenter une fonction capable de lire un fichier **ligne par ligne**, sans jamais recharger tout le fichier en mémoire.

Le projet met l’accent sur :

* la gestion fine des **buffers**,
* la **mémoire dynamique**,
* la manipulation de fichiers,
* et l’optimisation du flux de lecture.

Il s’agit d’un exercice fondamental pour maîtriser les bases du bas niveau en C.

---

## 🎯 Objectifs du projet

* Lire une ligne complète depuis un descripteur de fichier
* Gérer un buffer statique ou dynamique selon la version
* Préserver les données restantes entre les appels
* Assurer un comportement fiable quel que soit le type de fichier

---

## 🔧 Fonctionnement

La fonction `get_next_line` :

1. Lit un nombre fixe d’octets (`BUFFER_SIZE`)
2. Stocke temporairement les données
3. Construit progressivement une ligne complète
4. Renvoie la ligne, puis prépare la suivante

Elle doit fonctionner :

* sur les fichiers classiques,
* l’entrée standard,
* et les descripteurs multiples (selon la version).

---

## 📁 Structure du projet

```
gnl/
│
├── get_next_line.c          # Fonction principale
├── get_next_line_utils.c    # Fonctions utilitaires
├── get_next_line.h          # Header
├── main.c                   # Fichier de test
└── README.md                # Documentation
```

---

## 🛠️ Compilation

Pour compiler le projet :

```
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42
```

Tu peux changer `BUFFER_SIZE` comme tu veux.

---

## 📌 Exemple d'utilisation

```c
#include "get_next_line.h"
#include <fcntl.h>

int main()
{
    int fd = open("fichier.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 👤 Auteur

**Gabriel Benetrix**
Étudiant à l'école 42
