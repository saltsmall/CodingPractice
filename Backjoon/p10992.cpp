/*  
https://www.acmicpc.net/problem/10992
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i=1; i<=n; i++){
        for(int a=1; a<=n-i; a++){
            cout << " ";
        }
        for(int b=1; b<=2*i-1; b++){
            if(b==1||b==2*i-1||i==n) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }

    return 0;
}