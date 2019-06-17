// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <iomanip> // Biblioteca interna do C++ para trabalhar com alinhamento (width, right, etc)

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


void Form::formSelect() {
  string idCI;
  int escape = 0;
  
  if (!Data.empty()) {
    // Imprimindo todas os Registros de CI
    displayRecordsReport();

    do {
      // Escolhendo qual será o registro a ser retornado, para ver recuperar todos os dados
      cout << endl << "CONSULTAR ID. (escolha entre os registros acima): ";
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

    displaySelectCI(idCI);
    successfulMessage();
  }
  else
    emptyMessage();
}

// Método para verificar se um registro está presente na estrutura de dados
bool Form::formSelect(string idCI) {
  for (unsigned index = 0; index < Data.size(); index++) {
    // Condição para ser que o registro exista
    if ((Data[index].getIdCI()) == idCI)
      return true;
  }

  return false;
}

// Método para imprimir (Formulário de impressão) a CI que tem a referência do ID utilizado
void Form::displaySelectCI(string idCI) {
  for (unsigned index = 0; index < Data.size(); index++) {
    if ((Data[index].getIdCI()) == idCI) {
      cout << endl << endl;
      cout << "ID.: "; 
      cout << setw(49) << left << Data[index].getIdCI();
      cout << "DATA: ";
      cout << setw(15) << left << Data[index].getDateCI();
      cout << endl << endl;
      cout << "DE: ";
      cout << setw(50) << left << Data[index].getSenderCI();
      cout << "PARA: ";
      cout << setw(50) << left << Data[index].getRecipientCI();
      cout << endl << endl;
      cout << "ASSUNTO: ";
      cout << setw(100) << left << Data[index].getSubjectCI();
      cout << endl << endl;
      cout << "MENSAGEM: ";
      cout << setw(500) << left << Data[index].getMessageCI();
      cout << endl << endl;
    }
  }
}

// Método para imprimir (Uso no método UPDATE) a CI que tem a referência do ID utilizado
void Form::displaySelectCI(string idCI, string toUpdate) {
  for (unsigned index = 0; index < Data.size(); index++) {
    if ((Data[index].getIdCI()) == idCI) {
      cout << endl << endl;
      cout << "ID.: "; 
      cout << setw(49) << left << Data[index].getIdCI();
      cout << "DATA: ";
      cout << setw(15) << left << Data[index].getDateCI();
      cout << endl << endl;
      cout << "[A] - DE: ";
      cout << setw(50) << left << Data[index].getSenderCI();
      cout << endl << endl;
      cout << "[B] - PARA: ";
      cout << setw(50) << left << Data[index].getRecipientCI();
      cout << endl << endl;
      cout << "[C] - ASSUNTO: ";
      cout << setw(100) << left << Data[index].getSubjectCI();
      cout << endl << endl;
      cout << "[D] - MENSAGEM: ";
      cout << setw(500) << left << Data[index].getMessageCI();
      cout << endl << endl;
    }
  }
}

// Método para mensagem padrão de registro não encontrado, quando a estrutura de dados está vazia
void Form::emptyMessage() {
  cout << endl << endl << "\t\tNenhum registro foi encontrado!!!" << endl << endl;
}

// Método para Imprimir uma especie de relatórios de registros.
void Form::displayRecordsReport() {
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
}

// Método para mensagem padrão para cancelar o processo
void Form::abortingProcessMessage() {
  cout << endl << endl << "\t\tAbortando Processo..." << endl << endl;
}

// Método para mensagem padrão de quando registro procurado não foi encontrado.
void Form::recordNotFoundMenssage() {
  cout << endl << endl << "\t\tRegistro não encontrado..." << endl << endl;
}