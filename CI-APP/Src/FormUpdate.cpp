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

void Form::formUpdate() {
  string idCI;
  string newSenderCI;
  string newRecipientCI;
  string newSubjectCI;
  string newMessageCI;
  // string fieldCI;
  int idField = 0;
  int escape = 0;
  char optUpdate = '\0';

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
      if (escape == NUMBER_OF_ATTMPTS) {
        recordNotFoundMenssage();
        abortingProcessMessage();
        break;
      }
    } while (!formSelect(idCI));

    if (escape != NUMBER_OF_ATTMPTS) {
      displaySelectCI(idCI, "UPDATE");

      escape = 0;
      do {
        // Escolhendo qual campo será atualizado
        cout << endl << "ESCOLHA UM DOS CAMPOS (A, B, C ou D) PARA ALTERAR): ";
        cin >> optUpdate;
        cin.ignore();
        
        // Váriavel de Controle de exibições do Loop 
        escape++;

        // Controle do Loop
        if (escape == NUMBER_OF_ATTMPTS) {
          // recordNotFoundMenssage();
          // abortingProcessMessage();
          break;
        }

      } while (!validateInputToUpdate(optUpdate));

      if (!validateInputToUpdate(optUpdate)) {
        recordNotFoundMenssage();
        abortingProcessMessage();
      }
    }
    
    if (validateInputToUpdate(optUpdate)) {
      if ((returnInputToUpdate(optUpdate)) == 1) {
        // Entrada de dados
        cout << endl << "DE (max 100 caracteres): ";
        getline(cin, newSenderCI);
        // Verificar se os dados de não estão vazios
        newSenderCI = validateInput(newSenderCI, SENDER_RECIPIENT_SUBJECT_SIZE);

        formUpdate(idCI, newSenderCI, 1);
        successfulMessage();
      }

      if ((returnInputToUpdate(optUpdate)) == 2) {
        // Entrada de dados
        cout << endl << "PARA (max 100 caracteres): ";
        getline(cin, newRecipientCI);
        // Verificar se os dados de não estão vazios
        newRecipientCI = validateInput(newRecipientCI, SENDER_RECIPIENT_SUBJECT_SIZE);

        formUpdate(idCI, newRecipientCI, 2);
        successfulMessage();
      }

      if ((returnInputToUpdate(optUpdate)) == 3) {
        // Entrada de dados
        cout << endl << "ASSUNTO (max 100 caracteres): ";
        getline(cin, newSubjectCI);
        // Verificar se os dados de não estão vazios
        newSubjectCI = validateInput(newSubjectCI, SENDER_RECIPIENT_SUBJECT_SIZE);

        formUpdate(idCI, newSubjectCI, 3);
        successfulMessage();
      }

      if ((returnInputToUpdate(optUpdate)) == 4) {
        // Entrada de dados
        cout << endl << "MENSAGEM (max 500 caracteres): ";
        getline(cin, newMessageCI);
        // Verificar se os dados de não estão vazios
        newMessageCI = validateInput(newMessageCI, MENSSAGE_SIZE);

        formUpdate(idCI, newMessageCI, 4);
        successfulMessage();
      }
    }


  }
  else
    emptyMessage();
}

// Validação prévia da opção escolhida para fazer a atualização de campos do formulário
bool Form::validateInputToUpdate(char optUpdate) {
  if ((optUpdate == 'A') || (optUpdate == 'a'))
    return true;

  if ((optUpdate == 'B') || (optUpdate == 'b'))
    return true;

  if ((optUpdate == 'C') || (optUpdate == 'c'))
    return true;

  if ((optUpdate == 'D') || (optUpdate == 'd'))
    return true;
  
  return false;
}

// Retornar opção escolhida para fazer a atualização de campos do formulário
int Form::returnInputToUpdate(char optUpdate) {
    if ((optUpdate == 'A') || (optUpdate == 'a'))
    return 1;

  if ((optUpdate == 'B') || (optUpdate == 'b'))
    return 2;

  if ((optUpdate == 'C') || (optUpdate == 'c'))
    return 3;

  if ((optUpdate == 'D') || (optUpdate == 'd'))
    return 4;
}

// Realiza a atualização de acordo como o campo solicitado
void Form::formUpdate(string idCI, string fieldCI, int idField) {
  for (unsigned index = 0; index < Data.size(); index++) {
    if ((Data[index].getIdCI()) == idCI) {
      if (idField == 1)
        Data[index].setSenderCI(fieldCI);

      if (idField == 2)
        Data[index].setRecipientCI(fieldCI);

      if (idField == 3)
        Data[index].setSubjectCI(fieldCI);

      if (idField == 4)
        Data[index].setMessageCI(fieldCI);
    }
  }
}


