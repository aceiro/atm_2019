// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <stdlib.h>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Components.hpp"


// Uso refinado do Escopo STD
using std::cout;
using std::endl;
using std::string;

Components::Components() {

}

Components::~Components() {

}

// Rotina de Limpeza de tela
void Components::clearScreen() {
  system("cls || clear");
}

// Rotina para dar "pause" na sequência do programa
void Components::pauseScreen() {
  getchar();
}