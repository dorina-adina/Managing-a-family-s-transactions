#ifndef LAB8_UI_H
#define LAB8_UI_H

#include "../Service/EntitateService.h"

class UI {
private:
    EntitateService *service;

    void printMenu();
    void printAllEntitati();
    void addEntitateToService(char* name, int ziua, int suma_de_bani, char* tip, char* descriere);
    void modifyEntitateToService(char* name, int NewZiua, int NewSuma_de_bani, char* NewTip, char* NewDescriere);
//    void deleteEntitateToService(int ziua_de_sters);
    void deleteEntitateToService(char* name);
    void anumiteCheltuieli(char* proprietate, int sumaData);
    void cheltuieliOrdonateDescDupaCheltuieli();
    void filtrareCheltuieli(char * prop);


public:
    UI(EntitateService &service);

    void start();

};


#endif //LAB8_UI_H
