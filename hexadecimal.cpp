#include <iostream>
#include <string>

using namespace std;

int main(){

    char letras[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    int numDecimal;
    cin >> numDecimal;

    int restoDivisao=0;
    string numeroHexadecimal;

    while(numDecimal){
        restoDivisao = numDecimal%16;
        numeroHexadecimal.push_back(letras[restoDivisao]);

        numDecimal = numDecimal/16;
    }

    for(int i=numeroHexadecimal.size()-1; i>=0; i--){
        cout << numeroHexadecimal[i];
    }
    cout << "\n";
}