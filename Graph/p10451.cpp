/*  
https://www.acmicpc.net/problem/10451
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> matrix(1000,0);
vector<bool> visited(1000,false);

void DFS(int start){
    stack<int> s;
    s.push(start); //1

    while(!s.empty()){
        int num = s.top(); s.pop();

        if(visited[num]) continue;
        visited[num] = true;

        s.push(matrix[num]);
    }
}

int test(int N){
    int ans = 0;
    int n;
    //초기화
    for(int i=1; i<=N; i++){
        cin >> n;
        matrix[i] = n;
        visited[i] = false;
    }
    //DFS
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            DFS(i);
            ans++;
        }
    }
    return ans;
}


int main(){
    int T, N;

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N;
        cout << test(N) << "\n";
    }
    return 0;
}