#include <iostream>
#include <cstdlib>

using namespace std;

int main(){

    int n; cin >> n;

    int* arranjo = (int*) malloc(0*sizeof(int)); //alocação dinâmica de vetor

    int tam=0;
    for(int i=0; i<n; i++){
        int num; cin >> num;

        if (i==0 || (i!=0 && arranjo[tam-1]!=num)){
            arranjo = (int*) realloc(arranjo, (tam+1)*sizeof(int));
            arranjo[tam] = num;
            tam++;
        }
    }

    cout << tam << endl;

    for(int i=0; i<tam; i++){
        if(i == tam-1){
            cout << arranjo[i];
        }
        else {
            cout << arranjo[i] << " ";
        }
    }
    cout << "\n";

    free(arranjo);
}