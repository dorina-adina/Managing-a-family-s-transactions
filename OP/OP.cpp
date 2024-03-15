
#include "OP.h"

OP::OP()
{
//    cout << "Default constructor" << endl;
    this->namee = nullptr;
    this->OP_type = nullptr;
    this->ziuaa = 0;
    this->suma_de_banii = 0;
    this->tipp = nullptr;
    this->descrieree = nullptr;
}

OP::OP(char* OP_type, char* namee, int ziuaa, int suma_de_banii, char* tipp, char*descrieree)
{
//    cout << "Constructor with param" << endl;
    this->OP_type = new char[strlen(OP_type)+1];
    strncpy(this->OP_type, OP_type, strlen(OP_type));

    this->namee = new char[strlen(namee) + 1];
    strncpy(this->namee, namee, strlen(namee));

    this->ziuaa = ziuaa;

    this->suma_de_banii = suma_de_banii;

    this->tipp = new char[strlen(tipp) + 1];
    strncpy(this->tipp, tipp, strlen(tipp));

    this->descrieree = new char[strlen(descrieree) + 1];
    strncpy(this->descrieree, descrieree, strlen(descrieree));

}

OP::OP(OP& other)
{
//    cout << "Copy constructor" << endl;
    this->OP_type = new char[strlen(other.OP_type)+1];
    strcpy_s(this->OP_type, strlen(other.OP_type)+1, other.OP_type);

    this->namee = new char[strlen(other.namee) + 1];
    strcpy_s(this->namee, strlen(other.namee) + 1, other.namee);

    this->ziuaa= other.ziuaa;

    this->suma_de_banii = other.suma_de_banii;

    this->tipp = new char[strlen(other.tipp)+1];
    strcpy_s(this->tipp, strlen(other.tipp)+1, other.tipp);

    this->descrieree = new char[strlen(other.descrieree) + 1];
    strcpy_s(this->descrieree, strlen(other.descrieree) + 1, other.descrieree);
}


OP::~OP()
{
//        cout << "Destructor of cerc " << centru << ' ' << raza << endl;
    delete[] this->OP_type;
}


char *OP::getOP_type()
{
    return this->OP_type;
}


void OP::setOP_type(char* newOP)
{
//    if (this->name){
//        delete[] this->name;
//    }
    this->OP_type = new char[strlen(newOP)];
    strncpy(this->OP_type, newOP, strlen(newOP));
}


char *OP::getNamee()
{
    return this->namee;
}


void OP::setNamee(char* newNamee)
{
//    if (this->descriere){
//        delete[] this->descriere;
//    }
    this->namee = new char[strlen(newNamee) + 1];
    strcpy_s(this->namee, strlen(newNamee) + 1, newNamee);
}

int OP::getZiuaa()
{
    return this->ziuaa;
}

int OP::getSumaDeBanii()
{
    return this->suma_de_banii;
}

char *OP::getTipp()
{
    return this->tipp;
}

char *OP::getDescrieree()
{
    return this->descrieree;
}



void OP::add(char* OP_type, char* namee, int ziuaa, int suma_de_banii, char* tipp, char* descriere)
{
    OP *entitate = new OP(OP_type, namee, ziuaa, suma_de_banii, tipp, descriere);
    this->operatii.push_back(entitate);
}

vector <OP*> OP::getAllOP()
{
    return this->operatii; 
}

void OP::removeLastOP() {
    if (!this->operatii.empty()) {
        delete this->operatii.back(); // Elimina memoria alocata pentru ultima operatie
        this->operatii.pop_back(); // Elimina ultima operatie din vectorul de operatii
    }
}
