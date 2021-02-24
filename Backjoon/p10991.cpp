/*  
https://www.acmicpc.net/problem/10991
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i=1; i<=n; i++){
        for (int b=1; b<=n-i; b++){
            cout <<" ";
        }
        for(int a=1; a<=2*i-1; a++){
            if(a%2){
                cout <<"*";
            }
            else cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
