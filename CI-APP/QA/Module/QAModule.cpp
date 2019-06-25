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

}

QAModule::~QAModule() {
  
}

// Testar a Entrada de Dados
void QAModule::createTest(string testIdCI, string testSenderCI, string testRecipientCI, string testSubjectCI, string testDateCI, string testMessageCI) {
  // Teste para verificar se a Entrada de Dados está dentro das especificações - não testa Data e ID
  assert((testForm.auxValidateInput(testSenderCI, SENDER_RECIPIENT_SUBJECT_SIZE)) == true);
  assert((testForm.auxValidateInput(testRecipientCI, SENDER_RECIPIENT_SUBJECT_SIZE)) == true);
  assert((testForm.auxValidateInput(testSubjectCI, SENDER_RECIPIENT_SUBJECT_SIZE)) == true);
  assert((testForm.auxValidateInput(testMessageCI, MENSSAGE_SIZE)) == true);
  
  // Submissão do dados para o formulário. 
  testForm.formCreate(testIdCI, testSenderCI, testRecipientCI, testSubjectCI, testDateCI, testMessageCI);
}

// Testar a Consulta de Dados
void QAModule::selectTest(string testIdCI) {
  // Teste para verificar se os dados podem ser recuperados
  assert((testForm.formSelect(testIdCI)) == true);
}

// Testar a Atualização de Dados
void QAModule::updateTest(string testIdCI, string testSenderCI, string testRecipientCI, string testSubjectCI, string testDateCI, string testMessageCI, char optA, char optB, char optC, char optD) {
  // Teste para verificar se os dados podem ser recuperados
  assert((testForm.formSelect(testIdCI)) == true);
  
  // Teste para validar se as opções foram inseridas corretamente 
  assert((testForm.validateInputToUpdate(optA)) == true);
  assert((testForm.validateInputToUpdate(optB)) == true);
  assert((testForm.validateInputToUpdate(optC)) == true);
  assert((testForm.validateInputToUpdate(optD)) == true);

  // Teste para comparar se a opção de entrar é retornada de forma correta
  assert((testForm.returnInputToUpdate(optA)) == 1);
  assert((testForm.returnInputToUpdate(optB)) == 2);
  assert((testForm.returnInputToUpdate(optC)) == 3);
  assert((testForm.returnInputToUpdate(optD)) == 4);

  // Teste para verificar se a Entrada de Dados está dentro das especificações - não testa Data e ID
  assert((testForm.auxValidateInput(testSenderCI, SENDER_RECIPIENT_SUBJECT_SIZE)) == true);
  assert((testForm.auxValidateInput(testRecipientCI, SENDER_RECIPIENT_SUBJECT_SIZE)) == true);
  assert((testForm.auxValidateInput(testSubjectCI, SENDER_RECIPIENT_SUBJECT_SIZE)) == true);
  assert((testForm.auxValidateInput(testMessageCI, MENSSAGE_SIZE)) == true);

  // Inserção de dados
  testForm.formUpdate(testIdCI, testSenderCI, 1);
  testForm.formUpdate(testIdCI, testRecipientCI, 2);
  testForm.formUpdate(testIdCI, testSubjectCI, 3);
  testForm.formUpdate(testIdCI, testMessageCI, 4);
}

// Testar a Exclusão de Dados
void QAModule::deleteTest(string testIdCI) {
  // Teste para verificar se os dados podem ser recuperados
  assert((testForm.formSelect(testIdCI)) == true);

  // Realizando a exclusão do dado solicitado
  testForm.formDelete(testIdCI);

  // Teste para verificar se os dados não podem ser recuperados ("false" é nossa intenção agora)
  assert((testForm.formSelect(testIdCI)) == false);
}

// Testar a Impressão de Dados
void QAModule::printTest(string testIdCI) {
  // Teste para verificar se os dados podem ser recuperados
  assert((testForm.formSelect(testIdCI)) == true);

  // Submissão dos dados para impressão 
  testForm.formToPrint(testPrintCI, testIdCI, testSenderCI, testRecipientCI, testSubjectCI, testDateCI, testMessageCI);
}