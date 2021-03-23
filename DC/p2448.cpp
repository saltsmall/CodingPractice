/*  
https://www.acmicpc.net/problem/2448
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > map(4000, vector<char>(7000, ' '));

void solve(int n, int x, int y){
    if(n== 3){
        map[x][y+2] = '*';
        map[x+1][y+1] = '*';
        map[x+1][y+3] = '*';
        for(int j=0; j<5; j++){
            map[x+2][y+j] = '*';
        }
        return;
    }

    for(int j=0; j<2; j++){
        int next = n/2;
        solve(next, x,y+next);
        solve(next, x+next, y);
        solve(next, x+next, y+n);
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    solve(N, 0, 0);

    for(int i=0; i<N; i++){
        for(int j=0; j<N*2-1; j++){
            cout << map[i][j];
        }
        cout << "\n";
    } 

    return 0;
}