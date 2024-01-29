cmake_minimum_required(VERSION 3.0)
project(puissance4)

add_compile_options(-Wall)

set(CMAKE_EXECUTABLE_SUFFIX ".html")  # Pour produire un .html à la fin

add_executable(${PROJECT_NAME}.out
  ia.cpp
  jeu.cpp
  strategie.cpp
  verification.cpp
  main.cpp
)
