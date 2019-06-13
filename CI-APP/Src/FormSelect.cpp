// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
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

void Form::formSelect() {
  for (unsigned index = 0; index < Data.size(); index++) {
    cout << endl;
    cout << "Código: " << Data[index].getIdCI() << endl;
    cout << "De: " << Data[index].getSenderCI() << "\tPara: " << Data[index].getRecipientCI() << endl;
    cout << "Assunto: " << Data[index].getSubjectCI() << "\tData: " << Data[index].getDateCI() << endl;
    cout << "Mensagem: " << Data[index].getMessageCI() << endl;
    cout << endl;
  }



}
