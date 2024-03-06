# Puissance 4

Le projet Puissance 4 est une implémentation du jeu de stratégie classique en C++, utilisant la bibliothèque SFML pour l'interface graphique. Ce guide vous aidera à installer et à lancer le jeu sur votre machine.

## Prérequis

Pour compiler et exécuter ce projet, assurez-vous que vous avez installé :

- Un compilateur C++ supportant le standard C++11 (comme g++).
- CMake (version 3.0 ou ultérieure).
- SFML (version 2.5 ou ultérieure).

### Installation de SFML

La méthode d'installation de SFML dépend de votre système d'exploitation.


#### Sur Ubuntu/Debian

```bash
sudo apt-get install libsfml-dev
```

#### Sur Fedora

```bash
sudo dnf install SFML
```


#### Sur macOS (avec Homebrew)

```bash
brew install sfml
```

#### Sur Windows

Téléchargez et installez SFML depuis le [site officiel de SFML](https://www.sfml-dev.org/download.php). Assurez-vous de configurer les chemins vers les bibliothèques dans votre IDE ou système de build.

## Compilation et Exécution du Projet

1. Clonez le dépôt GitHub à l'aide de la commande suivante :

```bash
git clone https://github.com/hofrance/puissance4.git
```



2. Naviguez dans le répertoire du projet :

```bash
cd puissance4
```

3. Créez un répertoire de build et naviguez dans ce répertoire :

```bash
mkdir build && cd build
```

4. Générez les fichiers de build avec CMake :

```bash
cmake ..
```

5. Compilez le projet :

```bash
make
```

6. Exécutez le jeu :

```bash
./puissance4.out
```

## Structure du Projet

- `puissance4_coder_en_cpp`:contient le jeu developper en c++
- `puissance4_coder_en_cpp/src/`: Contient les fichiers sources (.cpp) du projet.
- `puissance4_coder_en_cpp/src/header`: Contient les fichiers d'en-tête (.h).
- `CMakeLists.txt`: Script de configuration pour CMake.


## Contribuer

Les contributions à ce projet sont les bienvenues. N'hésitez pas à forker le dépôt, apporter vos modifications, et soumettre une pull request.



## Contactez moi
- `BANKOUEZI Richard Hofrance`[ visitez mon site Web ](https://www.richard-hofrance.com)
- `contact@richard-hofrance.com`


