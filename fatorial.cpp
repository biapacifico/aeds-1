#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n; cin >> n;

    vector<int> ans(10000, 0);
    ans[0] = 1;
    int tam=1, sobra=0;

    for(int i=2; i<=n; i++){
        for(int j=0; j<tam; j++){
            int mult = (i*ans[j])+sobra;
            ans[j] = mult%10;
            sobra = mult/10;
        }
        while(sobra!=0){
            ans[tam] = sobra%10;
            sobra = sobra/10;
            tam++;
        }
    }

    cout << "Resultado: ";
    for(int i=tam-1; i>=0; i--){
        cout << ans[i];
    }
    cout << "\n";
}