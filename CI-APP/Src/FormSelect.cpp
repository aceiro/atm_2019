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
  for (unsigned i = 0; i < Data.size(); i++) {
    cout << endl;
    cout << Data[i].getIdCI() << endl;
    cout << Data[i].getSenderCI() << "\t" << Data[i].getRecipientCI() << endl;
    cout << Data[i].getSubjectCI() << "\t" << Data[i].getDateCI() << endl;
    cout << Data[i].getMessageCI() << endl;
    cout << endl;
  }



}
