#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Formulario.cpp"
#include <time.h>

using namespace std;

int main(){
    
    Formulario f;
    string rmtt, dstn, msg;

    cout << "Preencha o formulário" << endl;
    cout << "Primeiro, identifique-se, informe seu nome" << endl;
    getline(cin, rmtt);
    f.setRemetente(rmtt);

    cout << "Entre agora com o nome do destinatário" << endl;
    getline(cin, dstn);
    f.setDestinatario(dstn);

    cout << "Digite sua mensagem" << endl;
    getline(cin, msg); 
    f.setMensagem(msg);

    system("pause");
    system("clear||cls");

    cout << "----------FORMULÁRIO----------" << endl << endl;
    cout << "Remetente: " << f.getRemetente() << endl;
    cout << "Destinatário: " << f.getDestinatario() << endl;
    cout << "Mensagem" << endl << f.getMensagem() << endl;
    f.getData();

    return 0;
}
