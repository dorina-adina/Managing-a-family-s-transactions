#include "EntitateService.h"
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

EntitateService::EntitateService(EntitateRepository &repo, OP &undoRepo) {
    this->repo = &repo;
    this->undoRepo = &undoRepo;
}


vector<Entitate *> EntitateService::getAll() {
    vector<Entitate *> entitati = this->repo->getAllEntitati();

    vector<Entitate *> results;

    for (int i = 0; i < entitati.size(); i++) {
        Entitate *entitate = entitati.at(i);
        results.push_back(entitate);
    }

    return results;
}


void EntitateService::addEntitate(char* name, int ziua, int suma_de_bani, char* tip, char* descriere) {

    this->repo->addEntitate(name, ziua, suma_de_bani, tip, descriere);
    this->undoRepo->add("DEL", name, ziua, suma_de_bani, tip, descriere);

}

void EntitateService::modifyEntitate(char* name, int NewZiua, int NewSuma_de_bani, char* NewTip, char* NewDescriere)
{
    vector <Entitate*> entitati = this->repo->getAllEntitati();
    for(int i = 0; i < entitati.size(); i++)
        if(strcmp(entitati[i]->getName(), name) == 0)
        {
            this->undoRepo->add("MOD", name, entitati[i]->getZiua(), entitati[i]->getSumaDeBani(), entitati[i]->getTip(), entitati[i]->getDescriere());
            break;
        }
    this->repo->modifyEntitate(name, NewZiua, NewSuma_de_bani, NewTip, NewDescriere);
}
//void EntitateService::deleteEntitate(int ziua_de_sters)
//{
//    this->repo->deleteEntitate(ziua_de_sters);
//}

void EntitateService::deleteEntitate(char* name)
{
    vector <Entitate*> entitati = this->repo->getAllEntitati();
    for(int i = 0; i < entitati.size(); i++)
        if(strcmp(entitati[i]->getName(), name) == 0)
        {
            this->undoRepo->add("ADD", name, entitati[i]->getZiua(), entitati[i]->getSumaDeBani(), entitati[i]->getTip(), entitati[i]->getDescriere());
            break;
        }
    this->repo->deleteEntitate(name);
}

void EntitateService::UNDO()
{
    vector <OP*> operatii = this->undoRepo->getAllOP();

    if (!operatii.empty()) {
        OP *last_op = operatii.back();

        if (strcmp(last_op->getOP_type(), "DEL") == 0) {
            this->repo->addEntitate(last_op->getNamee(), last_op->getZiuaa(), last_op->getSumaDeBanii(), last_op->getTipp(), last_op->getDescrieree());
        } else if (strcmp(last_op->getOP_type(), "MOD") == 0) {
            this->repo->modifyEntitate(last_op->getNamee(), last_op->getZiuaa(), last_op->getSumaDeBanii(), last_op->getTipp(), last_op->getDescrieree());
        } else if (strcmp(last_op->getOP_type(), "ADD") == 0) {
            this->repo->deleteEntitate(last_op->getNamee());
        }

        this->undoRepo->removeLastOP();
    }
}



vector<Entitate*> EntitateService::afisareAnumiteCheltuieli(char* proprietate, int suma) {

    vector<Entitate *> entitati = this->repo->getAllEntitati();

    vector<Entitate *> listaCeruta;

    for (int i = 0; i < entitati.size(); i++) {
        if (strcmp(entitati[i]->getDescriere(), proprietate) == 0 && entitati[i]->getSumaDeBani() >= suma) {
            listaCeruta.push_back(entitati[i]);
        }
    }
    return listaCeruta;
}


bool copmare(Entitate *a, Entitate *b) {
    return a->getSumaDeBani() > b->getSumaDeBani();
}

vector<Entitate*> EntitateService::afisareSumeCheltuiteZilnicOrdonateDescrescator() {

    vector<Entitate *> entitati = this->repo->getAllEntitati();

    vector<Entitate *> listaCeruta;

    for (int i = 0; i < entitati.size(); i++) {
        if(strcmp(entitati[i]->getTip(), "tip_out") == 0)
            listaCeruta.push_back(entitati[i]);
    }

    std::sort(listaCeruta.begin(), listaCeruta.end(), copmare);

    return listaCeruta;
}

vector<Entitate*> EntitateService::filtrareCheltuieli(char *prop) {
    vector<Entitate *> entitati = this->repo->getAllEntitati();
    vector<Entitate *> listaCeruta;
    for (int i = 0; i < entitati.size(); i++) {
        if (strcmp(entitati[i]->getTip(),prop)==0) {
            listaCeruta.push_back(entitati[i]);
        }
    }
    return listaCeruta;
}




