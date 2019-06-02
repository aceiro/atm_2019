// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef MENU_HPP
#define MENU_HPP

// Padrões usados para a entradas do Menu, e tudo relacionado.
#define END "Sair do Programa"

// Declaração das Bibliotecas internas do C++ 
#include <string>
#include <vector>

// Uso refinado do Escopo STD
using std::string;
using std::vector;

// Declaração da Classe Menu
class Menu {
  // Atributos da Classe primária
  private:
    // Declaração da Classe Option usanda como Atriuto da Classe Menu
    // Será usada e manipulada como uma TAD em nosso projeto
    class Option {
      private:
        int idOption;
        string descOption;

      public:
        // Inicialização da Classe
        Option(int idOption, string descOption);
        ~Option();
        void setIdOption(int idOption);
        void setDescOption(string descOption);
        int getIdOption();
        string getDescOption();
    };
    // Definição de optMenu como um "vector" do Tipo "Option"
    // Faz referência a nossa Classe Option, com os nossos modelos
    vector<Option> optMenu;

  public:
    // Atributo para definir Título do Menu 
    string menuTitle;
    // Inicialização da Classe
    Menu();
    ~Menu();
    // Métodos de manipulação da Classe
    void addOptMenu(int idOption, string descOption);
    void displayMenu();
};

#endif
