/*
https://www.acmicpc.net/problem/2331
*/

#include <vector>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

vector<int> visited(1000000,0);

int getSum(int num, int P){
    string str = to_string(num);
    int result = 0;
    for(int i=0; i<str.length(); i++){
        result += pow(str[i]-'0', P);
    }
    return result;
}

void DFS(int num, int P){
    visited[num]++;
    if(visited[num]>2) return;
    int next = getSum(num, P);
    DFS(next, P);
}

int main(){
    int A, P;
    cin >> A >> P;
    DFS(A, P);

    int ans = 0;
    for(int i=0; i<visited.size(); i++){
        if(visited[i]==1) ans++;
    }

    cout << ans;

    return 0;
}