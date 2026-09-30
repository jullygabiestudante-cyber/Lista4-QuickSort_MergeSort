#include <bits/stdc++.h>

using namespace std;

struct Palavra {
    string texto;
    int tamanho;
};

void merge(vector<Palavra> &palavras, int inicio, int meio, int fim) {

    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    vector<Palavra> esquerda(n1);
    vector<Palavra> direita(n2);

    for (i = 0; i < n1; i++) {
        esquerda[i] = palavras[inicio + i];
    }

    for (j = 0; j < n2; j++) {
        direita[j] = palavras[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while (i < n1 && j < n2) {

        if (esquerda[i].tamanho >= direita[j].tamanho) {
            palavras[k++] = esquerda[i++];
        } else {
            palavras[k++] = direita[j++];
        }
    }

    while (i < n1) {
        palavras[k++] = esquerda[i++];

    }

    while (j < n2) {
        palavras[k++] = direita[j++];

    }
}



void mergeSort(vector<Palavra> &palavras, int inicio, int fim) {
    if (inicio < fim) {


        int meio = inicio + (fim - inicio) / 2;
        mergeSort(palavras, inicio, meio);
        mergeSort(palavras, meio + 1, fim);
        merge(palavras, inicio, meio, fim);
    }
}


 int particao(vector<Palavra> &palavras, int inicio, int fim) {

    int i = inicio -1;
    int pivo = palavras[fim].tamanho;
    for (int j = inicio; j < fim; j++) {
        if (palavras[j].tamanho > pivo) {
            i++;
            swap(palavras[i], palavras[j]);
        }

    }
    swap(palavras[i +1], palavras[fim]);
    return  i + 1;
}

void quickSort(vector<Palavra> &palavras, int inicio, int fim) {
   if (inicio < fim) {
       int pivo = particao(palavras, inicio, fim);
       quickSort(palavras, inicio, pivo -1);
       quickSort(palavras, pivo + 1, fim);

   }

}

int main() {
    int n;
    cin >> n;

    vector<Palavra> palavras(n);

    for (int i = 0; i < n; i++) {
        cin >> palavras[i].texto;
        palavras[i].tamanho = palavras[i].texto.length();
    }

    vector<Palavra> palavrasMerge = palavras;
    vector<Palavra> palavrasQuick = palavras;

    mergeSort(palavrasMerge, 0, n - 1);
    quickSort(palavrasQuick, 0, n - 1);

    cout << "[MergeSort] ";

    for (int i = 0; i < n; i++) {
        cout << palavrasMerge[i].texto << (i < n - 1 ? " " : "");
    }

    cout << endl;

    cout << "[QuickSort] ";

    for (int i = 0; i < n; i++) {
        cout << palavrasQuick[i].texto << (i < n - 1 ? " " : "");
    }

    cout << endl;

    return 0;
}
