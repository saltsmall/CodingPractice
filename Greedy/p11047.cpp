/*  
https://www.acmicpc.net/problem/11047
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int ans = 0;
    int N, K;
    cin >> N >> K;

    //코인 
    vector<int> coins(N);
    for(int i=0; i<N; i++){
        cin >> coins[i];
    }

    for(int i=N-1; i>=0; i--){
        if(K/coins[i] != 0){
            ans += K/coins[i];
            K %= coins[i];
        }
    }

    cout << ans;
    
    return 0;
}