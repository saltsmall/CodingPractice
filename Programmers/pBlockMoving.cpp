#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
[block move]
have to know : minTime => use BFS

how to move:
1. up and down
2. rotate

so we have to know direction
direction : h or v
            
queue : (x1, y1) (x2, y2) store this 
robot location : (x1, y1) (x2, y2)
|
|
y x-------

board[y][x]
if it is h : x2 = x1+1 , y1 = y2
if it is v : x1 = x2, y2 = y1+1

queue size store -> depth count

[move] up down right left
[rotate] left_up, left_down, right_up, left_up
8 way moving

then visit?....

direction 0 , 1 , 2, 3
x1, y1



*/

bool isHorizontal (pair<int,int> coord, pair<int, int> coord2){
    if(coord.first == coord2.first) return false;
    return true;
}

bool checkRange(int size, int x, int y){
    if(0 > x || x >= size) return false;
    if(0 > y || y >= size) return false;
    return true;
}


int solution(vector<vector<int>> board) {
    int answer = 0;
    int board_size = board.size();
                 //up down left right      
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};

    int rx[4] = {1,-1,};
    int ry[4] = {-1,-1,}

    pair<int,int> destination = make_pair(board_size-1, board_size-1);
    vector<pair<int,int>> location = {make_pair(0,0), make_pair(1,0)};
    queue<vector<pair<int,int>>> q;

    //check visit
    vector<vector<bool>> visited_h (board_size, vector<bool> (board_size, false));
    vector<vector<bool>> visited_v (board_size, vector<bool> (board_size, false));
    q.push(location);

    while(!q.empty()){
        pair<int, int> coord = q.front().front(); 
        pair<int, int> coord2 = q.front().back(); q.pop();

        //is arrived?
        if(coord == destination || coord2 == destination) break; 

        //no
        bool hor = isHorizontal(coord, coord2);
        int x1 = coord.first, y1 = coord.second;
        int x2 = coord2.first, y2 = coord2.second;

        //is visited?
        if(hor && visited_h[y1][x1]) continue;
        else visited_h[y1][x1] = true;
        if(!hor && visited_v[y1][x1]) continue;
        else visited_v[y1][x1] = true;

        //move
        for(int i=0; i<4; i++){
            if(!checkRange(board_size, x1+dx[i], y1+dy[i]) || !checkRange(board_size, x2+dx[i], y2+dy[i])) continue;
            if(board[y1+dy[i]][x1+dx[i]] == 0 && board[y2+dy[i]][x2+dx[i]] == 0){
                location = {make_pair(x1+dx[i], y1+dy[i]), make_pair(x2+dx[i], y2+dy[i])};
                q.push(location);
            }
        }

        //rotate
        for()



    return answer;
}