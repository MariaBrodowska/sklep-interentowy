#ifndef PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_PRODUKTY_H
#define PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_PRODUKTY_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Produkt{
public:
    string nazwa;
    float cena, cenaVAT;
    int ilePozostalo, ileZamowiono;
    void aktualizujZapis(vector <Produkt> w);
};

#endif //PROJEKT_ZALICZENOWY__LAB_MARIA_BRODOWSKA_PRODUKTY_H
