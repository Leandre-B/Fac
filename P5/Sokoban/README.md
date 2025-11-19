# Sokoban

**Sommaire**

[Présentation](##Présentation)  
[Installation / Exécution](##Installation/Exécution)  
[Comment jouer ?](##Commentjouer?)

## Présentation
Ceci est un projet de fin d'année de notre L1 informatique à l'université d'Angers, pour plus d'information, vous pouvez visiter [cette page](https://leria-etud.univ-angers.fr/~leand/Sokoban/index.html)

## Installation / Exécution
Le repo se base sur le [template officiel GitHub SFML 2.6](https://github.com/SFML/cmake-sfml-project/tree/sfml2)
Vous pouvez jeter un coup d'oeil au tuto [SFML with the CMake Project Template](https://www.sfml-dev.org/tutorials/2.6/start-cmake.php#requirements))
L'installation de git sur votre machine est indispensable

### Sur Linux
Différents package sont nécéssaire (cf [SFML with the CMake Project Template](https://www.sfml-dev.org/tutorials/2.6/start-cmake.php#requirements))
- A partir du projet/dossier Sokoban:
```console
mkdir build
cd build
cmake ..
make
cd bin
./sokoban
```


### Sur Windows
- Installer un compilateur c++, nous recommendons GCC 13.1.0 (with POSIX threads) + LLVM/Clang/LLD/LLDB 16.0.5 - release 5,  Win32 : [Winlibs](https://winlibs.com/) ou [téléchargement direct](https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-ucrt-r5/winlibs-i686-posix-dwarf-gcc-13.1.0-llvm-16.0.5-mingw-w64ucrt-11.0.0-r5.zip)

- A partir du projet/dossier Sokoban:
```console
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
mingw32-make
cd bin
./sokoban.exe
```
- Pour certaines raisons, la compilation du projet peut échouer sur Windows, si cela vous arrive, bon courage.

## Comment jouer ?

### Règles du jeu
- L'objectif est de déplacer toutes les caisses sur leurs emplacement
- les déplacements sont uniquement latéraux.
- le joueur perd quand une caisse est bloquée


### Navigation dans les menus

- La plupart des textes peuvent être cliqués, pour revenir d'un menu à un autre appuyez sur la touche "échap".
- Le skin par défaut est "default", pour en changer, cliquez sur les noms des skins en haut à gauche sur l'écran de séléction des niveaux.

- Notre jeu ne supportant pas le redimensionnage de fenêtre, il est fortement récommandé de ne pas changer sa taille.

### Création de niveaux et de skins

Il est possible pour tout utilisateur de créer ses propres niveaux ainsi que ses propres skins.

### Pour les niveaux


**En .xsb :** 

Format originel du Sokoban, vous pouvez importer des niveaux déjà existant où en créer en suivant le code ci-dessous.
- '#' =murs
- '$' =caisse
- '@' =personnage
- '.' =emplacement de caisse
- '\*' =caisse sur emplacement
- '\+' =personnage sur emplacement

**Attention**

- Il doit toujours y avoir un retour à la ligne à la fin du plateau.
- le joueur doit être entouré de murs (sinon ça crash).
- le nom du fichier doit bien se terminer par .xsb.

**En .json :**

Nous ne recommendons pas vraiment ce format, mais si l'envie vous prend, vous pouvez prendre exemple sur les plateaux déjà présent.


*bien penser à les déposer dans Sokoban/plateau/*

### Pour les skins

- Créez un nouveau dossier dans Sokoban/Skins/
- Ajoutez vos images (bien respecter les noms)
- Les images sont en 32*32px et le fond en 4/3.
