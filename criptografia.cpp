#include <iostream>
#include <string>

using namespace std;

bool isLetra(char letra){
    if(letra>='a' && letra<='z' || letra>='A' && letra<='Z'){
        return true;
    } else {
        return false;
    }
}

string criptografia(string frase){
    for(int i=0; i<frase.size(); i++){
        if(isLetra(frase[i])){
            frase[i] = frase[i]+3;
        }
    }

    string fraseNova;
    for(int i=(frase.size()-1); i>=0; i--){
        fraseNova.push_back(frase[i]);
    }

    for(int i=(fraseNova.size()/2); i<fraseNova.size(); i++){
        fraseNova[i] = fraseNova[i]-1;
    }

    return fraseNova;
}

int main(){

    int casosDeTeste;
    cin >> casosDeTeste;
    cin.ignore();

    for(int i=1; i<=casosDeTeste; i++){
        string frase;
        getline(cin, frase);
        cout << criptografia(frase) << "\n";
    }
}