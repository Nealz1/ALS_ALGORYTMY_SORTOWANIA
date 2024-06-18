//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 10.3
// Comb sort
//
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//FUNKCJA NA COMB SORT
void combSort(int tablica[], int n) 
{
    double wspolczynnik = 1.3;
    int przerwa = n;
    int zamiana = 1;

    while (przerwa > 1 || zamiana == 1) 
	{
        if (przerwa > 1) 
		{
            przerwa = przerwa / wspolczynnik;
        }

        zamiana = 0;
        int i = 0;
        
        while (i + przerwa < n) 
		{
            if (tablica[i] > tablica[i + przerwa]) 
			{
                int temp = tablica[i];
                tablica[i] = tablica[i + przerwa];
                tablica[i + przerwa] = temp;
                zamiana = 1;
            }
            i++;
        }
    }
}

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

int main()
{
    srand(time(0));
    int n;
    cout << "Podaj ilosc elementow do losowego wygenerowania:" << endl;
    cin >> n;
    int tablica[n];
    
    int a,b;
    cout << "Podaj przedzial liczbowy z ktorego chcesz losowac liczby <a;b>:" << endl;
    cin >> a >> b;
    
    for(int i=0; i<n; i++)
    {
        tablica[i] = LosowanieLiczb(a,b);
    }
    
    cout << endl << "Wygenerowane liczby:" << endl;
    Wypisz(n, tablica);
    combSort(tablica, n);
    
    cout << endl << "Wygenerowane posortowane liczby:" << endl;
    Wypisz(n, tablica);
	
	//ZAPIS DANYCH DO PLIKU
	ofstream plik;
	plik.open("wynik3.txt");
	for(int i = 0; i<n; i++)
	{
		plik << tablica[i] << " ";
		if ((i + 1) % 10 == 0)
        {
        	plik << endl;
		}
	}
	plik.close();
	cout << endl << "Plik zostal zapisany o nazwie 'wynik3.txt'" << endl;
	
    return 0;
}
