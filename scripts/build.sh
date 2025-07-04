#!/usr/bin/env bash

# Nombre del ejecutable
EXEC="main.out"

# Detect Boost include and lib paths
if [ -d "/opt/homebrew/include/boost" ]; then
  BOOST_INCLUDE="/opt/homebrew/include"
  BOOST_LIB="/opt/homebrew/lib"
elif [ -d "/usr/local/include/boost" ]; then
  BOOST_INCLUDE="/usr/local/include"
  BOOST_LIB="/usr/local/lib"
else
  echo "❌ Boost not found. Please install Boost (brew install boost)."
  exit 1
fi

# Compilación con flags básicos
g++ -std=c++11 -O2 -Wall -I"$BOOST_INCLUDE" -L"$BOOST_LIB" -lboost_system -o "$EXEC" src/main.cpp

# Salir si la compilación falla
if [ $? -ne 0 ]; then
  printf "\n❌ Compilation failed.\n\n"
  exit 1
fi

# Ejecución del programa
printf "\n✅ Compilation succeeded. Running...\n\n"
./"$EXEC"

rm -f "$EXEC"
rm -f main
echo -e "\n🗑️  main & main.out deleted."
