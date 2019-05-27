#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu {
  private:
    int Option;
    string OptDescription;

  public:
    Menu();
    ~Menu();
    void setMenu(int);
    int getMenu();
};

#endif
