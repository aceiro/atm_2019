#include <iostream>
#include <locale.h>
#include <iomanip>
#include "../Include/Components.hpp"
#include "../Include/Menu.hpp"
#include "../Include/Help.hpp"
#include "../Include/Form.hpp"
#include "../Include/PrintingModule.hpp"
#include "../Include/QAModule.hpp"

using std::cout;
using std::endl;
using std::right;

int main() {
  setlocale(LC_ALL,"pt_BR_utf8");
  Components components;
  Menu menu;

  components.mainTitle = "Comunicado Interno - CI - Asser RC";
  menu.menuTitle = "Menu Principal - Entre com uma das Opções abaixo:";
  
  components.clearScreen();
  cout << endl;
  cout.width(40);
  cout << right << components.mainTitle << endl << endl;

  cout.width(57);
  cout << right << menu.menuTitle << endl;

  menu.addOptMenu(1, "Cadastrar");
  menu.addOptMenu(2, "Selecionar");
  menu.addOptMenu(3, "Alterar");
  menu.addOptMenu(4, "Exlcluir");
  menu.addOptMenu(5, "00000");
  menu.addOptMenu(5, "111111");
  
  menu.displayMenu();
  components.pauseScreen();
  components.clearScreen();
  
  return 0;
}
