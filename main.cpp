#include <iostream>
#include "Modules/Entitate.h"
#include "Repo/EntitateRepository.h"
#include "Service/EntitateService.h"
#include "UI/UI.h"
#include "Tests/Tests.h"
#include "OP/OP.h"
using namespace std;

int main() {
    testEntitate();
    EntitateRepository r;

    r.addEntitate("tranz1", 11, 70, "tip_out", "teatru");
    r.addEntitate("tranz2", 12, 100, "tip_out", "cadouri");
    r.addEntitate("tranz3", 4, 50, "tip_in", "salariu");
    r.addEntitate("tranz4", 6, 30, "tip_out", "cinema");
    r.addEntitate("tranz5", 14, 120, "tip_out", "teatru");

    OP undoRepo;

    EntitateService service(r,undoRepo);

    UI ui(service);

    ui.start();

    return 0;
}
