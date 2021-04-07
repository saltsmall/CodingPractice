/*  
https://www.acmicpc.net/problem/11399
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> schedule(N);
    for(int i=0; i<N; i++){
        cin >> schedule[i];
    }

    sort(schedule.begin(), schedule.end());

    long long ans = 0; 
    for(int i=0; i<N; i++){
        ans += schedule[i]*(N-i);
    }

    cout << ans << "\n";

    return 0;
}