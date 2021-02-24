/*
https://www.acmicpc.net/problem/10818  
*/

#include <iostream>

using namespace std;

int main(){
    int min, max, n, a;

    cin >> n;
    cin >> a;
    min = a;
    max = a;
    for (int i=1; i<n; i++){
        cin >> a;
        if(a>max) max = a;
        else if(a<min) min = a;
    }
    cout << min << " " << max;
    return 0;
}