/*  
https://www.acmicpc.net/problem/2186
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

#define MAX 100

int N, M, K;
vector<vector<char>> MAP(MAX, vector<char>(MAX));
//방문하지 않으면 -1
int DP[MAX][MAX][80];

string Dest;
int Dest_len;

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1 ,1};


int DFS(int x, int y, int Idx)
{
    if (DP[x][y][Idx] != -1) return DP[x][y][Idx];
    if (Idx >= Dest_len) return 1;
 
    DP[x][y][Idx] = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int k = 1; k <= K; k++)
        {
            int nx = x + dx[i] * k;
            int ny = y + dy[i] * k;
 
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (MAP[nx][ny] != Dest[Idx]) continue;
 
            DP[x][y][Idx] = DP[x][y][Idx] + DFS(nx, ny, Idx + 1);
        }
    }
    return DP[x][y][Idx];
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int ans = 0;

    cin >> N >> M >> K;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> MAP[i][j];
        }
    }
    cin >> Dest;
    Dest_len = Dest.length();
    memset(DP, -1, sizeof(DP));

    char temp = Dest[0];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(MAP[i][j] == temp) ans += DFS(i, j, 1);
        }
    }

    cout << ans << "\n";

    return 0;
}