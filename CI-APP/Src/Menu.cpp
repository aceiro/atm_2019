#include <iostream>
#include "../Include/Menu.hpp"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

Menu::Entry::Entry(int &Option, string &OptDescription) : Option(Option), OptDescription(OptDescription) {
}

Menu::Entry::~Entry() {
}

void Menu::Entry::setOption(int &Option) {
  this->Option = Option;
}

void Menu::Entry::setOptDescription(string &OptDescription) {
  this->OptDescription = OptDescription;
}

int Menu::Entry::getOption() {
  return Option;
}

string Menu::Entry::getOptDescription() {
  return OptDescription;
}

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::addEntry(int &Option, string &OptDescription) {
  Menu::addEntry(Option, OptDescription, Entries.size());
}

void Menu::addEntry(int &Option, string &OptDescription, int Position) {
  //for (int counter = 0; counter < Entries.size(); ++counter)
  if ((Position < 0) || (Position > Entries.size()))
    Entries.push_back(Entry(Option, OptDescription));
  else
    Entries.insert(Entries.begin() + Position, Entry(Option, OptDescription));
}

void Menu::displayMenu(int Position) {
  while (Position != Entries.size()) {
    cout << "teste 1" << " - " << "teste 2" << endl;

  }
}
