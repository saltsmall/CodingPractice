/* 
https://www.acmicpc.net/problem/2446
*/

#include <iostream>

using namespace std;

int main(){
    int n, c1, c2;
    cin >> n;

    for (int i=1; i<=(2*n-1); i++){
        if (i <=n){
            c1 = i-1;
            c2 = (2*n-1)-(i-1)*2;
        }
        else {
            c1 = (2*n-1)-i;
            c2 = 2*(i-n+1)-1;
        }

        for (int a=1; a<=c1; a++ ){
            cout << " ";
        }
        for (int b=1; b<=c2; b++ ){
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}