/*Marcin Hanas
 *Plik zawiera implementacje metod skladajacych sie na klase kolejki
 */

#include <iostream>
#include "kolejka.h"

int kolejka::id_za_ostatnim (void)
{
    return (id_pierwszy+l_el)%max_l_el;
}
int kolejka::id_i (int i)
{
    return (id_pierwszy+i)%max_l_el;
}

void kolejka::dodaj_nadpisz (float nowy_el)
{
    element[id_za_ostatnim()]=nowy_el; //wstawianie elementu do tablicy danych
    if(!czy_pelna()) l_el++;
    else id_pierwszy=id_i(1); //jezeli kolejka jest pelna, to nowy el zostal zapisany w miejscu dotychczasowego pierwszego,
                              //wiec nastepuje przesuniecie wskazania id_pierwszy na kolejny element
}

void kolejka::dodaj_bez_nadpisu (float nowy_el)
{
    if(!czy_pelna()) //jezeli kolejka nie jest pelna
    {
        element[id_za_ostatnim()]=nowy_el; //wstawianie elementu do tablicy danych
        l_el++;
    }
    else cout << "Brak mozliwosci dodania kolejnego elementu"<<endl;
}

float kolejka::pobierz (void)
{
    float pobrany_element;
    pobrany_element=element[id_pierwszy];
    id_pierwszy=id_i(1); //zmiana wskazania na 1. element
    l_el--; //zmniejszenie liczby elementow
    return pobrany_element; //zwrocenie wartosci pobranego elementu
}

int kolejka::podaj_rozmiar (void)
{
    return l_el;
}

int kolejka::czy_pusta (void)
{
    return l_el==0;
}

int kolejka::czy_pelna (void)
{
    return l_el==max_l_el;
}

kolejka kolejka::operator+(kolejka &kol2)
{
    class kolejka nowa_kolejka(max_l_el+kol2.max_l_el); //tworzenie nowej kolejki o rozmiarze sumy maksymalnych rozmiarow obu kolejek
    for(int i=0; i<l_el; i++) nowa_kolejka.dodaj_nadpisz(element[id_i(i)]); //dodawanie do kolejki elementow z pierwszej kolejki
    for(int i=0; i<kol2.l_el; i++) nowa_kolejka.dodaj_nadpisz(kol2.element[(kol2.id_i(i)]); //dodawanie do kolejki elementow z drugiej kolejki
    return nowa_kolejka;
}


void kolejka::operator+=(kolejka &kol2)
{
    int tmp_l_el=l_el;
    float tmp[l_el];
    for(int i=0; i<l_el; i++) tmp[i]=element[id_i(i)]; //zapisywanie aktualny danych z kolejki x do tablicy tymczasowej

    element= new float[max_l_el+kol2.max_l_el]; //tworzenie nowej tablicy dynamicznej o rozmiarze wiekszym o maksymalna wielkosc dodawanej kolejki
    max_l_el+=kol2.max_l_el;
    l_el=0; //zerowanie liczby elementow, utworzona tablica jest obecnie pusta

    for(int i=0; i<tmp_l_el; i++) dodaj_bez_nadpisu(tmp[i]); //dodawanie do kolejki elementow z tablicy tymczasowej (tych ktore wczesniej byly w tej kolejce)
    for(int i=0; i<kol2.l_el; i++) dodaj_bez_nadpisu(kol2.element[(kol2.id_i(i)]); //dodawanie nowych elementow z kolejki dodawanej
}

bool kolejka::operator==(kolejka &kol2)
{
    if(l_el!=kol2.l_el) return false; //jezeli kolejki maja rozna liczbe elementow, to nie sa takie same
    for (int i=0; i<l_el; i++)
    {
        if(element[i]!=kol2.element[i]) return false; //jezeli kolejki maja rozne elementy, to nie sa takie same
    }
    return true;
}


bool kolejka::operator!=(kolejka& kol2)
{
    return !(operator==(kol2)); //jezeli kolejki nie sa takie same, to sa rozne
}


ostream& operator<< (ostream &wyjscie, kolejka &x)
{
    for (int i=0; i<x.l_el; i++)
    {
        wyjscie << x.element[(x.id_i(i)] << " "; //ladowanie do wyjscia elementow kolejki x
    }
    wyjscie << endl;
    return wyjscie; //zwracanie wyjscia
}
