#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
struct email
{
    char Identificador[12];
    char Fecha[15];
    char Hora[10];
    char From[30];
    char To[30];
    char CC[50];
    char BCC[50];
    char subject[35];
    char Content[200];
};
using namespace std;

class Email
{
private:
    string Identificador;
    string Fecha;
    string Hora;
    string From;
    string To;
    string CC;
    string BCC;
    string subject;
    string Content;
public:
    Email();
    string getIdentificador() const;
    void setIdentificador(const string &value);
    string getFecha() const;
    void setFecha(const string &value);
    string getHora() const;
    void setHora(const string &value);
    string getFrom() const;
    void setFrom(const string &value);
    string getTo() const;
    void setTo(const string &value);
    string getCC() const;
    void setCC(const string &value);
    string getBCC() const;
    void setBCC(const string &value);
    string getSubject() const;
    void setSubject(const string &value);
    string getContent() const;
    void setContent(const string &value);
    friend ostream &operator <<(ostream &os,Email &a);
};

#endif // EMAIL_H
