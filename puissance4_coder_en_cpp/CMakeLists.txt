cmake_minimum_required(VERSION 3.0)
project(puissance4)

# Ajouter des options de compilation pour tous les fichiers source.
add_compile_options(-Wall)

# Inclure des répertoires si vous avez des en-têtes dans des répertoires séparés.
# Remplacez "./headers" par le chemin vers votre répertoire d'en-têtes si nécessaire.
include_directories(./src/headers)

# Ajouter les fichiers sources au projet.
add_executable(${PROJECT_NAME}.out
  src/ia.cpp
  src/jeu.cpp
  src/strategie.cpp
  src/verification.cpp
  src/main.cpp
)

# Trouver le paquet SFML par les modules nécessaires.
# Si SFML n'est pas installé dans un chemin standard, vous devrez peut-être
# définir la variable SFML_DIR au chemin contenant le fichier "Config.cmake" de SFML
# par exemple, vous pourriez avoir besoin d'ajouter une ligne telle que :
# set(SFML_DIR "<chemin-vers-SFML>/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Lier votre exécutable aux bibliothèques SFML.
target_link_libraries(${PROJECT_NAME}.out sfml-graphics sfml-window sfml-system)

# Autres composants de SFML que vous pourriez utiliser dans votre projet :

# Pour ajouter la gestion audio à votre application :
# find_package(SFML 2.5 COMPONENTS audio REQUIRED)
# target_link_libraries(${PROJECT_NAME}.out sfml-audio)

# Pour ajouter la gestion du réseau :
# find_package(SFML 2.5 COMPONENTS network REQUIRED)
# target_link_libraries(${PROJECT_NAME}.out sfml-network)

# Notez que chaque fois que vous ajoutez un composant avec find_package,
# vous devez également lier votre exécutable à ce composant avec target_link_libraries.
