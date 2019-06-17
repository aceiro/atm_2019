// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Form.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::endl;
using std::string;

Form::Form() {

}

Form::~Form() {

}

// Inicialização do Construtor, repassando a herança para os atributos que estarão encapsulados
Form::FormData::FormData(string idCI, string senderCI, string recipientCI, string subjectCI, string dateCI, string messageCI) : idCI(idCI), senderCI(senderCI), recipientCI(recipientCI), subjectCI(subjectCI), dateCI(dateCI), messageCI(messageCI) {

}

Form::FormData::FormData(string senderCI) : senderCI(senderCI) {

}
  
Form::FormData::~FormData(){

}

void Form::FormData::setIdCI() {
  this->idCI = idCI;
}

void Form::FormData::setSenderCI(string senderCI) {
  this->senderCI = senderCI;
}

void Form::FormData::setRecipientCI(string recipientCI) {
  this->recipientCI = recipientCI;
}
  
void Form::FormData::setSubjectCI(string subjectCI) {
  this->subjectCI = subjectCI;
}

void Form::FormData::setDateCI() {
  this->dateCI = dateCI;
}
  
void Form::FormData::setMessageCI(string menssageCI) {
  this->messageCI = messageCI;
}
  
string Form::FormData::getIdCI() {
  return idCI;
}
  
string Form::FormData::getSenderCI() {
  return senderCI;
}
  
string Form::FormData::getRecipientCI() {
  return recipientCI;
}
  
string Form::FormData::getSubjectCI() {
  return subjectCI;
}
  
string Form::FormData::getDateCI() {
  return dateCI;
}
  
string Form::FormData::getMessageCI() {
  return messageCI;
}