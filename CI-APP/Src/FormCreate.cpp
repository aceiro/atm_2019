// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>
#include <ctime> // Biblioteca interna do C++ para usar padrões de data hora do sistema
#include <cctype> // Biblioteca interna do C++ para usar "isdigit"

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Form.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::string;

void Form::formCreate() {
  // Váriaveis para inserção no Formulário
  string idCI;
  string senderCI; // SENDER_RECIPIENT_SUBJECT_SIZE
  string recipientCI; // SENDER_RECIPIENT_SUBJECT_SIZE
  string subjectCI; // SENDER_RECIPIENT_SUBJECT_SIZE
  string dateCI; 
  string messageCI; // SENDER_RECIPIENT_SUBJECT_SIZE

  // Entrada de dados
  cout << endl << endl << "\tObs.: Entre com dados válidos! Não omita nenhum campo!" << endl << endl;

  cout << endl << "DE (max 100 caracteres): ";
  getline(cin, senderCI);
  // Verificar se os dados de não estão vazios
  senderCI = validateInput(senderCI, SENDER_RECIPIENT_SUBJECT_SIZE);

  cout << endl << "PARA (max 100 caracteres): ";
  getline(cin, recipientCI);
  // Verificar se os dados de não estão vazios
  recipientCI = validateInput(recipientCI, SENDER_RECIPIENT_SUBJECT_SIZE);

  cout << endl << "ASSUNTO (max 100 caracteres): ";
  getline(cin, subjectCI);
  // Verificar se os dados de não estão vazios
  subjectCI = validateInput(subjectCI, SENDER_RECIPIENT_SUBJECT_SIZE);

  cout << endl << "MENSAGEM (max 500 caracteres): ";
  getline(cin, messageCI);
  // Verificar se os dados de não estão vazios
  messageCI = validateInput(messageCI, MENSSAGE_SIZE);

  // Inicialização das Váriaveis dataCI
  dateCI = getSystemDate();

  // idCI é uma string resultante da concatenação de ano+mes+dia+hora+minuto+segundos
  idCI = createIdCI();

  // Criar rotina de utilizar do crudCreate
  formCreate(idCI, senderCI, recipientCI, subjectCI, dateCI, messageCI);

  // Rertorna da Mensagem de confirmação do procedimento.
  successfulMessage();
}

void Form::formCreate(string idCI, string senderCI, string recipientCI, string subjectCI, string dateCI, string messageCI) {
  // Verificação da Posição a ser inserido, e inserção
  // Insere no início, quando a estrutura de dados está vazia
  if (Data.empty())
    Data.insert(Data.begin(), FormData(idCI, senderCI, recipientCI, subjectCI, dateCI, messageCI));

  // Insere no final, quando já existir algum registro na estrtutura de dados
  else
    Data.push_back(FormData(idCI, senderCI, recipientCI, subjectCI, dateCI, messageCI));
}

// Conversão de tipo data para string
string Form::getSystemDate() {
  // "t_Date" será nossa váriavel para passagem de referênica dos valores de data
  time_t t_Date;

  // "tm" é um estrutura interna do C++ que indica atributos do tipo TIME
  struct tm *timeInfo;

  // "buffer" será atribuída a "sBuffer", e será nosso retorno com data formatada
  char buffer[DATE_SIZE];
  string sBuffer;

  // Usando a função "time" (Interna do C++) passando como referência "t_Date"
  time(&t_Date);

  // Usando a função "localtime", e passando nossa "t_Date", para "timeInfo",
  // que é onde temos a entrada da data sem formatação 
  timeInfo = localtime(&t_Date);

  // "strftime", converte nosso tipo de data para uma string, que nosso caso é o "buffer"
  strftime(buffer, DATE_SIZE, "%d/%m/%Y", timeInfo);

  // retornamos nossa string, para que seja usada no restante do programa
  sBuffer = buffer;
  return sBuffer;
}

// Gerando código idCI (código único) 
// reutilizando trechos do código da hora formatada.
string Form::createIdCI() {
  time_t t_Date;
  struct tm *timeInfo;
  char cd[DATE_SIZE];
  string sCd;
  // double id;
  
  time(&t_Date); 
  timeInfo = localtime(&t_Date);

  // "strftime", converte nosso tipo de data para uma string: 
  // ano(4)%mes(2)%dia(2)%hora(2)%minuto(2)%segundo(2)
  // Exemplo: sendo hoje 23/10/1989 e agora 10:35:56
  // 23101989103556
  strftime(cd, DATE_SIZE, "%Y%m%d%H%M%S", timeInfo);

  // retornamos nossa string, para que seja usada no restante do programa
  sCd = cd;
  return sCd;
}

// Validação de entrada de dados no formulário
string Form::validateInput(string inputData, int optCheckIn) {
  int escape = 0;

  // Aqui, primeiramente verifica qual campo está entrando e depois, valida o mesmo
  while (!auxValidateInput(inputData, optCheckIn)) { 
    cout << endl<< endl << "\tEntre com dados válidos! Digite novamente: ";
    getline(cin, inputData);

    // Váriavel de Controle de exibições do Loop 
    escape++;

    // Controle do Loop
    if (escape == NUMBER_OF_ATTMPTS) {
      escape = 0;
      inputStandardMessage();
    }

  }

  return inputData;
}

// Auxiliar para validação da entrada dos dados
bool Form::auxValidateInput(string inputData, int optCheckIn) {
  if (inputData.empty())
    return false;
  
  if ((isdigit(inputData[0])) || (isdigit(inputData[1])) || (isdigit(inputData[2])) || (isdigit(inputData[3])) || (isdigit(inputData[4])))
    return false;

  if (((optCheckIn == SENDER_RECIPIENT_SUBJECT_SIZE) && (inputData.size() > SENDER_RECIPIENT_SUBJECT_SIZE)) || ((optCheckIn == MENSSAGE_SIZE) && (inputData.length() > MENSSAGE_SIZE)))
    return false;

  return true;
}

// Mensagem padrão para procedimento realizados com sucesso
void Form::successfulMessage() {
  cout << endl << endl << "OK! pressione ENTER para continuar." << endl << endl;
}

// Mensagem padrão, de orientações para o cadastro
void Form::inputStandardMessage() {
  cout << endl << endl << "ATENÇÃO: Cadastro não pode estar vazio, iniciar com números ou ultrapassar quantidade de caracteres!!!";
}