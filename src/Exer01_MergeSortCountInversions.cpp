#include<bits/stdc++.h>
using namespace std;

int cont = 0;


void merge(vector<int>& arr, int inicio, int meio, int fim) {

    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    vector<int> esquerda(n1);
    vector<int> direita(n2);

    for (i = 0; i < n1; i++) {
        esquerda[i] = arr[inicio + i];
    }

    for (j = 0; j < n2; j++) {
        direita[j] = arr[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {

        if (esquerda[i] <= direita[j]) {
            arr[k++] = esquerda[i++];

        } else {
            arr[k++] = direita[j++];
            cont += n1-i;
        }


    }

    while (i < n1) {
        arr[k++] = esquerda[i++];
    }

    while (j < n2) {
        arr[k++] = direita[j++];
    }
}

void mergeSort(vector<int>& arr, int inicio, int fim) {

    if (inicio < fim) {

        int meio = inicio + (fim - inicio) / 2;

        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        merge(arr, inicio, meio, fim);
    }
}

int main() {

    vector<int> arr = {2, 3, 8, 6, 1};

    mergeSort(arr, 0, 4);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << endl;
    }
    cout << "Quantidade De Trocas " << cont<<endl;

    return 0;
}