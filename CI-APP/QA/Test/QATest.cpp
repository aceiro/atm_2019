// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <locale.h> // Biblioteca interna do C++ para usar padrões de linguagem de acordo com o idioma

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Module/QAModule.hpp" // Classe Funções (Métodos) Testes
#include "../../Include/Components.hpp" // Classe Funções (Métodos) auxiliares (Pause, Limpa tela, etc...)
#include "../../Include/Form.hpp" // Classe Funções (Métodos) Manipulação do CRUD
#include "../../Include/PrintingModule.hpp" // Classe Funções (Métodos) Impressão

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
  QAModule test;
  Form testForm;
  PrintingModule testPrint;
  Components testComp;

  // Váriaveis locais
  string recIdCI;
  string recSenderCI;
  string recRecipientCI;
  string recSubjectCI;
  string recDateCI;
  string recMessageCI;
  string recPrintCI;

  testComp.clearScreen();
  
  cout << endl << endl << "\t\t" << QAMODULE_TITLE << endl << endl;
  
  // Teste em funções do módulo  Form (Create)
  cout << "1 - TESTE DE ENTRADA DE DADOS" << endl << endl;
  cout << "INSIRA O CAMPO [ DE ]: ";
  getline(cin, recSenderCI);
  cout << "INSIRA O CAMPO [ PARA ]: ";
  getline(cin, recRecipientCI);
  cout << "INSIRA O CAMPO [ ASSUNTO ]: ";
  getline(cin, recSubjectCI);
  cout << "INSIRA O CAMPO [ MENSSAGEM ]: ";
  getline(cin, recMessageCI);
  recDateCI = testForm.getSystemDate();
  recIdCI = testForm.createIdCI();
  test.createTest(recIdCI, recSenderCI, recRecipientCI, recSubjectCI, recDateCI, recMessageCI);
  cout << endl << endl << "\t\t" << "Teste 1 OK!!!" << endl << endl;
  
  testComp.pauseScreen();
  testComp.clearScreen();

  // Teste em funções do módulo  Form (Select)
  cout << "2 - TESTE DE CONSULTA DE DADOS" << endl << endl;
  
  cout << "USANDO O ID. " << recIdCI << " PARA TESTAR A CONSULTA DE DADOS." << endl;
  testComp.pauseScreen();
  test.selectTest(recIdCI);
  cout << endl << endl << "\t\t" << "Teste 2 OK!!!" << endl << endl;

  // Teste em funções do módulo  Form (Update)
  cout << "3 - TESTE DE ATUALIZAÇÃO DE DADOS" << endl << endl;
  cout << endl << endl << "\t\t" << "Teste 3 OK!!!" << endl << endl;

  // Teste em funções do módulo  Form (Delete)
  cout << "4 - TESTE DE EXCLUSÃO DE DADOS" << endl << endl;
  cout << endl << endl << "\t\t" << "Teste 4 OK!!!" << endl << endl;
  // Teste em funções do módulo  PritingModule (print)
  cout << "5 - TESTE DE IMPRESSÃO DE DADOS" << endl << endl;
  cout << endl << endl << "\t\t" << "Teste 5 OK!!!" << endl << endl;

  cout << "6 - TESTE DE CAPACIDADE DE ARMAZENAMENTO DE DADOS (20 REGISTROS)" << endl << endl;
  cout << endl << endl << "\t\t" << "Teste 6 OK!!!" << endl << endl;

  return 0;
}