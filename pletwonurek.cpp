#include <iostream>

using namespace std;

int main() {

    short potrzebny_tlen, potrzebny_azot, liczba_butli;

    cin >> potrzebny_tlen >> potrzebny_azot >> liczba_butli; // 5 tlenu 60 azotu 5 butli

    short* tlen_w_itej_butli = new short[liczba_butli]; // dlugosc 5
    short* azot_w_itej_butli = new short[liczba_butli];
    short* waga_itej_butli = new short[liczba_butli];
    short** wynik = new short* [potrzebny_tlen];

    for (int i = 0; i < potrzebny_tlen; i++)
		wynik[i] = new short[potrzebny_azot];

    for (int i = 0; i < liczba_butli; i++) 
        cin >> tlen_w_itej_butli[i] >> azot_w_itej_butli[i] >> waga_itej_butli[i];

    for (int i = 0; i < liczba_butli; i++) {
        if (tlen_w_itej_butli[i] > potrzebny_tlen)
            tlen_w_itej_butli[i] = potrzebny_tlen;
        if (azot_w_itej_butli[i] > potrzebny_azot)
            azot_w_itej_butli[i] = potrzebny_azot;

        for (int k = 0; k < tlen_w_itej_butli[i]; k++)
            for (int l = 0; l < azot_w_itej_butli[i]; l++) {
                if (waga_itej_butli[i] < wynik[k][l] || wynik[k][l] == 0) 
                    wynik[k][l] = waga_itej_butli[i];
                // if (wynik[tlen_w_itej_butli[i] + 1 + k][azot_w_itej_butli[i] + 1 + l] > waga_itej_butli[i] || wynik[k][l] == 0)
                //     wynik[k][l] = waga_itej_butli[i];
            }
    }

    for (int i = 0; i < potrzebny_tlen; i++) {
        for (int j = 0; j < potrzebny_azot; j++) {
            cout << wynik[i][j] << " ";
        }
        cout << endl;
    }

    delete [] wynik;
    delete [] tlen_w_itej_butli;
    delete [] azot_w_itej_butli;
    delete [] waga_itej_butli;
    return 0;
}