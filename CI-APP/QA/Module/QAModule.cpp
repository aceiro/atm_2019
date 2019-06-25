// Declaração das Bibliotecas internas do C++ 
#include <iostream> 
#include <string>
#include <assert.h>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Module/QAModule.hpp"
#include "../../Include/Form.hpp"

using std::cout;
using std::endl;
using std::string;

Form testForm;

QAModule::QAModule() {
  cout << endl << "Aqui sera o Modulo de testes (Qualidade), ainda esta em construcao..." << endl;
}

QAModule::~QAModule() {
  
}

// Testar a Entrada de Dados
void QAModule::createTest(string testIdCI, string testSenderCI, string testRecipientCI, string testSubjectCI, string testDateCI, string testMessageCI) {
  // Teste para verificar se o "input de dados" está dentro das especificações - não testa Data e ID
  assert((testForm.auxValidateInput(testSenderCI, SENDER_RECIPIENT_SUBJECT_SIZE)) == true);
  assert((testForm.auxValidateInput(testRecipientCI, SENDER_RECIPIENT_SUBJECT_SIZE)) == true);
  assert((testForm.auxValidateInput(testSubjectCI, SENDER_RECIPIENT_SUBJECT_SIZE)) == true);
  assert((testForm.auxValidateInput(testMessageCI, MENSSAGE_SIZE)) == true);

  // Rotina de atribuição de dados (para receber dados, teste 2 vezes -- Verificar a necessidade)
  testSenderCI = testForm.auxValidateInput(testSenderCI, SENDER_RECIPIENT_SUBJECT_SIZE);
  testRecipientCI = testForm.auxValidateInput(testRecipientCI, SENDER_RECIPIENT_SUBJECT_SIZE);
  testSubjectCI = testForm.auxValidateInput(testSubjectCI, SENDER_RECIPIENT_SUBJECT_SIZE);
  testMessageCI = testForm.auxValidateInput(testMessageCI, MENSSAGE_SIZE);
  
  // Submissão do dados para o formulário. 
  testForm.formCreate(testIdCI, testSenderCI, testRecipientCI, testSubjectCI, testDateCI, testMessageCI);
}

// Testar a Consulta de Dados
void QAModule::selectTest(string testIdCI) {
  // testForm.

}

// Testar a Atualização de Dados
void QAModule::updateTest(string test) {

}

// Testar a Exclusão de Dados
void QAModule::deleteTest(string testIdCI) {

}

// Testar a Impressão de Dados
void QAModule::printTest(string testIdCI) {

}

// Testar a Capacidade de Armazenamento de Dados
// Neste ponto a Métrica: 20 entradas, baseado em que o programa é armazenado em memória
int QAModule::capacityTest(string testIdCI, string testDateCI, string testSenderCI, string testRecipient, string testSubject, string testMessage) {

}
