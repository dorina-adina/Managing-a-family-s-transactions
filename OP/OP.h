
#ifndef LAB8_OP_H
#define LAB8_OP_H
#include <cstring>
#include <vector>

using namespace std;

class OP {
private:
    char* OP_type;
    char* namee;
    int ziuaa;
    int suma_de_banii;
    char* tipp;
    char* descrieree;
    vector<OP*> operatii;
public:
    OP();
    OP(char* OP_type, char* namee, int ziuaa, int suma_de_banii, char *tipp, char *descrieree);
    OP(OP &other);

    ~OP();

//    Entitate &operator=(const Entitate &other);
//    bool operator==(const Entitate &e);

    char *getOP_type();

    char *getNamee();


    void setOP_type(char *newOP);

    void setNamee(char *newNamee);


    int getZiuaa();

    int getSumaDeBanii();

    char *getTipp();

    char *getDescrieree();

    void add(char* OP_type, char* namee, int ziuaa, int suma_de_banii, char *tipp, char *descrieree);
    vector <OP*> getAllOP();

    void removeLastOP();

};


#endif //LAB8_OP_H
