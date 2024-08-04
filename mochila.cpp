#include <bits/stdc++.h>

using namespace std;

int achaValorOtimo(int n, int w, vector<pair<int,int>> pesoValor){
    
    //utilizacao de uma tabela para armazenar valores ja calculados
    vector<vector<int>> tabela(n+1, vector<int>(w+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            //se o peso do item for menor ou igual ao da coluna, pode testar
            if(pesoValor[i-1].first <= j){
                tabela[i][j] = max(tabela[i-1][j], tabela[i-1][j-pesoValor[i-1].first]+pesoValor[i-1].second);
            }
            //se não, continua com o valor anterior
            else {
                tabela[i][j] = tabela[i-1][j];
            }
        }
    }

    return tabela[n][w];
}

int main(){

    int w; cin >> w; //capacidade da mochila

    int n; cin >> n; //número de itens

    //vetor de pares que armazena o peso e o valor de cada item
    vector<pair<int,int>> pesoValor;
    for(int i=0; i<n; i++){
        int peso, valor; cin >> peso >> valor;
        pesoValor.push_back(make_pair(peso, valor));
    }

    //calcula o peso e valor totais dos itens indicados
    int pesoTotal=0, valorTotal=0;
    for(int i=0; i<n; i++){
        int escolhido; cin >> escolhido;
        if(escolhido==1){
            pesoTotal += pesoValor[i].first;
            valorTotal += pesoValor[i].second;
        }
    }

    if(pesoTotal>w){
        cout << "Solucao inviavel." << endl;
    }
    else if(pesoTotal<=w && valorTotal!=achaValorOtimo(n, w, pesoValor)){
        cout << "Solucao viavel mas nao otima." << endl;
    }
    else {
        cout << "Solucao otima." << endl;
    }
}