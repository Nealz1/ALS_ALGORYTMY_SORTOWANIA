//============================================================================
//                  Algorytmy i Struktury Danych
// Zadanie 11.1
// Merge sort
//
//============================================================================

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//FUNKCJA WYKONUJACA SCALANIE
void merge(int tablica[], int lewo, int srodek, int prawo)
{
    int i, j, k;
    int n1 = srodek - lewo + 1;
    int n2 = prawo - srodek;

    int tabL[n1], tabP[n2];

    for (i = 0; i < n1; i++)
    {
    	tabL[i] = tablica[lewo + i];
	}
    for (j = 0; j < n2; j++)
    {
    	tabP[j] = tablica[srodek + 1 + j];
	}
    i = 0;
    j = 0;
    k = lewo;
    while (i < n1 && j < n2)
    {
        if (tabL[i] <= tabP[j])
        {
            tablica[k] = tabL[i];
            i++;
        }
        else
        {
            tablica[k] = tabP[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        tablica[k] = tabL[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        tablica[k] = tabP[j];
        j++;
        k++;
    }
}

//FUNKCJA NA MERGE SORT
void mergeSort(int tablica[], int lewo, int prawo)
{
    if (lewo < prawo)
    {
        int srodek = lewo + (prawo - lewo) / 2;
        mergeSort(tablica, lewo, srodek);
        mergeSort(tablica, srodek + 1, prawo);
        merge(tablica, lewo, srodek, prawo);
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
    mergeSort(tablica, 0, n-1);
    
    cout << endl << "Wygenerowane posortowane liczby:" << endl;
    Wypisz(n, tablica);
	
	//ZAPIS DANYCH DO PLIKU
	ofstream plik;
	plik.open("wynik1.txt");
	for(int i = 0; i<n; i++)
	{
		plik << tablica[i] << " ";
		if ((i + 1) % 10 == 0)
        {
        	plik << endl;
		}
	}
	plik.close();
	cout << endl << "Plik zostal zapisany o nazwie 'wynik1.txt'" << endl;
	
    return 0;
}
