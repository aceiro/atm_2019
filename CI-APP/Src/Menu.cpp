#include <iostream>
#include <string>
#include "../Include/Menu.hpp"


using std::cout;
using std::cin;
using std::endl;
using std::string;

Menu::Option::Option(int idOption, string descOption) : idOption(idOption), descOption(descOption) {

}

Menu::Option::~Option() {

}

void Menu::Option::setIdOption(int idOption) {
  this->idOption = idOption;
}

void Menu::Option::setDescOption(string descOption) {
  this->descOption = descOption;
}

int Menu::Option::getIdOption() {
  return idOption;
}

string Menu::Option::getDescOption() {
  return descOption;
}

Menu::Menu() {

}

Menu::~Menu() {

}

void Menu::addOptMenu(int idOption, string descOption) {
  // if (optMenu.empty())
  //   optMenu.push_back(Option(idOption, descOption));
  // else
  //   optMenu.insert(optMenu.end(), Option(idOption, descOption));
  
  if (optMenu.empty())
    optMenu.insert(optMenu.begin(), Option(idOption, descOption));
    
  else
    optMenu.push_back(Option(idOption, descOption));

  // else
  //   optMenu.insert((optMenu.begin() + size), Option(idOption, descOption));
  

}

void Menu::displayMenu() {  
  cout << endl << "O tamanho do Vector é: " << optMenu.size() << endl;
  for (unsigned i = 0; i < optMenu.size(); i++) {
    cout << optMenu[i].getIdOption() << " - " << optMenu[i].getDescOption() << endl;
  }
  
  // return optMenu[0].getDescOption();
  // return 0;
} 