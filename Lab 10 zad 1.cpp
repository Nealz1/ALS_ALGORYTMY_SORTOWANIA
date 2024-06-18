//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 10.1
// Heap sort
//
//  WCY21IX4S0  Miksiewicz Pawel
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//PODSTAWAWOWA STRUKTURA DO SORTOWANIA PRZEZ KOPCOWANIE
struct Drzewo 
{
    int klucz;
    int index;
    struct Drzewo* lewo;
    struct Drzewo* prawo;
};

//FUNKCJA NA LOSOWANIE LICZBY Z PRZEDZIALU <a;b>
int LosowanieLiczb(int a, int b)
{
    int losowa;
	if(a<b) //SPRAWDZANIE ABY A BYLO MNIEJSZE OD B, ZEBY POPRAWNIE WYKONAC ZAKRES <a;b>
	{
    	losowa = (rand() % (b - a + 1)) + a;
	}
	else if(a>b) //IF DLA PRZYPADKU A>B, WTEDY ZOSTAJE ZAMIENIANA WARTOSC PRZEDZIALU tzn. TRAKTUJEMY PRZEDZIAL <b;a>
	{
    	losowa = (rand() % (a - b + 1)) + b;
	}	
	return losowa;
}

//UTWORZENIE WEZLA
struct Drzewo* Wezel(int klucz, int index) 
{
    struct Drzewo* temp = (struct Drzewo*)malloc(sizeof(struct Drzewo));
    temp->klucz = klucz;
    temp->index = index;
    temp->lewo = NULL;
	temp->prawo = NULL;
    return temp;
}

//SORTOWANIE PRZEZ KOPCOWANIE
void heapify(struct Drzewo* korzen, int n, int i) 
{
    int najwiekszy = i;
    int lewo = 2*i + 1;
    int prawo = 2*i + 2;

    struct Drzewo* NajwiekszaWartosc = korzen;
    struct Drzewo* lewoDrzewo = korzen;
    struct Drzewo* prawoDrzewo = korzen;

    for (int j = 0; j < lewo; j++) 
	{
        if (lewoDrzewo)
        {
        	lewoDrzewo = lewoDrzewo->lewo;
		}
    }
    for (int j = 0; j < prawo; j++) 
	{
        if (prawoDrzewo)
        {
        	prawoDrzewo = prawoDrzewo->lewo;
		}
    }

    if (lewoDrzewo && lewoDrzewo->klucz > NajwiekszaWartosc->klucz) 
	{
        najwiekszy = lewo;
        NajwiekszaWartosc = lewoDrzewo;
    }

    if (prawoDrzewo && prawoDrzewo->klucz > NajwiekszaWartosc->klucz) 
	{
        najwiekszy = prawo;
        NajwiekszaWartosc = prawoDrzewo;
    }

    if (najwiekszy != i) 
	{
        int temp = korzen->klucz;
        korzen->klucz = NajwiekszaWartosc->klucz;
        NajwiekszaWartosc->klucz = temp;
        heapify(korzen, n, najwiekszy);
    }
}

//FUNKCJA NA DODANIE WARTOSCI DO DRZEWA
struct Drzewo* WstawDoDrzewa(struct Drzewo* korzen, int klucz, int index) 
{
    if (!korzen)
    {
    	return Wezel(klucz, index);
	}
    korzen->lewo = WstawDoDrzewa(korzen->lewo, klucz, index);
    heapify(korzen, 0, 0);
    return korzen;
}

//WYPISANIE LVR
void inorder(struct Drzewo* korzen) 
{
    if (!korzen)
    {
    	return;
	}
    inorder(korzen->lewo);
    cout << korzen->klucz << " ";
    inorder(korzen->prawo);
}

//MAIN
int main()
{
    struct Drzewo* korzen = NULL;
    srand(time(NULL));
    int n;
    cout << "Podaj ilosc elementow do losowego wygenerowania:" << endl;
    cin >> n;
    
    int a,b;
    cout << "Podaj przedzial liczbowy z ktorego chcesz losowac liczby <a;b>:" << endl;
    cin >> a >> b;
    
    int liczba;
    cout << endl << "Wygenerowane liczby" << endl;
    for(int i=0; i<n; i++)
    {
        liczba = LosowanieLiczb(a,b);
        cout << liczba << " ";
        if ((i + 1) % 10 == 0)
        {
        	cout << endl;
		}
        korzen = WstawDoDrzewa(korzen, liczba, i);
    }

    cout << endl << "Wygenerowane posortowane liczby:" << endl;
    inorder(korzen);
    cout << endl;

    return 0;
}
