// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef COMPONENTS_HPP_INCLUDED
#define COMPONENTS_HPP_INCLUDED

// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>

// Uso refinado do Escopo STD
using std::string;

// Declaração da Classe Components
// Classe com funções utilitárias ao código
class Components {
  private:
    
  public:
    Components();
    ~Components();
    string mainTitle;
    // Método padrão para limpar a tela
    void clearScreen();
    // Método padrão para dar "pause" no fluxo do código.
    void pauseScreen();
};

#endif