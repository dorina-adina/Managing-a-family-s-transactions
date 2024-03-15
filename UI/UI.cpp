#include <iostream>
#include "UI.h"
#include <vector>
using namespace std;

UI::UI(EntitateService &service) {
    this->service = &service;
}

void UI::printAllEntitati() {
    for (const auto entitati: this->service->getAll()) {
        cout << "Entitate: " << endl << "Nume: " << entitati->getName() << endl << "Ziua: " << entitati->getZiua()
             << endl << "Suma de bani: " << entitati->getSumaDeBani() << endl << "Tip: " << entitati->getTip() << endl
             << "Descriere: " << entitati->getDescriere() << endl << endl << endl;
    }
}

void UI::printMenu(){
        cout << "Alege una din optiunile:" << endl;
        cout << " 1. Adauga o entitate." << endl;
        cout << " 2. Afiseaza toate entitatile." << endl;
        cout << " 3. Modifica entitate dupa nume." << endl;
        cout << " 4. Sterge entitate dupa nume." << endl;
        cout << " 5. Lista entitatilor cu o anumita descriere si cu o suma mai mare decat o suma data." << endl;
        cout << " 6. Lista entitatilor ordonate descrescator dupa suma cheltuita." << endl;
        cout << " 7. Filtrare cheltuieli." << endl;
        cout << " 8. UNDO " << endl;
        cout << " 9. Exit" << endl;
    }


void UI::addEntitateToService(char* name, int ziua, int suma_de_bani, char* tip, char* descriere){
        this->service->addEntitate(name, ziua, suma_de_bani, tip, descriere);
    }

void UI::modifyEntitateToService(char* name, int NewZiua, int NewSuma_de_bani, char* NewTip, char* NewDescriere){
    this->service->modifyEntitate(name, NewZiua, NewSuma_de_bani, NewTip, NewDescriere);
}

//void UI::deleteEntitateToService(int ziua_de_sters){
//    this->service->deleteEntitate(ziua_de_sters);
//}

void UI::deleteEntitateToService(char* name){
    this->service->deleteEntitate(name);
}

void UI::anumiteCheltuieli(char*proprietate, int sumaData) {
    for (const auto entitati: this->service->afisareAnumiteCheltuieli(proprietate, sumaData)) {
        cout << "Entitate: " << endl << "Nume: " << entitati->getName() << endl << "Ziua: " << entitati->getZiua()
             << endl << "Suma de bani: " << entitati->getSumaDeBani() << endl << "Tip: " << entitati->getTip() << endl
             << "Descriere: " << entitati->getDescriere() << endl << endl << endl;    }
}

void UI::cheltuieliOrdonateDescDupaCheltuieli()
{
    for (const auto entitati: this->service->afisareSumeCheltuiteZilnicOrdonateDescrescator()) {
        cout << "Entitate: " << endl << "Nume: " << entitati->getName() << endl << "Ziua: " << entitati->getZiua()
             << endl << "Suma de bani: " << entitati->getSumaDeBani() << endl << endl << endl;    }
}

void UI::filtrareCheltuieli(char *prop)
{
    for (const auto entitati: this->service->filtrareCheltuieli(prop)) {
        cout << "Entitate: " << endl << "Nume: " << entitati->getName() << endl << "Ziua: " << entitati->getZiua()
             << endl << "Suma de bani: " << entitati->getSumaDeBani() << endl << "Tip: " << entitati->getTip() << endl
             << "Descriere: " << entitati->getDescriere() << endl << endl << endl;    }
}


void UI::start() {

        int ziua;
        int suma_de_bani;
        char *name;
        char *tip;
        char *descriere;
        int NewZiua;
        int NewSuma_de_bani;
        char *NewTip;
        char *NewDescriere;
        while (true) {
            this->printMenu();
            int option;
            cin >> option;

            switch (option) {
                case 1:
                    name = new char[10];
                    tip = new char[5];
                    descriere = new char[10];
                    cout << "Please input: \n";
                    cout << "Name: "; cin >> name;
                    cout << "Ziua: "; cin >> ziua;
                    cout << "Suma de bani: "; cin >> suma_de_bani;
                    cout << "Tip: "; cin >> tip;
                    cout << "Descriere: "; cin >> descriere;
                    cout << endl;
                    this->addEntitateToService(name, ziua, suma_de_bani, tip, descriere);
                    break;
                case 2:
                    this->printAllEntitati();
                    break;
                case 3:
                    name = new char[10];
                    NewTip = new char[5];
                    NewDescriere = new char[10];
                    cout << "Please input: \n";
                    cout << "Name: "; cin >> name;
                    cout << "Ziua noua: "; cin >> NewZiua;
                    cout << "Suma de bani noua: "; cin >> NewSuma_de_bani;
                    cout << "Tip nou: "; cin >> NewTip;
                    cout << "Descriere noua: "; cin >> NewDescriere;
                    cout << endl;
                    this->modifyEntitateToService(name, NewZiua, NewSuma_de_bani, NewTip, NewDescriere);
                    break;
                case 4:
//                    int ziua_de_sters;
                    name = new char [10];
                    cout << "Dati numele entitatii de sters: \n";
//                    cin >> ziua_de_sters;
                    cin >> name;
                    this->deleteEntitateToService(name);
//                    this->deleteEntitateToService(ziua_de_sters);
                    break;
                case 5:
                    char* proprietate;
                    proprietate = new char[10];
                    int sumaData;
                    cout << "Dati descrierea: ";
                    cin >> proprietate;
                    cout << endl << "Dati suma: ";
                    cin >> sumaData;
                    cout << endl;
                    this->anumiteCheltuieli(proprietate, sumaData);
                    break;
                case 6:
                    this->cheltuieliOrdonateDescDupaCheltuieli();
                    break;
                case 7:
                    proprietate = new char[10];
                    cout << "Dati tipul dupa care sa fie filtrate cheltuielile:";
                    cin >> proprietate;
                    cout << endl;
                    this->filtrareCheltuieli(proprietate);
                    break;
                case 8:
                    this->service->UNDO();
                    break;
                case 9:
                    return;
            }
        }

    }
