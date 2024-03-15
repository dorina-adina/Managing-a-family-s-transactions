
#include "Tests.h"
#include "../Modules/Entitate.h"
#include "../Repo/EntitateRepository.h"
#include "../Service/EntitateService.h"
#include "../OP/OP.h"
#include <cassert>
#include <cstring>
#include <vector>
#include <iostream>

void testEntitate()
{
   Entitate entitate1;

   entitate1.setName("tranz1");
   entitate1.setZiua(11);
   entitate1.setSumaDeBani(70);
   entitate1.setTip("tip_out");
   entitate1.setDescriere("haine");
   assert(strcmp(entitate1.getName(), "tranz1") == 0);
   assert(entitate1.getZiua() == 11);
   assert(entitate1.getSumaDeBani() == 70);
   assert(strcmp(entitate1.getTip(), "tip_out") == 0);
   assert(strcmp(entitate1.getDescriere(), "haine") == 0);


   Entitate entitate2("tranz2", 12, 100, "tip_in", "salariu");
   assert(strcmp(entitate2.getName(), "tranz2") == 0);
   assert(entitate2.getZiua() == 12);
   assert(strcmp(entitate2.getTip(), "tip_in") == 0);
   assert(entitate2.getSumaDeBani() == 100);
   assert(strcmp(entitate2.getDescriere(), "salariu") == 0);


   Entitate entitate3 = Entitate(entitate2);
   assert(strcmp(entitate3.getName(), "tranz2") == 0);
   assert(entitate3.getZiua() == 12);
   assert(strcmp(entitate3.getTip(), "tip_in") == 0);
   assert(strcmp(entitate3.getDescriere(), "salariu") == 0);
   assert(entitate3.getSumaDeBani() == 100);


   Entitate* entitate4 = new Entitate("tranz3", 12, 100, "tip_in", "salariu");
   assert(strcmp(entitate4->getName(), "tranz3") == 0);
   assert(strcmp(entitate4->getTip(), "tip_in") == 0);
   assert(entitate4->getZiua() == 12);
   assert(entitate4->getSumaDeBani() == 100);
   assert(strcmp(entitate4->getDescriere(), "salariu") == 0);



   EntitateRepository r;

   r.addEntitate("tranz1", 11, 70, "tip_out", "teatru");
   r.addEntitate("tranz2", 12, 100, "tip_in", "salariu");
   r.addEntitate("tranz3", 12, 100, "tip_in", "salariu");

   assert(r.getSizeAllEntitati() == 3);

   vector<Entitate*> entitati = r.getAllEntitati();

   assert(strcmp(entitati[0]->getName(), "tranz1") == 0);
   assert(strcmp(entitati[0]->getDescriere(), "teatru") == 0);
   assert(strcmp(entitati[0]->getTip(), "tip_out") == 0);
   assert(entitati[1]->getSumaDeBani() == 100);
   assert(entitati[2]->getZiua() == 12);

   r.modifyEntitate("tranz1", 10, 234, "tip_in", "burse");
   assert(strcmp(entitati[0]->getName(), "tranz1") == 0);
   assert(strcmp(entitati[0]->getDescriere(), "burse") == 0);
   assert(strcmp(entitati[0]->getTip(), "tip_in") == 0);
   assert(entitati[0]->getSumaDeBani() == 234);
   assert(entitati[0]->getZiua() == 10);

   r.deleteEntitate("tranz1");
   assert(strcmp(entitati[0]->getName(), "tranz2") != 0);
   assert(strcmp(entitati[0]->getDescriere(), "salariu") != 0);
   assert(strcmp(entitati[0]->getTip(), "tip_in") == 0);
   assert(entitati[0]->getSumaDeBani() != 100);

   OP undoRepo;

   EntitateService service(r, undoRepo);

   service.addEntitate("tranz1", 11, 70, "tip_out", "teatru");
   service.addEntitate("tranz2", 12, 100, "tip_in", "salariu");
   service.addEntitate("tranz3", 12, 101, "tip_in", "salariu");
   service.addEntitate("tranz4", 13, 234, "tip_out", "teatru");


   vector<Entitate*> entitati1 = service.getAll();

   assert(strcmp(entitati1[0]->getDescriere(), "teatru") != 0);
   assert(strcmp(entitati1[0]->getTip(), "tip_out") != 0);
   assert(entitati1[1]->getSumaDeBani() == 100);
   assert(entitati1[2]->getZiua() != 12);

   service.modifyEntitate("tranz1", 10, 234, "tip_in", "burse");
   assert(strcmp(entitati1[0]->getName(), "tranz1") != 0);
   assert(strcmp(entitati1[0]->getDescriere(), "burse") != 0);
   assert(strcmp(entitati1[0]->getTip(), "tip_in") == 0);
   assert(entitati1[0]->getSumaDeBani() != 234);
   assert(entitati1[0]->getZiua() != 10);

   service.deleteEntitate("tranz1");
   assert(strcmp(entitati1[0]->getName(), "tranz2") == 0);
   assert(strcmp(entitati1[0]->getDescriere(), "salariu") == 0);
   assert(strcmp(entitati1[0]->getTip(), "tip_in") == 0);
   assert(entitati1[0]->getSumaDeBani() == 100);


   vector<Entitate*> entitati2;
   entitati2 = service.afisareAnumiteCheltuieli("teatru", 100);

   assert(strcmp(entitati2[0]->getName(), "tranz4") == 0);
   assert(strcmp(entitati2[0]->getTip(), "tip_out") == 0);
   assert(entitati2[0]->getZiua() == 13);
   assert(entitati2[0]->getSumaDeBani() == 234);


   vector<Entitate*> entitati3;
   entitati3 = service.afisareSumeCheltuiteZilnicOrdonateDescrescator();

   assert(strcmp(entitati3[0]->getName(), "tranz4") == 0);
   assert(strcmp(entitati3[0]->getTip(), "tip_out") == 0);
   assert(entitati3[0]->getZiua() == 13);
   assert(entitati3[0]->getSumaDeBani() == 234);
   assert(strcmp(entitati3[0]->getDescriere(), "teatru") == 0);


   vector<Entitate*> entitati4;
   entitati4 = service.filtrareCheltuieli("tip_in");

   assert(strcmp(entitati4[0]->getName(), "tranz3") != 0);
   assert(entitati4[0]->getZiua() != 15);
   assert(entitati4[0]->getSumaDeBani() != 101);
   assert(strcmp(entitati4[0]->getDescriere(), "teatru")!= 0);



   std::cout << "Tests passed successfully" << "\n";
}
