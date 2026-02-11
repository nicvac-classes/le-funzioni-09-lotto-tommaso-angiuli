#include <iostream>
#include <vector>
using namespace std;

bool cercaNumero(vector<int> estratti, int m, int numero) {
    bool trovato;
    int j;

    j = 0;
    trovato = false;
    while (j <= m - 1) {
        if (estratti[j] == numero) {
            trovato = true;
        }
        j = j + 1;
    }
    
    return trovato;
}

int controllaVincita(vector<int> estratti, vector<int> giocati, int n, int m) {
    int vincita, i, j;

    i = 0;
    vincita = 0;
    while (i <= n - 1) {
        if (cercaNumero(estratti, m, giocati[i])) {
            vincita = vincita + 1;
        }
        i = i + 1;
    }
    
    return vincita;
}

void estrazioneNumeri(vector<int> & v, int n) {
    int i;

    i = 0;
    while (i <= n - 1) {
        v[i] = rand() % 90 + 1;
        cout << v[i] << endl;
        i = i + 1;
    }
}

void gioca(vector<int> & giocata, int n) {
    int i, x;

    i = 0;
    while (i <= n - 1) {
        cout << "inserisci il " << i + 1 << " numero da giocare" << endl;
        cin >> x;
        giocata[i] = x;
        i = i + 1;
    }
}

void visualizzaMenu() {
    cout << "scegli un opzione tra: 1 (gioca al lotto), 2 (estrazione del lotto), 3 (controlla vincita), 0 (esci)" << endl;
}

int main() {
    int scelta, n, indovinati;

    visualizzaMenu();
    cin >> scelta;
    indovinati = 0;
    n = 5;
    vector<int> estrazione(n);
    vector<int> giocata(5);
    while (scelta > 0) {
        if (scelta == 1) {
            do {
                cout << "quanti numeri vuoi giocare? (da 1 a 5)" << endl;
                cin >> n;
            } while (n < 1 || n > 5);
            gioca(giocata, n);
        } else {
            if (scelta == 2) {
                estrazioneNumeri(estrazione, n);
            } else {
                if (scelta == 3) {
                    indovinati = controllaVincita(estrazione, giocata, n, 5);
                    cout << "hai indovinato " << indovinati << " numeri" << endl;
                }
            }
        }
        visualizzaMenu();
        cin >> scelta;
    }
    return 0;
}
