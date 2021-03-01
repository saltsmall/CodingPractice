#include <string>
#include <vector>
#include <iostream>

using namespace std;

//회전
void rotation(vector<vector<int>> &key){
    const int size = key.size();
    vector<vector<int>> temp(size, vector<int>(size,0));
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            temp[i][j] = key[size-j-1][i];
        }
    }
    key = temp;
}

//키확인
bool check_key(vector<vector<int>> v, vector<vector<int>> key, int dx, int dy){
    const int V_SIZE = v.size();
    const int KEY_SIZE = key.size();

    for(int i=0; i<KEY_SIZE; i++){
        for(int j=0; j<KEY_SIZE; j++){
            v[i+dy][j+dx] ^= key[i][j];
        }
    }

    for(int i=KEY_SIZE-1; i<=V_SIZE-KEY_SIZE; i++){
        for(int j=KEY_SIZE-1; j<=V_SIZE-KEY_SIZE; j++){
            if(v[i][j]!= 1) return false;
        }
    }
    return true;
}

void print_vec(vector<vector<int>>v){
    for(vector<int> vec: v){
        for(int i: vec){
            cout << i << " ";
        }
        cout << "\n";
    }
    cout <<"\n\n";
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    const int KEY_SIZE = key.size();
    const int LOCK_SIZE = lock.size();
    const int V_SIZE = KEY_SIZE*2 + LOCK_SIZE -2;
    vector<vector<int>> v(V_SIZE, vector<int>(V_SIZE,0));


    //lock 위치 고정
    for(int i = 0; i<LOCK_SIZE; i++){
        for(int j= 0; j<LOCK_SIZE; j++){
            v[i+KEY_SIZE-1][j+KEY_SIZE-1] = lock[i][j]; 
        }
    }

    for(int dy = 0; dy<=V_SIZE-KEY_SIZE; dy++){
        for(int dx=0; dx<=V_SIZE-KEY_SIZE; dx++){
            for(int r=1; r<=4; r++){ //네방향 검사
                if(check_key(v,key,dx,dy)) return true; // 찾음    
                rotation(key); // 회전
            }
        }
    }

    return answer;
}