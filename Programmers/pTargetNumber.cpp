#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int getSum(queue<int> q, int target, int result, int sign){
    //sign의 값에 따라 달라진다. -1/1
    result += q.front()*sign; q.pop();

    //종료 조건
    if(q.empty()){
        if(target == result) return 1;
        else return 0;
    }
    //sign의 값에 따라 달라진다. -1/1
    
    return getSum(q, target, result, -1) + getSum(q, target, result, 1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    queue<int> q;
    for(int num: numbers) q.push(num);

    answer = getSum(q, target, 0, -1)+ getSum(q, target, 0, 1);

    return answer;
}