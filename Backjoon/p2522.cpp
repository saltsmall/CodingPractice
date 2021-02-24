/*  
https://www.acmicpc.net/problem/2522
*/

#include <iostream>

using namespace std;

int main(){
    int n, c1, c2;
    cin >> n;

    for(int i=1; i<=2*n-1; i++){
        
        if(i <= n) {
            c1 = n-i;
            c2 = i;
        }
        else {
            c1 = i-n;
            c2 = 2*n-i;
        }

        for(int a=1; a<=c1; a++) cout << " ";
        for(int b=1; b<=c2; b++) cout << "*";

        cout <<"\n";
    }

    return 0;
}