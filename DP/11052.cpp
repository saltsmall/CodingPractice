/*  
https://www.acmicpc.net/problem/11052
*/

#include<iostream>
#include<vector>
using namespace std;

#define MAX 1001

vector<int> dp(MAX);
vector<int> cards(MAx);

int main(){
    int buy;
    cin >> buy;
    for(int i=1; i<=buy; i++){
        cin >> cards[i];
    }

    dp[1] = cards[1];
    for(int i=2; i<=buy; i++){

        for(int j=1; j<i; i++){
            if(i%j == 0) 
        }
    }

    
    return 0;
}