 /*  
 https://www.acmicpc.net/problem/2445
 */

#include <iostream>

using namespace std;

int main(){
    int n, c1, c2;
    cin >> n;

    for (int i=1; i<=(2*n-1); i++){
        if(i<=n){
           c1 = i;
           c2 = (n-i)*2;
        }
        else {
           c1 = 2*n-i;
           c2 = (i-n)*2;
        }

        for(int a=1; a<=c1; a++){
            cout << "*";
        }
        for(int b=1; b<=c2; b++){
            cout << " ";
        }
        for(int c=1; c<=c1; c++){
            cout << "*";
        }
        cout << "\n";
    }


    return 0;
}