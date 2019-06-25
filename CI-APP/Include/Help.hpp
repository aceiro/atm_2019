// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef HELP_HPP 
#define HELP_HPP

// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <fstream>

// Padrões usados para a entradas do Menu, e tudo relacionado.
#define HELP "Ajuda / Sobre"

// Uso refinado do Escopo STD
using std::cout;
using std::endl;
using std::string;
using std::ifstream; // Container para utilizar abertura e leitura de arquivos em C++

// Declaração da Classe de Ajuda
class Help {
  // Aqui, "helpFile" será um arquivo que será o README.txt
  private:
    // Atributo responsável pela abertura do arquivo.
    ifstream helpFile;
    string fileLine;
    int lineNumber;
  
  public:
    Help();
    ~Help();
    // Método para abrir o arquivo, exibir em tela, e depois fechá-lo
    void displayHelpFile();
};

#endif
