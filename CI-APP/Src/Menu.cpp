#include <iostream>
#include "../Include/Menu.hpp"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Menu::Menu(){

}

Menu::~Menu(){

}

void Menu::setMenu(int Option){
  do{
    cout << endl << "Escolha uma das Opcoes do Menu:" << endl;
    cout << "1 - Criar CI" << endl;
    cout << "2 - Pesquisar CI" << endl;
    cout << "3 - Atualizar um registro de CI" << endl;
    cout << "4 - Apagar um registro de CI" << endl;
    cout << "0 - Sair" << endl;
    cin >> Option;

    switch(Option){
      case 1:
        this->Option = Option; 
        this->OptDescription = "Criar CI";
        break;
      case 2:
        this->Option = Option;
        this->OptDescription = "Pesquisar CI";
        break;
      case 3:
        this->Option = Option;
        this->OptDescription = "Atualizar CI";
        break;
      case 4:
        this->Option = Option;
        //cout << "Apagar CI" << endl;
        break;
      case 0:
        this->Option = Option;
        //cout << "Saindo do Programa" << endl;
        break;
      default:
        this->Option = 100;
        //cout << "Opcao escolhida, nao existe, saindo" << endl;
        break;
    }
  } while(Option != 0);
}

int Menu::getMenu(){
  return this->Option;
}
