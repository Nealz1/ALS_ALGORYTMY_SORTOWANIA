//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 9.3
//  Quick Sort
//
//  WCY21IX4S0  Miksiewicz Pawel
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//FUNCKJA NA QUICK SORT
void SzybkiSort(int tablica[], int lewo, int prawo)
{
    int i = lewo;
    int j = prawo;
    int srodek = tablica[(lewo + prawo) / 2];

    while (i <= j)
    {
        while (tablica[i] < srodek)
        {
        	i++;
		}
        while (tablica[j] > srodek)
        {
        	j--;
		}
        if (i <= j)
        {
            int temp = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = temp;
            i++;
            j--;
        }
    }
    if (lewo < j)
    {
    	SzybkiSort(tablica, lewo, j);
	}
    if (i < prawo)
    {
    	SzybkiSort(tablica, i, prawo);
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
    SzybkiSort(tablica, 0, n - 1);
    Wypisz(n, tablica);

	//ZAPIS DANYCH DO PLIKU
    ofstream plik;
	plik.open("wynik3.txt");
	for(int i = 0; i<n; i++)
	{
		plik << tablica[i] << endl;
	}
	plik.close();
	cout << endl << "Plik zostal zapisany o nazwie 'wynik3.txt'" << endl;
	
    return 0;
}
