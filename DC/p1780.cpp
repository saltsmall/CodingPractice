/*  
https://www.acmicpc.net/problem/1780
*/

#include <vector>
#include <iostream>

using namespace std;

vector<vector<int> > vec(2187, vector<int>(2187));

int countPaper[3]; // -1 0 1

bool isSame(int x, int y, int N){
    int num = vec[y][x];
    for(int i=y; i<y+N; i++){
        for(int j=x; j<x+N; j++){
            if(num != vec[i][j]) return false;
        }
    }
    return true;
}

//종이의 숫자를 확인 틀릴 경우 나누기
void check(int x, int y, int N){
    if(isSame(x,y,N)){
        countPaper[vec[y][x]+1] ++;
        return;
    }
    int M = N/3;
    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            check(x+M*j, y+M*i, M);
        }
    }
}

int main(){
    int N;
    cin >> N;


    //배열 삽입
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> vec[i][j];
        }
    }

    check(0,0,N);

    for(int num: countPaper){
        cout << num << "\n";
    }

    return 0;
}