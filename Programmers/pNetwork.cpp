#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 1;

    vector<bool> visited(n, false);
    queue<int> q; //BFS
    //stack<int> st; DFS
    q.push(0); //컴퓨터 개수 1<= n <= 200

    while(!q.empty()){ //queue가 비어져있다면
        int v = q.front(); q.pop();
        
        if (!visited[v]){
            visited[v] = true; //방문함
            //연결되어 있는 것중 방문하지 않은 컴퓨터 q에 넣기
            for(int i=0; i<n; i++){
                if(computers[v][i] == 1 && !visited[i]) q.push(i);
            }
        }
        
        //연결된게 하나라도 없으면 q는 비워져있음
        
        //q가 비어져있다면 방문하지 않은 컴퓨터 q에 넣기
        //방문할 수 있는 컴퓨터가 없다면 q는 empty상태로 while문은
        if(q.empty()){
            for(int i=0; i<n; i++){
                if(!visited[i]){
                    q.push(i);
                    answer ++; //네트워크 수 증가
                    break; //하나만 찾고 그만
                }  
            }
        }
    }

    return answer;
}