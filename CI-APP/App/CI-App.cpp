// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <locale.h>
//#include <iomanip>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Components.hpp" // Classe Funções (Métodos) auxiliares (Pause, Limpa tela, etc...)
#include "../Include/ExternLib/MenuTemplate/MenuTemplate.hpp"// Classe Funções (Métodos) do MenuTemplate (Externo) 
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
  MenuTemplate::MenuTemplate menu;
  
  // Rotina de título do Menutemplate (Ferramenta externa)
  menu.Title = "\t\tCI-App beta 1.1.40";
  menu.Description = "Mova setas (p/ Acima ou p/ Abaixo) para escolher uma opção: ";
  menu.setCursor("> ");

  // Rotina de instanciar entradas de Menu: a primeira String será usada para comparação do CRUD
  menu.addEntry("CREATE", "Criar um novo registro de CI");
  menu.addEntry("SELECT", "Listar/Localizar um registro de CI");
  menu.addEntry("UPDATE", "Atualizar um registro de CI");
  menu.addEntry("DELETE", "Apagar um registro de CI");
  menu.addEntry("PRINT", "Imprimir um registro de CI");
  menu.addEntry("HELP", "Ajuda / Sobre");
  menu.addEntry("END", "Finalizar o Programa");

  // Definindo posição e local de início do Cursor
  menu.swapEntries(2, "CREATE");
  menu.setCursorStartPosition(0);

  // Aqui ainda estamos apenas retornado o que vai ser comparado para o CRUD.
  // Posteriormente usaremos o método set para enviar para o CRUD.
  cout << menu.displayGetName() << endl;
 
  return 0;
}
