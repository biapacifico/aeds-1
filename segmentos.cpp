#include <bits/stdc++.h>

using namespace std;

//função responsável por fazer realocação de matriz e preencher
void reallocMatrix(int **matrix, int col, int countEql, int c){
    for(int j=0; j<2; j++){
        matrix[j] = (int*)realloc(matrix[j], col*sizeof(int));
    }
    matrix[0][col-1] = c;
    matrix[1][col-1] = countEql;
}

int main(){

    int n; cin >> n;

    int *v = (int*) malloc(n*sizeof(int));

    set<int> s;

    //alocação dinâmica da matriz com duas linhas
    int **matrix = (int**) malloc(2*sizeof(int*));
    for(int i=0; i<2; i++){
        matrix[i] = (int*) malloc(1*sizeof(int));
    }

    //preenche o vetor e o set
    for(int i=0; i<n; i++){
        cin >> v[i];
        s.insert(v[i]);
    }

    int countEql=1, col=0;
    //faz o cálculo dos segmentos
    for(int i=0; i<n; i++){
        if(i!=0 && v[i]==v[i-1]){
            countEql++;
        }
        else if(i!=0 && v[i]!=v[i-1]){
            auto pos = s.find(v[i-1]);
            reallocMatrix(matrix, ++col, countEql, distance(s.begin(), pos)+1);
            countEql=1;
        }
    }
    auto pos = s.find(v[n-1]);
    reallocMatrix(matrix, ++col, countEql, distance(s.begin(), pos)+1);

    //print da matriz
    for(int i=0; i<2; i++){
        for(int j=0; j<col; j++){
            if(j==col-1) cout << matrix[i][j];
            else cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}