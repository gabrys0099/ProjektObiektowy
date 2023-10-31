#include <iostream>
#include <cmath>
using namespace std;
//klasa generyczna pierwiastka
template<typename pierwiastek>
class Pierwiastek
{
    public:
    pierwiastek wynikPierwiastka;
    pierwiastek pierwiastkuj(pierwiastek x)
    {
        wynikPierwiastka= sqrt(x);
        return wynikPierwiastka;
    }
};
//klasa generyczna logarytmu naturalnego
template<typename LogNatural>
class LogarytmNaturalny
{
    public:
    LogNatural wynikLogarytmu;
    LogNatural LogNatur(LogNatural x)
    {
        wynikLogarytmu= log(x);
        return wynikLogarytmu;
    }
};
//klasa generyczna dodawania
template<typename dodawanie>
class Dodawanie
{
    public:
    dodawanie x;
    dodawanie wynik;
    dodawanie dodaj(dodawanie x, dodawanie y)
    {
        wynik=x+y;
        return wynik;
    }
};

//klasa generyczna dla kwadratu liczb
template<typename kwadrat>
class Kwadrat
{
    public:
    kwadrat WynikPotegi;
    kwadrat PotegaKwadrat(kwadrat x)
    {
        WynikPotegi=x*x;
        return WynikPotegi;
    }
};
//klasa generyczna dzielenia
template<typename dzielenie>
class Dzielenie
{
    public:
    dzielenie WynikDzi;
    dzielenie Dziel(dzielenie el1, dzielenie el2)
    {
        WynikDzi=el1/el2;
        return WynikDzi;
    }
};
int main()
{
    Pierwiastek<int> *sqrtInt = new Pierwiastek<int>;
    cout<<sqrtInt->pierwiastkuj(100)<<endl;
    LogarytmNaturalny<double> *logDbl = new LogarytmNaturalny<double>;
    cout<<logDbl->LogNatur(7)<<endl;
    Dodawanie<int> *intDod = new Dodawanie<int>;
    cout<<intDod->dodaj(7, 14)<<endl;
    Kwadrat<float> *potegaKwadrat = new Kwadrat<float>;
    cout<<potegaKwadrat->PotegaKwadrat(5)<<endl;
    Dzielenie<double> *dblDzi = new Dzielenie<double>;
    cout<<dblDzi->Dziel(111.2121,2.21431)<<endl;
}

