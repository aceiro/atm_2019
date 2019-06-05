#include <iostream>
#include <string>
#include <stdlib.h>
#include "../Include/Components.hpp"

using std::cout;
using std::endl;
using std::string;

Components::Components() {

}

Components::~Components() {

}

void Components::clearScreen() {
  system("cls || clear");
}

void Components::pauseScreen() {
  getchar();
  // getchar();
}