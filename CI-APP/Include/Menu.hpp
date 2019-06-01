#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

class Menu {
  private:
    class Option {
      private:
        int idOption;
        string descOption;

      public:
        Option(int idOption, string descOption);
        ~Option();
        void setIdOption(int idOption);
        void setDescOption(string descOption);
        int getIdOption();
        string getDescOption();
    };
    vector<Option> optMenu;

  public:
    string menuTitle;
    Menu();
    ~Menu();
    void addOptMenu(int idOption, string descOption);
    void displayMenu();
};

#endif
