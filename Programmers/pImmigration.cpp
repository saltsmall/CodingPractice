#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*  
[이진 탐색]

배열 내부의 데이터가 정려되어 있어야만 사용가능한 알고리즘.

 이진탐색은 위치를 나타내는 변수 3개를 사용하는데 탐색하고자 하는 범위의
시작점, 끝점, 그리고 중간점이다. 찾으려는 데이터와 중간점 위치에 있는 데이터를 
반복적으로 비교해서 원하는데 데이터를 찾는 과정이다. 

최대시간(끝점)/ 최소시간(시작점)/ 평균시간(중간점)

최대인원이 총인원보다 크거나 같다면
=> answer = 평균시간, 최대시간 갱신

최대인원이 총이원보다 작다면
=> 현재보다 많은 시간 필요 : 최소시간 갱신


*/


long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long start = 1;
    long long mid;
    long long end = *max_element(times.begin(), times.end())*(long long)n;
    
    while(start<=end){
        //평균시간
        mid = (start+end) / 2;
        
        //평균시간 동안 수용할 수 있는 인원
        long long human = 0;
        for(int time:times){
            human += mid/time; 
        }
        
        //수용인원이 n보다 작기 때문에 더 많은 시간이 필요.
        if(human < n){
            start = mid + 1; //최소시간 갱신
        }
        else{ //human >= n
            //answer 갱신
            if(mid<=end) answer = mid; //
            end = mid -1; // 최대시간 갱신
        }        
    }

    return answer;
}