#include<bits/stdc++.h>

using namespace std;
int cont = 0;
int particao(vector<int> &arr, int inicio, int  fim) {
    int  pivo = arr[fim];
    int i = inicio-1;
    for( int j = inicio; j  <  fim;  j++) {
        if (arr[j] <= pivo ){
            i++;
            swap(arr[j], arr[i]);
            if (i  != j) {
                cont++;
            }
        }
    }
    swap(arr[i + 1], arr[fim]);
    if (i + 1 != fim) {
        cont++;
    }
    return i + 1;
}

int quickSelect(vector<int>& arr, int inicio, int fim, int alvo) {
    if (inicio == fim) {
        return arr[inicio];
    }

    int   posicaoPivo = particao(arr, inicio, fim);

    if (posicaoPivo == alvo) {
        return arr[posicaoPivo];
    }
    if (posicaoPivo < alvo) {
        return  quickSelect(arr, posicaoPivo + 1, fim, alvo);
    }

    return quickSelect(arr, inicio, posicaoPivo - 1, alvo);   // MUDOU
}
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int alvo = n - k;

    int elemento =  quickSelect(arr, 0, n - 1, alvo);
    cout << elemento << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    cout << cont << endl;
}