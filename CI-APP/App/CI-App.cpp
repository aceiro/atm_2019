#include <iostream>
#include "../Include/Menu.hpp"
#include "../Include/Help.hpp"
#include "../Include/Form.hpp"
#include "../Include/PrintingModule.hpp"
#include "../Include/QAModule.hpp"

using std::cout;
using std::endl;

int main() {
  cout << endl << "\tATM 2019 - CI-APP" << endl << endl;
  cout << endl << "\tListagem de Funcoes" << endl << endl;
  
  Menu menu;
  int x;
  //Exemplo (ainda sem uso de classes) de chamada do modulo de Menu
  menu.setMenu(x);
  cout << "Opcao escolhida" << menu.getMenu();

  //Exemplo (ainda sem uso de classes) de chamada do modulo de Ajuda
  Help();

  //Exemplo (ainda sem uso de classes) de chamada do modulo de Formulario de Dados
  FormTAD();
  FormCreate();
  FormUpdate();
  FormSelect();
  FormDelete();

  //Exemplo (ainda sem uso de classes) de chamada do modulo de Impressao
  PrintingModule();

  //Exemplo (ainda sem uso de classes) de chamada do modulo de Testes (Qualidade)
  QAModule();

  return 0;
}
