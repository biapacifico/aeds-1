#include <bits/stdc++.h>

using namespace std;

int numDigitos(int numero){

    if(numero<10){
        return 1;
    }
    else {
        return 1+numDigitos(numero/10);
    }

}

int main(){

    int num, cont=0;
    cout << "Digite um numero inteiro: ";
    cin >> num;

    cout << "Resultado: " << numDigitos(num) << endl;

}