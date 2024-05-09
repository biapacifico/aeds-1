#include <bits/stdc++.h>

using namespace std;
 
int potencia(int base, int expoente){

    if(expoente==0){
        return 1;
    }
    else {
        return base*potencia(base, expoente-1);
    }

}

int main(){

    int base, expoente;
    cout << "Digite a base e o expoente inteiros: ";
    cin >> base >> expoente;

    cout << "Resultado: " << potencia(base, expoente) << endl;
}