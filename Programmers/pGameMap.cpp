#include<vector>
#include<queue>
#include<iostream>
using namespace std;

/*  
BFS사용 : queue 
최단 경로 길이는 queue size를 사용해서 계산
*/

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(); //y_size
    int m = maps[0].size(); //x_size
    pair<int,int> desti = make_pair(m-1, n-1);//도착지
    vector<vector<bool> > visited (n, vector<bool>(m, false));
    queue<pair<int,int> > q;

    //이동
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    //첫번째 원소 넣기
    q.push(make_pair(0,0)); 

    bool find = false;
    while(!q.empty()){
        int q_size = q.size();
        for(int i=0; i<q_size; i++){
            pair<int, int> coord = q.front(); q.pop(); 

            int x = coord.first;
            int y = coord.second; 

            //방문 여부 확인
            if(visited[y][x]) continue;
            visited[y][x] = true;

            //목적지 도착
            if(coord == desti){
                find = true;
                break;
            }

            //갈 수 있는 경로 탐색
            for(int j=0; j<4; j++){
                int x2 = x + dx[j];
                int y2 = y + dy[j];

                //범위 확인
                if(x2<0||m<=x2) continue;
                if(y2<0||n<=y2) continue;

                if(maps[y2][x2] == 1){
                    q.push(make_pair(x2,y2));
                }
            }
        }
        //경로 길이 갱신
        answer++; 

        if(find) {
            break;
        }
    }

    if(!find) return -1;

    return answer;
}