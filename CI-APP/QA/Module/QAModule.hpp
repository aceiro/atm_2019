// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef QAMODULE_HPP
#define QAMODULE_HPP

// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>

// Títulos das Janela
#define QAMODULE_TITLE "MÓDULO DE TESTES - CI-App"

// Uso refinado do Escopo STD
using std::string;

// Declaração da Classe de Testes
class QAModule {
  private:
    string testIdCI;
    string testSenderCI;
    string testRecipientCI;
    string testSubjectCI;
    string testDateCI;
    string testMessageCI;
    string testPrintCI;

  public:
    // Construtor/Destrutor da Classe FormData
    QAModule();
    ~QAModule();

    // Métodos da Classe QAModule (Testando os métodos do CRUD e Impressão)
    void createTest(string testIdCI, string testSenderCI, string testRecipientCI, string testSubjectCI, string testDateCI, string testMessageCI);
    void selectTest(string testIdCI);
    void updateTest(string test);
    void deleteTest(string testIdCI);
    void printTest(string testIdCI);
    int capacityTest(string testIdCI, string testSenderCI, string testRecipientCI, string testSubjectCI, string testDateCI, string testMessageCI);
};

#endif
