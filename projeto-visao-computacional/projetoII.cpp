/****************
LAED1 - Projeto (Parte II) - Estimativa do formato da pista
Data: 29/08/2024
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

//função que cria um item
TipoItem createItem(int chave, int tipo, int numElementos, int pontoMedio){
    TipoItem item;

    //cria item
    item.Chave = chave;
    item.Tipo = tipo;
    item.NumElementos = numElementos;
    item.PontoMedio = pontoMedio;    

    return item;
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

//função que acha o formato da pista
string findFormat(vector<int> pontosMedios){
    int lastIndex = pontosMedios.size()-1;

    if(fabs(pontosMedios[0]-pontosMedios[lastIndex])/((pontosMedios[0]+pontosMedios[lastIndex])/2) < 0.1){
        return "Resultado: Pista em linha reta.";
    }
    else if(pontosMedios[0] > pontosMedios[lastIndex]){
        return "Resultado: Curva a direita.";
    }
    else {
        return "Resultado: Curva a esquerda.";
    }
}

int main(){

    int l; cin >> l;

    vector<int> pontosMedios;

    for(int i=0; i<l; i++){

        TipoLista lista;
        FLVazia(&lista);

        int n; cin >> n;

        int *v = (int*) malloc(n*sizeof(int));

        set<int> s;

        //preenche o vetor e o set
        for(int i=0; i<n; i++){
            cin >> v[i];
            s.insert(v[i]);
        }

        int countEql=1, col=0, chave=1, tipo, pontoMedio, ponto2;
        //faz o cálculo dos segmentos
        for(int i=0; i<n; i++){
            if(i!=0 && v[i]==v[i-1]){
                countEql++;
            }
            else if(i!=0 && v[i]!=v[i-1] || i==n-1){
                tipo = distance(s.begin(), s.find(v[i-1]))+1;
                pontoMedio = ((i-countEql)+(i-1))/2;

                if(tipo==2) ponto2 = pontoMedio;

                //insere item na lista
                Insere(createItem(chave, tipo, countEql, pontoMedio), &lista);

                countEql=1;
                chave++;
            }
        }
        tipo = distance(s.begin(), s.find(v[i-1]))+1;
        pontoMedio = ((i-countEql)+(i-1))/2;

        if(tipo==2) ponto2 = pontoMedio;

        //insere ultimo item na lista
        Insere(createItem(chave, tipo, countEql, pontoMedio), &lista);

        if(findPattern(lista)) pontosMedios.push_back(ponto2);
    }

    if(pontosMedios.size() < l*0.7){
        cout << "Resultado: Formato da pista nao estimado." << endl;
    }
    else {
        cout << findFormat(pontosMedios) << endl;
    }
}