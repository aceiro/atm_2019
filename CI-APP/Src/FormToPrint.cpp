// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Form.hpp"
#include "../Include/PrintingModule.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;

PrintingModule printThis;

void Form::formToPrint() {
  string fileName;
  string printIdCI;
  string printSenderCI;
  string printRecipientCI;
  string printSubjectCI;
  string printDateCI;
  string printMessageCI;
  // string idCI;
  int escape = 0;
  // char optUpdate = '\0';

  if (!Data.empty()) {
    // Imprimindo todas os Registros de CI
    displayRecordsReport();

    do {
      // Escolhendo qual será o registro a ser retornado, para ver recuperar todos os dados
      cout << endl << "IMPRIMIR ID. (escolha entre os registros acima): ";
      getline(cin, printIdCI);
      
      // Váriavel de Controle de exibições do Loop 
      escape++;

      // Controle do Loop
      if (escape == NUMBER_OF_ATTMPTS) {
        recordNotFoundMenssage();
        abortingProcessMessage();
        break;
      }
    } while (!formSelect(printIdCI));

    // Caso confirmado a existência do identificado, será usado como referência
    // para gerar a impressão
    if (formSelect(printIdCI)) {
      for (unsigned index = 0; index < Data.size(); index++) {
        if ((Data[index].getIdCI()) == printIdCI) {
          // Carregandos dados para gerar a impressão em arquivo
          fileName = printIdCI;
          fileName += ".txt";
          printIdCI = Data[index].getIdCI();
          printDateCI = Data[index].getDateCI();
          printSenderCI = Data[index].getSenderCI();
          printRecipientCI = Data[index].getRecipientCI();
          printSubjectCI = Data[index].getSubjectCI();
          printMessageCI = Data[index].getMessageCI();
        }
      }

      // Rotina que faz impressão de acordo com a escolha
      printThis.printFileCI(fileName, printIdCI, printSenderCI, printRecipientCI, printSubjectCI, printDateCI, printMessageCI);
    }
    successfulMessage();
    
  }
  else
    emptyMessage();
}
