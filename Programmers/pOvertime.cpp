#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> q; //중복가능
    //priority_queue<int, vector<int>, less<int> > q; 내림차순
    //priority_queue<int, vector<int>, greater<int> > q; 오름차순

    //삽입
    for(int i :works){
        q.push(i);
    }

    //가장 큰 수에 -1를 해준다.
    int max;
    for(int i=0; i<n; i++){
        if(q.top() > 0){
            max = q.top(); q.pop();
            if(max >0) max--;
            q.push(max);

        }
    }

    //야근 지수값 구하기
    while(!q.empty()){
        answer +=  q.top()*q.top(); q.pop();
    }

    return answer;
}