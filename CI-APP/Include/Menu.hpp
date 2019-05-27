#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

using std::string;
using std::vector;

class Menu {
  private:
    class Entry {
      private:
        int Option;
        string OptDescription;

      public:
        Entry(int &Option, string &OptDescription);
        ~Entry();
        void setOption(int &Option);
        void setOptDescription(string &OptDescription);
        int getOption();
        string getOptDescription();
    };
    vector<Entry> Entries;

  public:
    string Title;
    Menu();
    ~Menu();
    void addEntry(int &Option, string &OptDescription);
    void addEntry(int &Option, string &OptDescription, int Position);
    void displayMenu(int Position);
};

#endif
