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
  string fieldCI;
  int escape = 0;
  char optUpdate;
  
  // Reutilizando a rotina de buscar uma CI, para mostrar o Relatório de CIs existente
  // e recuperar um registro para visualizar o campo a ser alterado.
  formSelect();

  do {
    cout << endl << "Enre novamente com ID.: ";
    getline(cin, idCI);
    
    escape++;
    
    if (escape == 5) {
      recordNotFoundMenssage();
      abortingProcessMessage();
      return;
    }
  } while (!formSelect(idCI));

  cout << endl << endl;
  cout << "DIGITE 1 - ATUALIZAR CAMPO [ DE: ] -- ";
  cout << "DIGITE 2 - ATUALIZAR CAMPO [ PARA: ] -- ";
  cout << "DIGITE 3 - ATUALIZAR CAMPO [ ASSUNTO: ] -- ";
  cout << "DIGITE 4 - ATUALIZAR CAMPO [ MENSAGEM: ]";
  cout << endl << endl << "SUA OPÇÃO: ";
  cin >> optUpdate;

  switch (optUpdate) {
    case '1':
      // 
      cout << endl << endl << "Alterar para : ";
      getline(cin, fieldCI);
      // usar algum método de validação
      formUpdate(idCI, fieldCI, optUpdate);
      break;
    case '2':
      // 
      cout << endl << endl << "Alterar para : ";
      getline(cin, fieldCI);
      // usar algum método de validação
      formUpdate(idCI, fieldCI, optUpdate);
      break;
    case '3':
      // 
      cout << endl << endl << "Alterar para : ";
      getline(cin, fieldCI);
      // usar algum método de validação
      formUpdate(idCI, fieldCI, optUpdate);
      break;
    case '4':
      // 
      cout << endl << endl << "Alterar para : ";
      getline(cin, fieldCI);
      // usar algum método de validação
      formUpdate(idCI, fieldCI, optUpdate);
      break;
    default:
      // Mensagens padão para quando 
      abortingProcessMessage();
      break;
  }
}

// Método para recuperar um ID que foi validado
void Form::formUpdate(string idCI, string fieldCI, char optUpdate) {
  // Altear, usando a flag 1, para determinar, e insere fieldCI na posição do senderCI
  if (optUpdate == '1') {
    for (unsigned index = 0; index < Data.size(); index++) {
      // Condição de retorno
      if ((Data[index].getIdCI()) == idCI) {
        // return idCI;
        // Data[index].setSenderCI(fieldCI);
        Data.insert(Data.begin() + index, FormData(fieldCI));
      }
    }
  }

  // Altear, usando a flag 2, para determinar, e insere fieldCI na posição do recipientCI
  if (optUpdate == '2') {
    for (unsigned index = 0; index < Data.size(); index++) {
      // Condição de retorno
      if ((Data[index].getIdCI()) == idCI) {
        // return idCI;
        Data[index].setRecipientCI(fieldCI);
      }
    }
  }

  // Altear, usando a flag 3, para determinar, e insere fieldCI na posição do subjectCI
  if (optUpdate == '3') {
    for (unsigned index = 0; index < Data.size(); index++) {
      // Condição de retorno
      if ((Data[index].getIdCI()) == idCI) {
        // return idCI;
        Data[index].setSubjectCI(fieldCI);
      }
    }
  }

  // Altear, usando a flag 4, para determinar, e insere fieldCI na posição do messageCI
  if (optUpdate == '4') {
    for (unsigned index = 0; index < Data.size(); index++) {
      // Condição de retorno
      if ((Data[index].getIdCI()) == idCI) {
        // return idCI;
        Data[index].setMessageCI(fieldCI);
      }
    }
  }
}

