
#ifndef LAB8_ENTITATE_H
#define LAB8_ENTITATE_H


class Entitate {
private:
    char* name;
    int ziua;
    int suma_de_bani;
    char* tip;
    char* descriere;

public:
    Entitate();
    Entitate(char* name, int ziua, int suma_de_bani, char* tip, char* descriere);
    Entitate(Entitate &other);

    ~Entitate();

    Entitate &operator=(const Entitate &other);
    bool operator==(const Entitate &e);

    char *getName();

    int getZiua();

    int getSumaDeBani();

    char *getTip();

    char *getDescriere();


    void setName(char *newname);

    void setSumaDeBani(int newSumaDeBani);

    void setZiua(int newZiua);

    void setTip(char *newTip);

    void setDescriere(char *newDescriere);


//    friend ostream& operator << (ostream& os, Entitate &enti);
};


#endif //LAB8_ENTITATE_H
