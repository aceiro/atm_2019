// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <locale.h> // Biblioteca interna do C++ para usar padrões de linguagem de acordo com o idioma

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Module/QAModule.hpp" // Classe Funções (Métodos) Testes
#include "../../Include/Components.hpp" // Classe Funções (Métodos) auxiliares (Pause, Limpa tela, etc...)
#include "../../Include/Form.hpp" // Classe Funções (Métodos) Manipulação do CRUD

// Uso refinado do Escopo STD
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

// Estrutura do Código Main
int main() {
  // Configurando para o código aceitar acentuação PT_BR
  setlocale(LC_ALL,"pt_BR_utf8");

  // Instanciando as Classes
  QAModule testApp;
  Form testAppForm;
  Components testAppComponents;

  // Váriaveis locais
  string recIdCI;
  string auxRecIdCI;
  string recSenderCI;
  string recRecipientCI;
  string recSubjectCI;
  string recDateCI;
  string recMessageCI;
  char optACI = '\0';
  char optBCI = '\0';
  char optCCI = '\0';
  char optDCI = '\0';

  testAppComponents.clearScreen();
  
  cout << endl << endl << "\t\t" << QAMODULE_TITLE << endl << endl;
  // Teste em funções do módulo  Form (Create)
  cout << "1 - TESTE DE ENTRADA DE DADOS" << endl << endl;
  cout << "INSIRA O CAMPO [ DE ]: ";
  getline(cin, recSenderCI);
  cout << "INSIRA O CAMPO [ PARA ]: ";
  getline(cin, recRecipientCI);
  cout << "INSIRA O CAMPO [ ASSUNTO ]: ";
  getline(cin, recSubjectCI);
  cout << "INSIRA O CAMPO [ MENSAGEM ]: ";
  getline(cin, recMessageCI);
  recDateCI = testAppForm.getSystemDate();
  recIdCI = testAppForm.createIdCI();
  testApp.createTest(recIdCI, recSenderCI, recRecipientCI, recSubjectCI, recDateCI, recMessageCI);
  cout << endl << endl << "\t\t" << "Teste 1 OK!!!" << endl << endl;
  
  testAppComponents.pauseScreen();
  testAppComponents.clearScreen();

  cout << endl << endl << "\t\t" << QAMODULE_TITLE << endl << endl;
  // Teste em funções do módulo  Form (Select)
  cout << "2 - TESTE DE CONSULTA DE DADOS" << endl << endl;
  cout << "USANDO O ID. " << recIdCI << " PARA TESTAR A CONSULTA DE DADOS." << endl;
  cout << "ENTRE COM [ ID. ]: ";
  getline(cin, auxRecIdCI);
  testApp.selectTest(auxRecIdCI);
  cout << endl << endl << "\t\t" << "Teste 2 OK!!!" << endl << endl;

  testAppComponents.pauseScreen();
  testAppComponents.clearScreen();

  cout << endl << endl << "\t\t" << QAMODULE_TITLE << endl << endl;
  // Teste em funções do módulo  Form (Update)
  cout << "3 - TESTE DE ATUALIZAÇÃO DE DADOS" << endl << endl;
  cout << "AQUI, ENTRE DA SEGUINTE FORMA:" << endl;
  cout <<  "\t[ A ] - Campo [ DE: ]" << endl;
  cout <<  "\t[ B ] - Campo [ PARA: ]" << endl;
  cout <<  "\t[ C ] - Campo [ ASSUNTO: ]" << endl;
  cout <<  "\t[ D ] - Campo [ MENSAGEM: ]" << endl;
  cout << "USANDO O ID. " << recIdCI << " PARA TESTAR A CONSULTA DE DADOS." << endl;
  cout << "ENTRE COM [ ID. ]: ";
  getline(cin, auxRecIdCI);
  cout << "DIGITE | A ou a|: ";
  cin >> optACI;
  cin.ignore();
  cout << "DIGITE ATUALIZAÇÃO PARA O CAMPO | DE: |: ";
  getline(cin, recSenderCI);
  cout << "DIGITE | B ou b |: ";
  cin >> optBCI;
  cin.ignore();
  cout << "DIGITE ATUALIZAÇÃO PARA O CAMPO | PARA: |: ";
  getline(cin, recRecipientCI);
  cout << "DIGITE | C ou c |: ";
  cin >> optCCI;
  cin.ignore();
  cout << "DIGITE ATUALIZAÇÃO PARA O CAMPO | ASSUNTO: |: ";
  getline(cin, recSubjectCI);
  cout << "DIGITE | D ou d |: ";
  cin >> optDCI;
  cin.ignore();
  cout << "DIGITE ATUALIZAÇÃO PARA O CAMPO | MENSAGEM: |: ";
  getline(cin, recMessageCI);
  testApp.updateTest(auxRecIdCI, recSenderCI, recRecipientCI, recSubjectCI, recDateCI, recMessageCI, optACI, optBCI, optCCI, optDCI);
  cout << endl << endl << "\t\t" << "Teste 3 OK!!!" << endl << endl;

  testAppComponents.pauseScreen();
  testAppComponents.clearScreen();

  cout << endl << endl << "\t\t" << QAMODULE_TITLE << endl << endl;
  // Teste em funções do módulo  Form (Delete)
  cout << "4 - TESTE DE EXCLUSÃO DE DADOS" << endl << endl;
  cout << "USANDO O ID. " << recIdCI << " PARA TESTAR A CONSULTA DE DADOS." << endl;
  cout << "ENTRE COM [ ID. ] PARA EXCLUSÃO: ";
  getline(cin, auxRecIdCI);
  testApp.deleteTest(auxRecIdCI);
  cout << endl << endl << "\t\t" << "Teste 4 OK!!!" << endl << endl;

  testAppComponents.pauseScreen();
  testAppComponents.clearScreen();

  cout << endl << endl << "\t\t" << QAMODULE_TITLE << endl << endl;
  // Teste em funções do módulo  PritingModule (print)
  cout << "5 - TESTE DE IMPRESSÃO DE DADOS" << endl << endl;
  recDateCI = testAppForm.getSystemDate();
  recIdCI = testAppForm.createIdCI();
  cout << "USANDO O ID. " << recIdCI << " PARA TESTAR A CONSULTA DE DADOS." << endl;
  testApp.createTest(recIdCI, recSenderCI, recRecipientCI, recSubjectCI, recDateCI, recMessageCI);
  testApp.printTest(recIdCI);
  cout << endl << endl << "\t\t" << "Teste 5 OK!!!" << endl << endl;

  testAppComponents.pauseScreen();
  testAppComponents.clearScreen();

  return 0;
}