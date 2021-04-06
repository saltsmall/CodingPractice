/*  
https://www.acmicpc.net/problem/2011
*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX 5001
vector<long long> dp(MAX, 0);
vector<int> input (MAX);

int main(){
    string N;
    cin >> N;
    int len = N.length();

    dp[0] = 1;
    
    for(int i=1; i <= len; i++){
        input[i] = N[i-1] -'0';
        if( input[i] != 0){
            dp[i] = (dp[i-1] +dp[i])%1000000;
        }
        int num = input[i] + input[i-1]*10; // 숫자 두자리

        if(num>=10 && num<=26){
            dp[i] = (dp[i-2] +dp[i])%1000000;
        }
    }

    cout << dp[len] << "\n";

    return 0;
}