// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef FORM_HPP
#define FORM_HPP

// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

// Tamanho padrão para armazenar os tamanhos das strings.
#define DATE_SIZE 100
#define SENDER_RECIPIENT_SUBJECT_SIZE 100 
#define MENSSAGE_SIZE 500 

// Padrões usados para a entradas do Menu, e tudo relacionado.
#define CREATE "Criar um novo registro de CI"
#define SELECT "Listar/Localizar um registro de CI"
#define UPDATE "Atualizar um registro de CI"
#define DELETE "Apagar um registro de CI"

// Uso refinado do Escopo STD
using std::string;
using std::vector;

// Declaração da Classe Form (Formulário de manipulação de dados)
class Form {
  private:
    // Declaração da Classe FormData que será nossa base de dados 
    class FormData {
      private:
        string idCI;
        string senderCI;
        string recipientCI;
        string subjectCI;
        string dateCI;
        string messageCI;
      
      public:
        // Construtor/Destrutor da Classe FormData
        FormData(string idCI, string senderCI, string recipientCI, string subjectCI, string dateCI, string messageCI);
        ~FormData();
        // Métodos da Classe FormData
        void setIdCI();
        void setSenderCI(string senderCI);
        void setRecipientCI(string recipientCI);
        void setSubjectCI(string subjectCI);
        void setDateCI();
        void setMessageCI(string menssageCI);
        string getIdCI();
        string getSenderCI();
        string getRecipientCI();
        string getSubjectCI();
        string getDateCI();
        string getMessageCI();
    };
    // Tornando nossa base de dados uma estrutrua de dados do tipo Vector 
    vector<FormData> Data;

  public:
    // Construtor/Destrutor da Classe FormData
    Form();
    ~Form();
    
    // Métodos de entrada/inserção de dados para serem gravados ou não
    void formCreate();
    void formSelect();
    void formUpdate();
    void formDelete();

    // Métodos da Classe Form (Basicamente farão as operações do CRUD)
    void crudCreate(string idCI, string senderCI, string recipientCI, string subjectCI, string dateCI, string messageCI);
    void crudSelect(string idCI);
    void crudUpdate(string idCI);
    void crudDelete(string idCI);

    // Método de geração de data
    string getSystemDate();
    // Método de validação de entrada de formulário
    string validateInput(string inputData, int optCheckIn);
    // Método de criaçaõ dos idCI, que sempre será único
    // Aqui, usamos uma string, por comodidade, e por conta do tamanho do campo (15)
    string createIdCI();
};
  
#endif  
