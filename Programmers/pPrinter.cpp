#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    priority_queue<int> pq;
    queue<pair<int, int> > q;

    for(int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
        q.push(make_pair(i, priorities[i]));
    }

    while(!q.empty()){
        int id = q.front().first;
        int pri = q.front().second;
        
        if(pri == pq.top()){
            answer++;
            pq.pop();
            if(id == location){
                break;
            }
        }
        else{
            q.push(q.front());
        }
        q.pop();

    }

    return answer;
}