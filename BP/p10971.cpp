/*  
https://www.acmicpc.net/problem/10971
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<bool> visited(11);
vector<vector<int>> weight(11, vector<int>(11));
int start, N, ans = 1000000000;

void DFS(int node, int len, int cnt){
    if(cnt == N-1){
        if(weight[node][start]){
            ans = min(ans, len+ weight[node][start]);
            return;
        }
    }

    for(int i=0; i<N; i++){
        if(weight[node][i] && !visited[i]){
            visited[i] = true;
            DFS(i, len+ weight[node][i], cnt+1);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> N;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N ; j++) {
			cin >> weight[i][j];
		}
	}

    for (int i=0; i<N; i++){
        start = i;
        visited[i] = true;
        DFS(i,0,0);
        visited[i] = false;
    }

    cout << ans << "\n";
    return 0;
}