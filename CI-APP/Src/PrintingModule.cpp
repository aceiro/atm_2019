// Declaração das Bibliotecas internas do C++ 
#include <iostream>
#include <fstream> 
#include <string>
#include <iomanip>

// Declaração das Bibliotecas internas do Projeto (declação das Classes)
#include "../Include/PrintingModule.hpp"

// Uso refinado do Escopo STD
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream; // "ofstream" é escopo para criar/escrever um arquivo
using std::setw;
using std::left;

PrintingModule::PrintingModule() {
  
}

PrintingModule::~PrintingModule() {

}

// Realizar a impressão de acordo com a formatação abaixo, da CI escolhida
void PrintingModule::printFileCI(string fileName, string printIdCI, string printSenderCI, string printRecipientCI, string printSubjectCI, string printDateCI, string printMessageCI) {
  // Rotina de abertura para gravação do arquivo
  formFile.open (fileName);

  formFile << endl;
  formFile << "  ____ ___        _                  _   ___  " << endl;
  formFile << " / ___|_ _|      / \\   _ __  _ __   / | / _ \\ " << endl;
  formFile << "| |    | |_____ / _ \\ | '_ \\| '_ \\  | || | | |" << endl;
  formFile << "| |___ | |_____/ ___ \\| |_) | |_) | | || |_| |" << endl;
  formFile << " \\____|___|   /_/   \\_\\ .__/| .__/  |_(_)___/ " << endl;
  formFile << "                      |_|   |_|   " << endl;

  formFile << endl << endl << "\t\t" << PRINT_TITLE << endl << endl;
  formFile << "Nome do Arquivo: " << fileName << endl << endl;
  
  formFile << "ID.: "; 
  formFile << setw(49) << left << printIdCI;
  formFile << endl << endl;
  formFile << "DATA: ";
  formFile << setw(15) << left << printDateCI;
  formFile << endl << endl;
  formFile << "DE: ";
  formFile << setw(50) << left << printSenderCI;
  formFile << endl << endl;
  formFile << "PARA: ";
  formFile << setw(50) << left << printRecipientCI;
  formFile << endl << endl;
  formFile << "ASSUNTO: ";
  formFile << setw(100) << left << printSubjectCI;
  formFile << endl << endl;
  formFile << "MENSAGEM: ";
  formFile << setw(500) << left << printMessageCI;
  formFile << endl << endl;

  // Rotina de fechamento do arquivo.
  formFile.close(); 
}