// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <string>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/Form.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::endl;
using std::string;


Form::FormData::FormData(int idCI, string senderCI, string recipientCI, string subjectCI, char dateCI[], string messageCI) : idCI(idCI), senderCI(senderCI), recipientCI(recipientCI), subjectCI(subjectCI), dateCI(dateCI[DATE_SIZE]), messageCI(messageCI) {

}
  
Form::FormData::~FormData(){


}

void Form::FormData::setIdCI() {

}

void Form::FormData::setSenderCI(string senderCI) {

}

void Form::FormData::setRecipientCI(string recipientCI) {

}
  
void Form::FormData::setSubjectCI(string subjectCI) {

}

void Form::FormData::setDateCI() {

}
  
void Form::FormData::setMessageCI(string menssageCI) {

}
  
int Form::FormData::getIdCI() {

}
  
string Form::FormData::getSenderCI() {

}
  
string Form::FormData::getRecipientCI() {

}
  
string Form::FormData::getSubjectCI() {

}
  
char Form::FormData::getDateCI() {

}
  
string Form::FormData::getMessageCI() {

}