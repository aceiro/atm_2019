// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <locale.h> // Biblioteca interna do C++ para usar padrões de linguagem de acordo com o idioma
//#include <iomanip>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Components.hpp" // Classe Funções (Métodos) auxiliares (Pause, Limpa tela, etc...)
#include "../Include/ExternLib/MenuTemplate/MenuTemplate.hpp"// Classe Funções (Métodos) do MenuTemplate (Externo) 
#include "../Include/Help.hpp" // Classe Funções (Métodos) Ajuda/Sobre o sistema
#include "../Include/Form.hpp" // Classe Funções (Métodos) Manipulação do CRUD
#include "../Include/PrintingModule.hpp" // Classe Funções (Métodos) Impressão
#include "../Include/QAModule.hpp" // Classe Funções (Métodos) Testes

// Padrões usados para a entradas do Menu, e tudo relacionado.
#define END "Finalizar o Programa"

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
  Help help;
  MenuTemplate::MenuTemplate menu;

  // Declaração das váriaveis locais
  string option;
  
  // Rotina de título do Menutemplate (Ferramenta externa)
  menu.Title = "\t\tCI-App beta 1.1.50";
  menu.Description = "Mova setas (p/ Acima ou p/ Abaixo) para escolher uma opção: ";
  menu.setCursor(" -> ");

  // Rotina de instanciar entradas de Menu: a primeira String será usada para comparação do CRUD
  menu.addEntry("CREATE", CREATE);
  menu.addEntry("SELECT", SELECT);
  menu.addEntry("UPDATE", UPDATE);
  menu.addEntry("DELETE", DELETE);
  menu.addEntry("PRINT", PRINT);
  menu.addEntry("HELP", HELP);
  menu.addEntry("END", END);

  // Definindo posição e local de início do Cursor
  menu.swapEntries(2, "CREATE");
  menu.setCursorStartPosition(0);

  // Mainloop do programa usando um do...while
  do {
    // Variavel que armazena o valor retornando (string) da opção do menu
    option = menu.displayGetName();
    
    // Usando apenas uma estrutura if, pois switch não trabalha com comparações de strings
    if (option == "HELP") {
      help.displayHelpFile();
      components.pauseScreen();
    }
    
    if (option == "PRINT") {
      cout << PRINT << endl;
      components.pauseScreen();
    }

    if (option == "DELETE") {
      cout << DELETE << endl;
      components.pauseScreen();
    }

    if (option == "UPDATE") {
      cout << UPDATE << endl;
      components.pauseScreen();
    }

    if (option == "SELECT") {
      cout << SELECT << endl;
      components.pauseScreen();
    }
    
    if (option == "CREATE") {
      cout << CREATE << endl;
      components.pauseScreen();
    }

  } while (option != "END");
  
  // else
    // cout << menu.displayGetName() << endl;
  
  return 0;
}