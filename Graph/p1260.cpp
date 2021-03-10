/*  
https://www.acmicpc.net/problem/1260
*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

int main(){
    int N, M, V;
    cin >> N >> M >> V;

    vector<bool> visited_q(N, false);
    vector<bool> visited_s (N, false);
    vector<vector<int> > matrix(N, vector<int>(N, 0));
 
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;


        matrix[x-1][y-1] = 1;
        matrix[y-1][x-1] = 1;
    }

    stack<int> s;
    s.push(V-1);
    
    while(!s.empty()){
        int num = s.top(); s.pop();

        if(visited_s[num]) continue;
        visited_s[num] = true;

        cout << num+1 << " ";

        for(int i=N-1; i>=0; i--){
            if(matrix[num][i] == 1) s.push(i);
        }
    }
    cout << "\n";


    queue<int> q;
    q.push(V-1);
    while(!q.empty()){
        int num = q.front(); q.pop();

        if(visited_q[num]) continue;
        visited_q[num] = true;

        cout << num+1 << " ";
        for(int i = 0; i<N; i++){
            if(matrix[num][i] == 1) q.push(i);
        } 
    }

    return 0;
}