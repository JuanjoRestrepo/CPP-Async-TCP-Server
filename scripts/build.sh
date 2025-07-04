#!/usr/bin/env bash

# Name: build.sh
# Description: Script to compile and run the C++ async TCP server with Boost.
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

# Compile both main and server.cpp
g++ -std=c++11 -O2 -Wall -Iinclude -I"$BOOST_INCLUDE" -L"$BOOST_LIB" \
    -lboost_system \
    -o "$EXEC" src/main.cpp src/server.cpp

# Stop on compilation failure
if [ $? -ne 0 ]; then
  printf "\n❌ Compilation failed.\n\n"
  exit 1
fi

printf "\n✅ Compilation succeeded. Running...\n\n"
./"$EXEC"
