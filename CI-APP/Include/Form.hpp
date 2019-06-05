// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef FORM_HPP
#define FORM_HPP

// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <time.h>

// Padrões usados para a entradas do Menu, e tudo relacionado.
#define CREATE "Criar um novo registro de CI"
#define SELECT "Listar/Localizar um registro de CI"
#define UPDATE "Atualizar um registro de CI"
#define DELETE "Apagar um registro de CI"

// Uso refinado do Escopo STD
using std::string;
using std::time_get;


class Form {
  private:
    class FormData {
      private:
        int idCI;
        string senderCI;
        string recipientCI;
        string subjectCI;
        time_t dateCI;
        string messageCI;
      
      public:
        void setIdCI();
        // set
        

    };

  public:

};



#endif
