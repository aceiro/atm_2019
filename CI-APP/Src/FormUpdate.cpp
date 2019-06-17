// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
// #include <iomanip> // Biblioteca interna do C++ para trabalhar com alinhamento (width, right, etc)

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Form.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;
// using std::setw; // setw() é uma função para alinhar a largura
// using std::left; // alinha a esquerda

void Form::formUpdate() {
  string idCI;
  string senderCI;
  string recipientCI;
  string subjectCI;
  string messageCI;
  string fieldCI;
  int escape = 0;
  string optUpdate;

  if (!Data.empty()) {
    // Imprimindo todas os Registros de CI
    displayRecordsReport();

    do {
      // Escolhendo qual será o registro a ser retornado, para ver recuperar todos os dados
      cout << endl << "ALTERAR ID. (escolha entre os registros acima): ";
      getline(cin, idCI);
      
      // Váriavel de Controle de exibições do Loop 
      escape++;

      // Controle do Loop
      if (escape == 5) {
        recordNotFoundMenssage();
        abortingProcessMessage();
        break;
      }
    } while (!formSelect(idCI));

    displaySelectCI(idCI, "UPDATE");
    successfulMessage();

    // do {

    // } while ();

  }
  else
    emptyMessage();
}


