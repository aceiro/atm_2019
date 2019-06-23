// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef PRINTINGMODULE_HPP
#define PRINTINGMODULE_HPP

// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <fstream>

// Padrões usados para a entradas do Menu, e tudo relacionado.
#define PRINT "Imprimir um registro de CI"

// Título da Janela Imprmir
#define PRINT_TITLE "MÓDULO DE IMPRESSAO - IMPRIMIR UMA CI (em arquivo txt)"

// Uso refinado do Escopo STD
using std::cout;
using std::endl;
using std::string;
using std::ofstream; // Container para utilizar escrita de arquivos em C++

// Declaração da Classe de Impressão
class PrintingModule {
  private:
    // Atributo responsável pela abertura do arquivo.
    ofstream formFile;
    string fileName;
    string printIdCI;
    string printSenderCI;
    string printRecipientCI;
    string printSubjectCI;
    string printDateCI;
    string printMessageCI;
  
  public:
    PrintingModule();
    ~PrintingModule();
    // Método para gerar um arquivo (Impressão em arquivo)
    void printFileCI(string fileName, string printIdCI, string printSenderCI, string printRecipientCI, string printSubjectCI, string printDateCI, string printMessageCI);
};

#endif
