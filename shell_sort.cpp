//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 9.1
//  Shell sort
//
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//FUNKCJA NA SHELL SORT
void SortowanieShell(int tablica[], int n)
{
	int odstep;
    for (odstep = n / 2; odstep > 0; odstep = odstep / 2)
    {
        for (int i = odstep; i < n; i = i + 1)
        {
            int temp = tablica[i];
            int j;
            for (j = i; j >= odstep && tablica[j - odstep] > temp; j -= odstep)
            {
            	tablica[j] = tablica[j - odstep];
			}
            tablica[j] = temp;
        }
    }
}

//FUNKCJA NA GENEROWANIE LICZB
void GenerujLosowe(int n, int tab[], int a, int b)
{
    srand(time(0));
    
    if(a<b) //SPRAWDZANIE ABY A BYLO MNIEJSZE OD B, ZEBY POPRAWNIE WYKONAC ZAKRES <a;b>
	{
    	for (int i = 0; i < n; i++)
    	{
    		tab[i] = (rand() % (b - a + 1)) + a;
		}
	}
	else if(a>b) //IF DLA PRZYPADKU A>B, WTEDY ZOSTAJE ZAMIENIANA WARTOSC PRZEDZIALU tzn. TRAKTUJEMY PRZEDZIAL <b;a>
	{
    	for (int i = 0; i < n; i++)
    	{
    		tab[i] = (rand() % (a - b + 1)) + b;
		}
	}
}

//FUNKCJA NA WYPISANIE LICZB DO KONSOLI
void Wypisz(int n, int tab[])
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
        if ((i + 1) % 10 == 0)
        {
        	cout << endl;
		}
    }
}

//MAIN
int main()
{
    int n;
    cout << "Podaj ilosc elementow do losowego wygenerowania:" << endl;
    cin >> n;
    int tablica[n];
    
    int a,b;
    cout << "Podaj przedzial liczbowy z ktorego chcesz losowac liczby <a;b>:" << endl;
    cin >> a >> b;
    GenerujLosowe(n, tablica, a, b); 

    cout << "Wygenerowane liczby:" << endl;
    Wypisz(n, tablica);

    cout << endl << "Wygenerowane posortowane liczby:" << endl;
    SortowanieShell(tablica, n);
    Wypisz(n, tablica);

	//ZAPIS DANYCH DO PLIKU
	ofstream plik;
	plik.open("wynik1.txt");
	for(int i = 0; i<n; i++)
	{
		plik << tablica[i] << endl;
	}
	plik.close();
	cout << endl << "Plik zostal zapisany o nazwie 'wynik1.txt'" << endl;
	
    return 0;
}
