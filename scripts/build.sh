#!/usr/bin/env bash

# Nombre del ejecutable
EXEC="main.out"

# Compilación con flags básicos
g++ -std=c++11 -O2 -Wall -o "$EXEC" src/main.cpp

# Salir si la compilación falla
if [ $? -ne 0 ]; then
  printf "\n❌ Compilation failed.\n\n"
  exit 1
fi

# Ejecución del programa
printf "\n✅ Compilation succeeded. Running...\n\n"
./"$EXEC"