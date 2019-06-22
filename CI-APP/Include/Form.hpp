// Cabeçalho obrigatório na criação / declaração do arquivo das Classes
#ifndef FORM_HPP
#define FORM_HPP

// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#define NUMBER_OF_ATTMPTS 5

// Títulos das Janelas do CRUD (Formúlario)
#define CREATE_FORM_TITLE "MÓDULO DE CADASTRO - INSERIR UMA CI"
#define SELECT_FORM_TITLE "MÓDULO DE CONSULTA - PESQUISE UMA CI"
#define UPDATE_FORM_TITLE "MÓDULO DE ATUALIZAÇÃO - MODIFIQUE UMA CI"
#define DELETE_FORM_TITLE "MÓDULO DE REMOÇÃO - REMOVA UMA CI"

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
        void setMessageCI(string messageCI);
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
    void formCreate(string idCI, string senderCI, string recipientCI, string subjectCI, string dateCI, string messageCI);
    void formSelect();
    bool formSelect(string idCI);
    void displaySelectCI(string idCI);
    void displaySelectCI(string idCI, string toUpdate);
    void displayRecordsReport();
    void formUpdate();
    void formUpdate(string idCI, string fieldCI, int idField);
    void formDelete();

    // Método de geração de data
    string getSystemDate();
    // Método de validação de entrada de formulário
    string validateInput(string inputData, int optCheckIn);
    // Método auxiliar para validação na entrada de dados de formulário
    bool auxValidateInput(string inputData, int optCheckIn);
    // Método para validação prévia da opção escolhida para fazer a atualização de campos do formulário
    bool validateInputToUpdate(char opUpdate);
    // Método para retornar opção escolhida para fazer a atualização de campos do formulário
    int returnInputToUpdate(char opUpdate);
    // Método de criaçaõ dos idCI, que sempre será único
    // Aqui, usamos uma string, por comodidade, e por conta do tamanho do campo (15)  
    string createIdCI();
    // Método para mensagem de sucesso na operação
    void successfulMessage();
    // Método para mensagem de que não existem dados gravados
    void emptyMessage();
    // Método para mensagem quando não encontrar o dados procurador
    void recordNotFoundMenssage();
    // Método para mensagem de cancelamento do processo
    void abortingProcessMessage();
    // Método para mensagem de como o cadastro deve ser informado
    void inputStandardMessage();
};
  
#endif  