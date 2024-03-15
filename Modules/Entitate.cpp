#include <iostream>
#include <cstring>
#include "Entitate.h"
using namespace std;

Entitate::Entitate()
{
//    cout << "Default constructor" << endl;
    this->name = nullptr;
    this->ziua = 0;
    this->suma_de_bani = 0;
    this->tip = nullptr;
    this->descriere = nullptr;
}

Entitate::Entitate(char* name, int ziua, int suma_de_bani, char* tip, char * descriere)
{
//    cout << "Constructor with param" << endl;
    this->name = new char[strlen(name)+1];
    strncpy(this->name, name, strlen(name));

    this->ziua = ziua;

    this->suma_de_bani = suma_de_bani;

    this->tip = new char[strlen(tip) + 1];
    strncpy(this->tip, tip, strlen(tip));

    this->descriere = new char[strlen(descriere) + 1];
    strncpy(this->descriere, descriere, strlen(descriere));

}

Entitate::Entitate(Entitate& other)
{
//    cout << "Copy constructor" << endl;
    this->name = new char[strlen(other.name)+1];
    strcpy_s(this->name, strlen(other.name)+1, other.name);

    this->ziua = other.ziua;

    this->suma_de_bani = other.suma_de_bani;

    this->tip = new char[strlen(other.tip)+1];
    strcpy_s(this->tip, strlen(other.tip)+1, other.tip);

    this->descriere = new char[strlen(other.descriere) + 1];
    strcpy_s(this->descriere, strlen(other.descriere) + 1, other.descriere);

}


Entitate::~Entitate()
{
//        cout << "Destructor of cerc " << centru << ' ' << raza << endl;
    delete[] this->name;
}


char *Entitate::getName()
{
    return this->name;
}


void Entitate::setName(char* newName)
{
    if (this->name){
        delete[] this->name;
    }
    this->name = new char[strlen(newName)];
    strncpy(this->name, newName, strlen(newName));
}

int Entitate::getZiua()
{
    return this->ziua;
}

int Entitate::getSumaDeBani()
{
    return this->suma_de_bani;
}

char *Entitate::getTip()
{
    return this->tip;
}

char *Entitate::getDescriere()
{
    return this->descriere;
}

void Entitate::setZiua(int newZiua)
{
    this->ziua = newZiua;
}

void Entitate::setSumaDeBani(int newSumaDeBani)
{
    this->suma_de_bani = newSumaDeBani;
}

void Entitate::setTip(char* newTip)
{
    if (this->tip){
        delete[] this->tip;
    }
    this->tip = new char[strlen(newTip) + 1];
    strcpy_s(this->tip, strlen(newTip) + 1, newTip);
}

void Entitate::setDescriere(char* newDescriere)
{
    if (this->descriere){
        delete[] this->descriere;
    }
    this->descriere = new char[strlen(newDescriere) + 1];
    strcpy_s(this->descriere, strlen(newDescriere) + 1, newDescriere);
}


ostream& operator << (ostream& os, Entitate &enti) {
    os << "Entitate: " << endl << "Nume: " << enti.getName() << endl << "Ziua: " << enti.getZiua() << endl << "Suma de bani: " << enti.getSumaDeBani() << endl << "Tip: " << enti.getTip() << endl << "Descriere: " << enti.getDescriere() << endl << endl;
    return os;
}

Entitate &Entitate::operator=(const Entitate &other) {
//    cout << "Using = operator" << endl;
    if (this == &other) {
        return *this;
    }

    this->name = new char[strlen(other.name) + 1];
    strncpy(this->name, other.name, strlen(other.name));

    this->ziua = other.ziua;
    this->suma_de_bani = other.suma_de_bani;

    this->tip = new char[strlen(other.tip) + 1];
    strncpy(this->tip, other.tip, strlen(other.tip));

    this->descriere = new char[strlen(other.descriere) + 1];
    strncpy(this->descriere, other.descriere, strlen(other.descriere));


    return *this;
}

bool Entitate::operator==(const Entitate &e){
    return ((strcmp(this->name, e.name) == 0) && (this->ziua == e.ziua) && (this->suma_de_bani == e.suma_de_bani) && (strcmp(this->tip, e.tip) == 0) && (strcmp(this->descriere, e.descriere) == 0));
}

