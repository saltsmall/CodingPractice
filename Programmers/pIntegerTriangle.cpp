#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

/* 
[동적계획법]
                                        queue
            X1                           X1
        X2      X3              X2+X1           X1+X3
    X4      X5      X6      X4+X2+X1    X5+둘중 큰거 .....

    L1 = X1;
    
    L2 = L1+X2;
    L3 = L1+X3;
    
    L4 = L2 + X4;
    L5 = max(L2,L3)+X5;
    L6 = L3 + X6;

 */

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size(); //한 변의 길이

    queue<int> q; //경로길이 저장

    q.push(triangle[0][0]);

    for(int i=1; i<size; i++){
        for(int j=0; j<triangle[i].size(); j++){
            if(j == 0 || j == triangle[i].size()-1){ //첫번째, 마지막번째
                int L = q.front();
                q.push(L + triangle[i][j]);
            }
            else{
                int L1 = q.front(); q.pop();
                int L2 = q.front();
                q.push(max(L1,L2)+triangle[i][j]);
            }
        }
        q.pop(); //마지막 원소 제거

    }

    //최대값 찾기
    while(!q.empty()){
        int value = q.front(); q.pop();
        if(answer<value) answer = value; 
    }
    return answer;
}