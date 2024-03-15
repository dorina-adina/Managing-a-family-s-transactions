#ifndef LAB8_ENTITATESERVICE_H
#define LAB8_ENTITATESERVICE_H

#include "../Repo/EntitateRepository.h"
#include "../OP/OP.h"
#include <vector>

using namespace std;

class EntitateService {
private:
    EntitateRepository *repo;
    OP *undoRepo;

public:
    EntitateService(EntitateRepository &repo, OP &undoRepo);

    vector<Entitate *> getAll();

    void addEntitate(char* name, int ziua, int suma_de_bani, char* tip, char* descriere);

    void modifyEntitate(char* name, int NewZiua, int NewSuma_de_bani, char* NewTip, char* NewDescriere);

//    void deleteEntitate(int ziua_de_sters);

    void deleteEntitate(char* name);

    void UNDO();
    vector<Entitate *> afisareAnumiteCheltuieli(char* proprietate, int suma);

    vector<Entitate *> afisareSumeCheltuiteZilnicOrdonateDescrescator();

    vector<Entitate *> filtrareCheltuieli(char *prop);

};


#endif //LAB8_ENTITATESERVICE_H
