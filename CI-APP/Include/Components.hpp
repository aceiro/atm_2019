#ifndef COMPONENTS_HPP_INCLUDED
#define COMPONENTS_HPP_INCLUDED

#include <iostream>
#include <string>

using std::string;

class Components {
  private:
    
  public:
    Components();
    ~Components();
    string mainTitle;
    void clearScreen();
    void pauseScreen();
};

#endif