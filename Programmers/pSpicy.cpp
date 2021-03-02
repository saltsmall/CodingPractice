#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end() );
    int first_low, second_low;
    
    while (pq.top()<K ){
        //모든 음식의 스코빌 지수가 k를 넘지 않으면 -1 반환
        if(pq.size() == 1) return -1;
        first_low = pq.top(); pq.pop();
        second_low = pq.top(); pq.pop();
        //섞기
        pq.push(first_low + second_low*2);
        answer++; //횟수 증가;

    }
    return answer;
}