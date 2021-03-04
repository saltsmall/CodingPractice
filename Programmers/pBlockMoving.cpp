#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

/*
[블록 이동] -> 최소시간 (BFS사용)
최소시간을 구하기 위해선 
q.pop()하고 난뒤 push한 횟수를 세어서 size를 비교하여 size 0일 될때 depth 증가

q : a, b1, b2, b3, c1
d : 1 -> count ++;, 3 -> count ++;

<움직이는 방식>
1.상하좌우
2.회전(반시계 시계)
           
<블럭 형태>
방향에 따라서 달라짐 (x, y)와 방향

queue : (dir, x, y) 저장

robot location : (x1, y1) (x2, y2)
|
|
y x-------

1. up(0) : x2 = x1, y2 = y1-1
2. right(1) : x2 = x1+1, y2 = y1
3. down(2) : x2 = x1, y2 = y1+1
4. left(3) : x2 = x1-1, y2 = y1
*/
bool checkRange(int size, int x, int y){
    if(0 > x || x >= size) return false;
    if(0 > y || y >= size) return false;
    return true;
}
pair<int, int> selectPush(int dir, int x, int y){
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    if(dir == 0 || dir == 3) return make_pair(x+dx[dir], y+dy[dir]);
    else return make_pair(x, y);
}



int solution(vector<vector<int>> board) {
    int answer = 0;
    int b_size = board.size();
    pair<int,int> destination = make_pair(b_size-1, b_size-1);

    vector<bool, vector<bool>> visited_horizonal(b_size , vector<bool>(b_size, false)); 
    vector<bool, vector<bool>> visited_vertical(b_size , vector<bool>(b_size, false));

    //move value;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    //roate value;
    int rx[4] = {1, 1, -1, -1};
    int ry[4] = {1, -1, -1, 1};

    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(1,make_pair(0,0))) //right, (0,0)
    
    while(!q.empty){
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            int dir = q.front().first;
            int x = q.front().second.first; int y = q.front().second.second;
            int x2 = x+dx[dir];             int y2 = y+dy[dir];
            q.pop();

            //도착지 도착
            if(make_pair(x,y) == destination || make_pair(x2, y2)) return answer;

            //방문 확인
            if(dir == 0 && visited_vertical[y2][x2]) continue;
            else visited_vertical[y2]][x2] = true;

            if(dir == 1 && visited_horizonal[y][x]) continue;
            else visited_horizonal[y][x] = true;

            if(dir == 2 && visited_vertical[y][x]) continue;
            else visited_vertical[y][x] = true;

            if(dir == 3 && visited_horizonal[y2][x2]) continue;
            else visited_horizonal[y2][x2] = true;

            //상하좌우 이동
            for(int j=0; j<4; j++){
                if(checkRange(x+dx[i], y+dy[i]) && checkRange(x2+dx[i], y2+dy[i])){ // 범위 체크
                    if(board[y+dy[i]][x+dx[i]] == 0 && board[y2+dy[i]][x2+dx[i]] == 0){// 갈 수 있는 길인지 체크
                        q.push(make_pair(dir, selectPush(dir, x, y)));
                    }
                }
            }

            //시계 회전
            for(int j = 0; j<4; j++){
                int d = (dir+j)%4
                int n_d = (dir+1+j)%4
                if(checkRange(x+rx[d], y+ry[d]) && checkRange(x+dx[n_d], y+dy[n_d])){
                    if(board[y+ry[d]][x+rx[d]] == 0 && board[y+dx[n_d]][x+dx[n_d]]){
                        q.push(make_pair(n_d, selectPush(dir, x, y)));
                    }
                    else break;
                }
                else break;
            }

            //반시계 회전
            for(int j = 0; j<4; j++){
                int d = (dir-j)%4;
                if(d<0) d += 4;
                int n_d = (dir-1-j)%4
                if(n_d<0) d += 4;

                if(checkRange(x+rx[d], y+ry[d]) && checkRange(x+dx[n_d], y+dy[n_d])){
                    if(board[y+ry[d]][x+rx[d]] == 0 && board[y+dx[n_d]][x+dx[n_d]]){
                        q.push(make_pair(n_d, selectPush(dir, x, y)));
                    }
                    else break;
                }
                else break;
            }

        }
        answer++;
    }

    return answer;
}