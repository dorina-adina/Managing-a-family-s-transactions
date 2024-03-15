#ifndef LAB8_ENTITATEREPOSITORY_H
#define LAB8_ENTITATEREPOSITORY_H
#include "../Modules/Entitate.h"
#include <vector>

using namespace std;

class EntitateRepository {
private:
    vector <Entitate*> entitati;

public:
    EntitateRepository();
    ~EntitateRepository();

    void addEntitate(char* name, int ziua, int suma_de_bani, char* tip, char* descriere);
    int getSizeAllEntitati();
    vector <Entitate*> getAllEntitati();
    void modifyEntitate(char* name, int NewZiua, int NewSuma_de_bani, char* NewTip, char* NewDescriere);
//    void deleteEntitate(int ziua_de_sters);
    void deleteEntitate(char*name);

};
#endif //LAB8_ENTITATEREPOSITORY_H





















////
//// Created by User on 22.04.2023.
////
//
//#ifndef LAB8_ENTITATEREPOSITORY_H
//#define LAB8_ENTITATEREPOSITORY_H
//#include "Entitate.h"
//
//class EntitateRepository {
//private:
//    Entitate *entitati;
//    int maxCapacity = 10;
//    int size = 0;
//public:
//    EntitateRepository();
//
//    ~EntitateRepository();
//
//    void addEntitate(Entitate entitate);
//    int getSizeAllEntitati();
//    Entitate *getAllEntitati();
//
//
//};
//
//
//#endif //LAB8_ENTITATEREPOSITORY_H
