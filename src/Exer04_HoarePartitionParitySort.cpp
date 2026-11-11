#include<bits/stdc++.h>

using namespace std;
int particao(vector<int>& arr, int inicio, int fim) {

    int i = inicio;
    int j = fim;

    while (i <= j) {

        while (i <= j && arr[i] % 2 == 0) {   // MUDOU: i <= j
            i++;
        }

        while (i <= j && arr[j] % 2 != 0) {   // MUDOU: i <= j
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return i;
}

int particaoCrescente(vector<int>& arr, int inicio, int fim) {

    swap(arr[(inicio + fim) / 2], arr[fim]);   // MUDOU: pivô do meio

    int pivo = arr[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {

        if (arr[j] <= pivo) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[fim]);

    return i + 1;
}


int particaoDecrescente(vector<int>& arr, int inicio, int fim) {

    swap(arr[(inicio + fim) / 2], arr[fim]);   // MUDOU: pivô do meio

    int pivo = arr[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {

        if (arr[j] >= pivo) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[fim]);

    return i + 1;
}


void quickSortCrescente(vector<int>& arr, int inicio, int fim) {   // MUDOU
    if (inicio < fim) {
        int p = particaoCrescente(arr, inicio, fim);
        quickSortCrescente(arr, inicio, p - 1);
        quickSortCrescente(arr, p + 1, fim);
    }
}

void quickSortDecrescente(vector<int>& arr, int inicio, int fim) {  // NOVA
    if (inicio < fim) {
        int p = particaoDecrescente(arr, inicio, fim);
        quickSortDecrescente(arr, inicio, p - 1);
        quickSortDecrescente(arr, p + 1, fim);
    }
}

int main() {

    int n;

    cout << "Informe a quantidade de numeros: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Informe os " << n << " numeros:" << endl;

    for (int i = 0; i < n ; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> arr[i];
    }

    int meio = particao(arr, 0, n - 1);

    quickSortCrescente(arr, 0, meio - 1);
    quickSortDecrescente(arr, meio, n - 1);

    cout << "\nVetor ordenado:" << endl;

    for (int i = 0; i < n; i++) {
        cout << arr[i];

        if (i < n - 1) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}