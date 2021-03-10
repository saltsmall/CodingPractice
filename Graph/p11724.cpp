/*  
https://www.acmicpc.net/problem/11724
*/

#include <queue>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > matrix (1001, vector<int>(1001, 0));
vector<bool> visited (1001, false);

void BFS(int start, int N){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int num = q.front(); q.pop();

        if(visited[num]) continue;

        visited[num] = true;
        
        for(int i=1; i<=N; i++){
            if(matrix[num][i] == 1){
                q.push(i);
            } 
        }
    }
}

int main(){
    int answer = 0;
    int N, M;
    cin >> N >> M;

    for(int i=1; i<=M; i++){
        int x, y;
        cin >> x >> y;

        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }

    for(int i=1; i<=N; i++){
        if(!visited[i]) {
            BFS(i, N);
            answer++;
        }
    }
    cout << answer << "\n";

    return 0;
}