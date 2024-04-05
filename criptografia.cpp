#include <iostream>
#include <string>
#include <cctype>
 
using namespace std;

char cifraDeCesar(char letra){
    string letras = "abcdefghijklmnopqrstuvwxyz";

    bool letraMaiuscula = isupper(letra);
    if(letraMaiuscula){
        letra = tolower(letra);
    }

    char letraDecifrada;
    for(int i=0; i<letras.length(); i++){
        if(letra == letras[i]){
            int posicao = i-5;
            posicao < 0 ? posicao = letras.length()+posicao : posicao;
            letraDecifrada = letras[posicao];
        }
    }

    return letraMaiuscula ? letraDecifrada = toupper(letraDecifrada) : letraDecifrada;
}

int main() {
 
    string mensagemCodificada;
    getline(cin, mensagemCodificada);

    string mensagemDecodificada = mensagemCodificada;

    //substituição das letras pela cifra de césar e da # pelo espaço
    for(int i=0; i<mensagemDecodificada.length(); i++){
        if(isalpha(mensagemCodificada[i])){
            mensagemDecodificada[i] = cifraDeCesar(mensagemDecodificada[i]);
        } else {
            mensagemDecodificada[i] = ' ';
        }
    }

    //reflexão de cada bloco de 2 letras
    char aux0;
    for(int i=0; i<mensagemDecodificada.length(); i+=2){
        aux0 = mensagemDecodificada[i];
        mensagemDecodificada[i] = mensagemDecodificada[i+1];
        mensagemDecodificada[i+1] = aux0;
    }

    //permutação dos blocos de 2 letras
    char aux, aux2;
    for(int i=0, j=(mensagemDecodificada.length()-1); i<(mensagemDecodificada.length()/2), j>(mensagemDecodificada.length()/2); i+=4, j-=4){
        aux = mensagemDecodificada[i];
        mensagemDecodificada[i] = mensagemDecodificada[j-1];
        mensagemDecodificada[j-1] = aux;

        aux2 = mensagemDecodificada[i+1];
        mensagemDecodificada[i+1] = mensagemDecodificada[j];
        mensagemDecodificada[j] = aux2;
    }

    cout << "Mensagem codificada:\n" << mensagemCodificada << "\n";
    cout << "Mensagem decodificada:\n" << mensagemDecodificada << "\n";
 
    return 0;
}