// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Form.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;

void Form::formDelete() {
  string idCI;
  int escape = 0;
  // char optUpdate = '\0';

  if (!Data.empty()) {
    // Imprimindo todas os Registros de CI
    displayRecordsReport();

    do {
      // Escolhendo qual será o registro a ser retornado, para ver recuperar todos os dados
      cout << endl << "EXCLUIR ID. (escolha entre os registros acima): ";
      getline(cin, idCI);
      
      // Váriavel de Controle de exibições do Loop 
      escape++;

      // Controle do Loop
      if (escape == NUMBER_OF_ATTMPTS) {
        recordNotFoundMenssage();
        abortingProcessMessage();
        break;
      }
    } while (!formSelect(idCI));

    // Caso confirmado a existência do identificado, apaga-se a posição que o mesmo está alocado
    // Sendo assim, todo os registros (toda CI) são apagados nesta posição
    if (formSelect(idCI)) {
      for (unsigned index = 0; index < Data.size(); index++) {
        if ((Data[index].getIdCI()) == idCI) {
          Data.erase(Data.begin() + index);
        }
      }
    }
    successfulMessage();
    
  }
  else
    emptyMessage();
}
