// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <locale.h>
#include <iomanip>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Components.hpp" // Classe Funções (Métodos) auxiliares (Pause, Limpa tela, etc...)
#include "../Include/Menu.hpp" // Classe Funções (Métodos) do Menu 
#include "../Include/Help.hpp" // Classe Funções (Métodos) Ajuda/Sobre o sistema
#include "../Include/Form.hpp" // Classe Funções (Métodos) Manipulação do CRUD
#include "../Include/PrintingModule.hpp" // Classe Funções (Métodos) Impressão
#include "../Include/QAModule.hpp" // Classe Funções (Métodos) Testes

// Uso refinado do Escopo STD
using std::cout;
using std::endl;
using std::right;
using std::string;

// Estrutura do Código Main
int main() {
  // Configurando para o código aceitar acentuação PT_BR
  setlocale(LC_ALL,"pt_BR_utf8");

  // Declaração/Instanciação das Classes, gerando os Objetos
  Components components;
  Menu menu;

  // Declaração de váriaveis de apoio
  int recChoiceMenu;
  string recChoiceStringMenu;
  
  // Definição do Título principal
  components.mainTitle = "CI-App beta 1.0.10";
  
  // Definição do Título do Menu
  menu.menuTitle = "Menu - Entre com o número da Opção:";
  
  // Código de manutenção: "limpeza" de tela
  components.clearScreen();
  
  // Impressão (Formatada) do título do programa na tela
  cout << endl;
  cout.width(40);
  cout << right << components.mainTitle << endl << endl;

  // Impressão (Formatada) do título do Menu na tela
  cout.width(59);
  cout << right << menu.menuTitle << endl;

  // Entradas do Menu: são "#defines" (Constantes) presentes em ""../Includes/*"
  menu.addOptMenu(1, CREATE);
  menu.addOptMenu(2, SELECT);
  menu.addOptMenu(3, UPDATE);
  menu.addOptMenu(4, DELETE);
  menu.addOptMenu(5, HELP);
  menu.addOptMenu(6, PRINT);
  menu.addOptMenu(7, END);
  
  // Impressão da Opções do Menu
  menu.displayMenu();

  // Escolha do Menu (ainda retornando para o Main -> no futuro só retorna quando finaliza o programa)
  menu.setChoiceMenu();
  
  // Imprimindo a Opção (número) (ainda retornando para o Main -> no futuro só retorna quando finaliza o programa)
  recChoiceMenu = menu.getChoiceMenu();
  cout << endl << "Escolha do Menu: " << recChoiceMenu;

  // Imprimindo a Opção (descrição) (ainda retornando para o Main -> no futuro só retorna quando finaliza o programa)
  recChoiceStringMenu = menu.getChoiceStringMenu();
  cout << " - " << recChoiceStringMenu << endl;
  
  // Código de manutenção: "Pause" e limpeza de tela
  components.pauseScreen();
  components.clearScreen();
  
  return 0;
}
