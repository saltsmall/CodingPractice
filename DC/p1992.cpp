/*  
https://www.acmicpc.net/problem/1992
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > vec (64, vector<int>(64));

bool isSame(int x, int y, int N){
    int num = vec[y][x];
    for(int i=y; i<y+N; i++){
        for(int j=x; j<x+N; j++){
            if(num != vec[i][j]){
                return false;
            }
        }
    }
    return true;
}

void check(int x, int y, int N){
    if(isSame(x, y, N)){
        cout << vec[y][x];
        return;
    }

    cout << "(";    
    int M = N/2;
    check(x, y, M);
    check(x+M, y, M);    
    check(x, y+M, M);
    check(x+M, y+M, M);
    cout << ")";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    //배열 삽입
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c;
            cin >> c;
            vec[i][j] = c -'0';
        }
    }

    check(0,0,N);

    return 0;
}