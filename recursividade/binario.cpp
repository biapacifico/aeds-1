#include <bits/stdc++.h>

using namespace std;
 
void dec2bin(int decimal){

    if(decimal>0){
        dec2bin(decimal/2);
        cout << decimal%2;
    }

}

int main(){

    int decimal;
    cout << "Digite um numero inteiro: ";
    cin >> decimal;

    cout << "Resultado: ";
    dec2bin(decimal);
    cout << "\n";

}