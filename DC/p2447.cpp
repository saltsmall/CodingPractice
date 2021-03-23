/*  
https://www.acmicpc.net/problem/2447
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > map (10000, vector<char>(10000, ' '));

void solve(int size, int x, int y){
    if(size == 1){
        map[x][y] = '*'; 
        return;
    }

    int next = size / 3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==1 && j==1) continue; // �߾�
            solve(next, x+i*next, y+j*next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    solve(N,0,0);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << map[i][j];
        }
        cout << "\n";
    } 
 
    return 0;
}