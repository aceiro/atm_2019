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

// Conversão de tipo data para string
const char *Form::getSystemDate() {
  // "t_Date" será nossa váriavel para passagem de referênica dos valores de data
  time_t t_Date;

  // "tm" é um estrutura interna do C++ que indica atributos do tipo TIME
  struct tm *timeInfo;

  // "buffer" será nosso retorno com data formatada
  char buffer[DATE_SIZE];

  // Usando a função "time" (Interna do C++) passando como referência "t_Date"
  time(&t_Date);

  // Usando a função "localtime", e passando nossa "t_Date", para "timeInfo",
  // que é onde temos a entrada da data sem formatação 
  timeInfo = localtime(&t_Date);

  // "strftime", converte nosso tipo de data para uma string, que nosso caso é o "buffer"
  strftime(buffer, DATE_SIZE, "%d/%m%/Y", timeInfo);

  // retornamos nossa string, para que seja usada no restante do programa
  return buffer;
}

// Validação de entrada de dados no formulário
string Form::validateInput(string inputData) {
  
  // Condicional recursiva que força usuário a entrar com um valor válido (que seja um nome ou algo parecido)
  if ((inputData.empty()) || (isdigit(inputData[0])) || (isdigit(inputData[1])) || (isdigit(inputData[2])) || (isdigit(inputData[3]))) {
    cout << endl << inputData << " não é um remetente válido (nome)! " << "Digite novamente: ";
    getline(cin, inputData);
    cin.ignore();
    validateInput(inputData);
  }
  
  else
      return inputData;
}

void Form::formCreate() {
  // Váriaveis para inserção no Formulário
  int idCI;
  string senderCI;
  string recipientCI;
  string subjectCI;
  string dateCI;
  string messageCI;

  // Entrada de dados
  cout << endl << "\tMódulo de Cadastro - Inserir uma CI" << endl;
  cout << endl << "\t\tObs.: Nenhum dado pode ser omitido!" << endl;
  cout << endl << "De (nome do remetente): ";
  getline(cin, senderCI);
  
  // Verificar se os dados de não estão vazios
  senderCI = validateInput(senderCI);

  // Inicialização das Váriaveis dataCI
  dateCI = getSystemDate();

  // cin.ignore();
  // if 

  // Verificação da Posição a ser inserido, e inserção
  if (Data.empty())
    Data.insert(Data.begin(), FormData(idCI, senderCI, recipientCI, subjectCI, dateCI, messageCI));

  else
    Data.push_back(FormData(idCI, senderCI, recipientCI, subjectCI, dateCI, messageCI));
  

}
