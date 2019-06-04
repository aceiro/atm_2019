// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <fstream>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Help.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::endl;
// "ifstream" e "ios" são escopos para abrir o arquivo, sobre a regra de "apenas leitura"
using std::ifstream;
using std::ios;

Help::Help() {

}

Help::~Help() {

}

// Rotina para abrir o arquivo, e imprimir o mesmo em tela
void Help::displayHelpFile() {
  // Abrindo o aquivo README.txt, presenta na raiz, como somente em leitura.
  helpFile.open("./README.txt");

  // Rotina para verificar se o arquivo existe, e sim abrí-lo
  if (helpFile.is_open()) {
    lineNumber = 1;
    while (getline(helpFile, fileLine)) {
      cout << lineNumber << "\t" << fileLine << endl;
      lineNumber++;
    } 
    helpFile.close();

  } else
      cout << "Não foi possível abrir o Arquivo" << endl;
}