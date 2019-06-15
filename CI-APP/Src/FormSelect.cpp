// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <iomanip> // Biblioteca interna do C++ para trabalhar com alinhamento (width, right, etc)
#include <ctime> // Biblioteca interna do C++ para usar padrões de data hora do sistema
#include <cctype> // Biblioteca interna do C++ para usar "isdigit"

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Form.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;
using std::setw; // setw() é uma função para alinhar a largura
using std::left; // alinha a esquerda

void Form::emptyMessage() {
  cout << endl << endl << "\t\t" << "Nenhum registro foi encontrado!!!" << endl << endl;
}

void Form::formSelect() {
  string idCI;

  cout << endl << "\t\tMÓDULO DE CONSULTA - SELECIONAR UMA CI" << endl << endl;
  
  if (!Data.empty()) {
    // Cabeçalho da tabela (campos identificação, data, mensagem)
    cout << endl;
    cout << setw(30) << left << "ID.";
    cout << setw(15) << left << "DATA";
    cout << setw(100) << left << "ASSUNTO";
    cout << endl;

    // Loop para carregar todas as mensagens armazenada no Vector (em memória)
    for (unsigned index = 0; index < Data.size(); index++) {
      cout << setw(30) << left << Data[index].getIdCI();
      cout << setw(15) << left << Data[index].getDateCI();
      cout << setw(100) << left << Data[index].getSubjectCI();
      cout << endl;
    }
    
    // Escolhendo qual será o registro a ser retornado, para ver recuperar todos os dados
    // cout << endl << "PESQUISAR (E ): ";
    // getline(cin, idCI);
  }
  else
    emptyMessage();
}
