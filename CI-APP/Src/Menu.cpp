// Utilização de Bibliotecas internas do C++
#include <iostream>
#include <string>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Menu.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Desenvolvimento do código Construtor Classe Option
Menu::Option::Option(int idOption, string descOption) : idOption(idOption), descOption(descOption) {

}

// Destrutor da Classe
Menu::Option::~Option() {

}

// Desenvolvimento do método setIdOption: atribui a entrada para dentro da classe
void Menu::Option::setIdOption(int idOption) {
  this->idOption = idOption;
}

// Desenvolvimento do método setdescOption: atribui a entrada para dentro da classe
void Menu::Option::setDescOption(string descOption) {
  this->descOption = descOption;
}

// Desenvolvimento do método getIdOption: retorna entrada
int Menu::Option::getIdOption() {
  return idOption;
}

// Desenvolvimento do método getDescOption: retorna entrada
string Menu::Option::getDescOption() {
  return descOption;
}

// Desenvolvimento do código Construtor Classe Menu
Menu::Menu() {

}

// Destrutor da Classe
Menu::~Menu() {

}

// Desenvolvimento do método addOptMenu: entrada de campos do Menu (ID e Descrição)
void Menu::addOptMenu(int idOption, string descOption) {
  // Condicional para dar entradas dos dados em nossa estrutura Vector
  
  // Caso esteja vázio, a entrada ocorre na primeira posição
  if (optMenu.empty())
    optMenu.insert(optMenu.begin(), Option(idOption, descOption));
  
  // Caso contrário, a entrada ocorre na última posição disponível
  else
    optMenu.push_back(Option(idOption, descOption));
}

// Desenvolvimento do método displayMenu: Imprimindo as opções em tela
void Menu::displayMenu() {  
  
  // Usando laço para correr todas as posições da estrutrua Vector, para imprimir as opções do Menu 
  for (unsigned i = 0; i < optMenu.size(); i++)
    cout << "\t" << optMenu[i].getIdOption() << " - " << optMenu[i].getDescOption() << endl;
  
  cout << endl;
} 

// Desenvolvimento do método setOptMenu: estrutura de escolha da opção do Menu (ainda não completa)
void Menu::setChoiceMenu() {
  // while (!choiceMenu) {
    cout << "\t Qual é sua escolha: ";
    cin >> choiceMenu;
    switch (choiceMenu) {
    case 1:
      this->choiceMenu = choiceMenu;
      break;
    case 2:
      this->choiceMenu = choiceMenu;
      break;
    case 3:
      this->choiceMenu = choiceMenu;
      break;
    case 4:
      this->choiceMenu = choiceMenu;
      break;
    case 5:
      this->choiceMenu = choiceMenu;
      break;
    case 6:
      this->choiceMenu = choiceMenu;
      break;
    case 7:
      this->choiceMenu = choiceMenu;
      break;
    default:
      cout << endl << choiceMenu << "Não faz parte do escopo" << endl;
      this->choiceMenu = choiceMenu;
      break;
    }
  // }
  
}

// Desenvolvimento do método getOptMenu: retorna escolha do usuário (ainda retorna para main *)
int Menu::getChoiceMenu() {
  return this->choiceMenu;
}

// Desenvolvimento do método getOptStringMenu: retorna escolha (string) do usuário (ainda retorna para main *)
string Menu::getChoiceStringMenu() {
  for (unsigned i = 0; i < optMenu.size(); i++) {
    if (this->choiceMenu == optMenu[i].getIdOption())
      return optMenu[i].getDescOption();
  }
  
  return "Não existe";
}