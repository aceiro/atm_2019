// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef HELP_HPP 
#define HELP_HPP

// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <fstream>

// Padrões usados para a entradas do Menu, e tudo relacionado.
#define HELP "Ajuda / Sobre"

// Uso refinado do Escopo STD
using std::cout;
using std::endl;
// Container para utilizar abertura e leitura de arquivos em C++
using std::ifstream;

// Declaração da Classe de Ajuda
class Help {
  // Aqui, "fileHelp" será um arquivo que será o README.txt
  private:
    // Atributo responsável pela abertura do arquivo.
    ifstream helpFile;
  
  public:
    Help();
    ~Help();
    // Método para abrir o arquivo, exibir em tela, e depois fechá-lo
    void displayHelpFile();
};

#endif
