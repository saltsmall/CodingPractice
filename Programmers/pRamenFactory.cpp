#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq; //우선순위 큐 supplies가 가장 큰 것을 선택
    int start = 0; //시작점

    //하루 1톤씩 사용 -> k날 까지 쓸 수 있는 stock이 남아 있을 경우, 멈춤.
    while(stock < k){
        //주문할 수 있는 날짜 확인 -> supplies를 우선순위 큐 에 삽입
        for(int i=start; i<dates.size(); i++){
            if(stock < dates[i]) {
                /*
                start = i;
                -start가 갱신되지 않아서 여러개를 넣을 수 있음!!  
                */
                break; 
            }
            pq.push(supplies[i]);
            start = i+1;
        }
        stock += pq.top(); pq.pop(); //가장 많은 양 선택;
        answer ++;
    }

    return answer;
}