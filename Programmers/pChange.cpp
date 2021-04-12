/*  
https://programmers.co.kr/learn/courses/30/lessons/12907
*/
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    
    vector<long> dp(n+1, 0);

    for(int i=1; i<=n; i++){
        if(i % money[0] == 0){
            dp[i] = 1;
        }
    }

    for(int i=1; i<money.size(); i++){ //동전
        for( int j=money[i]; j<=n; j++){ //가격
            dp[j] += dp[j-money[i]] ;
        }
    }
    
    answer = (int)(dp[n] % 1000000007);

    return answer;
}