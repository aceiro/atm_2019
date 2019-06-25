#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

class Formulario
{
private:
    int id;
    string Remetente;
    string Destinatario;
    string Mensagem;
    time_t Data;

public:
    void setRemetente(string);
    void setDestinatario(string);
    void setMensagem(string);  

    string getRemetente();
    string getDestinatario();
    string getMensagem();
    string getData();
};

void Formulario::setRemetente(string rem)
{
    Remetente = rem;
}

void Formulario::setDestinatario(string des)
{
    Destinatario = des;
}

void Formulario::setMensagem(string msg)
{
    Mensagem = msg;
}

string Formulario::getRemetente()
{
    return Remetente;
}

string Formulario::getDestinatario()
{
    return Destinatario;
}

string Formulario::getMensagem()
{
    return Mensagem;
}

string Formulario::getData()
{
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    printf ("Data da mensagem: %s", asctime(timeinfo));
}