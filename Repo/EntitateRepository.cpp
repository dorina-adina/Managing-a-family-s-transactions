#include "EntitateRepository.h"
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

EntitateRepository::EntitateRepository()
{
//    this->entitati = new Entitate[this->maxCapacity]; // Our list allocated dinamically

}
EntitateRepository::~EntitateRepository()
{
//    delete[] this->entitati;
}

void EntitateRepository::addEntitate(char* name, int ziua, int suma_de_bani, char* tip, char* descriere)
{
    Entitate *entitate = new Entitate(name, ziua, suma_de_bani, tip, descriere);
    this->entitati.push_back(entitate);
}

vector <Entitate*> EntitateRepository::getAllEntitati()
{
    return this->entitati; 
}

int EntitateRepository::getSizeAllEntitati() {
    return this->entitati.size(); 
}

void EntitateRepository::modifyEntitate(char* name, int NewZiua, int NewSuma_de_bani, char* NewTip, char* NewDescriere)
{
    vector<Entitate *> entitati = this->getAllEntitati();
    for(int i = 0; i < this->getSizeAllEntitati(); i++)
        if(strcmp(name, entitati[i]->getName()) == 0)
        {
            entitati[i]->setZiua(NewZiua);
            entitati[i]->setSumaDeBani(NewSuma_de_bani);
            entitati[i]->setTip(NewTip);
            entitati[i]->setDescriere(NewDescriere);
        }

}

//void EntitateRepository::deleteEntitate(int ziua_de_sters)
//{
//    if(!entitati.empty())
//    {
//
//        int dimensiune = this->getSizeAllEntitati();
//        for(int i = 0; i < dimensiune; i++)
//            if(!entitati.empty())
//            {
//                if(entitati[i]->getZiua() == ziua_de_sters) {
//                delete entitati[i];
//                entitati.erase(entitati.begin() + i);
//                i = i - 1;
//                dimensiune = dimensiune - 1;
//                continue;
//                }
//
//            }
//            else break;
//
//
//        }
//}


void EntitateRepository::deleteEntitate(char *name)
{
    if(!entitati.empty())
    {

        int dimensiune = this->getSizeAllEntitati();
        for(int i = 0; i < dimensiune; i++)
            if(!entitati.empty())
            {
                if(strcmp(entitati[i]->getName(), name) == 0) {
                delete entitati[i];
                entitati.erase(entitati.begin() + i);
                i = i - 1;
                dimensiune = dimensiune - 1;
                continue;
                }

            }
            else break;
        }
}
