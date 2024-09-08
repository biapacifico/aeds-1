/****************
LAED1 - Projeto (Parte I) - Busca por padrão em sequência
Data: 16/08/2024
****************/

#include <bits/stdc++.h>

using namespace std;

#define INICIOARRANJO 1
#define MAXTAM 1000

typedef int TipoApontador;

typedef struct {
    int Chave;
    int Tipo;
    int NumElementos;
    int PontoMedio;
} TipoItem;

typedef struct {
    TipoItem Item[MAXTAM];
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista){
    Lista->Primeiro = INICIOARRANJO;
    Lista->Ultimo = Lista->Primeiro;
}

int Vazia(TipoLista Lista){
    return (Lista.Primeiro == Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista){
    if(Lista->Ultimo > MAXTAM){
        cout << "Lista está cheia\n";
    } 
    else {
        Lista->Item[Lista->Ultimo-1] = x;
        Lista->Ultimo++;
    }
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){
    int Aux;

    if(Vazia(*Lista) || p >= Lista->Ultimo){
        cout << "Erro: Posição não existe\n";
        return;
    }

    *Item = Lista->Item[p-1];
    Lista->Ultimo--;

    for(Aux=p; Aux<Lista->Ultimo; Aux++){
        Lista->Item[Aux-1] = Lista->Item[Aux];
    }
}

void Imprime(TipoLista Lista){
    for(int Aux=Lista.Primeiro-1; Aux<=(Lista.Ultimo-2); Aux++){
        cout << Lista.Item[Aux].Chave << "\n";
    }
}

//função que procura o padrão
bool findPattern(TipoLista Lista){
    int pattern[] = {1, 3, 2, 3, 1};

    for(int Aux=Lista.Primeiro-1; Aux<=(Lista.Ultimo-2)-4; Aux++){
        bool encontrado = true;

        for(int j=0; j<5; j++){
            if(Lista.Item[Aux+j].Tipo != pattern[j]){
                encontrado = false;
                break;
            }
        }
        if(encontrado) return true;
    }

    return false;
}

int main(){

    TipoLista lista;
    TipoItem item;

    FLVazia(&lista);

    int n; cin >> n;

    int *v = (int*) malloc(n*sizeof(int));

    set<int> s;

    //preenche o vetor e o set
    for(int i=0; i<n; i++){
        cin >> v[i];
        s.insert(v[i]);
    }

    int countEql=1, col=0, chave=1;
    //faz o cálculo dos segmentos
    for(int i=0; i<n; i++){
        if(i!=0 && v[i]==v[i-1]){
            countEql++;
        }
        else if(i!=0 && v[i]!=v[i-1] || i==n-1){
            //insere item na lista
            item.Chave = chave;
            item.Tipo = distance(s.begin(), s.find(v[i-1]))+1;
            item.NumElementos = countEql;
            item.PontoMedio = ((i-countEql)+(i-1))/2;
            Insere(item, &lista);

            countEql=1;
            chave++;
        }
    }
    //insere ultimo item na lista
    item.Chave = chave;
    item.Tipo = distance(s.begin(), s.find(v[n-1]))+1;
    item.NumElementos = countEql;
    item.PontoMedio = ((n-countEql)+(n-1))/2;
    Insere(item, &lista);

    if(findPattern(lista)){
        cout << "Resultado: Padrao encontrado." << endl;
    }
    else {
        cout << "Resultado: Padrao nao encontrado." << endl;
    }
}