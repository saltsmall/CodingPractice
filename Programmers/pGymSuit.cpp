#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    //전체학생은 0으로 초기화
    vector<int> student(n,0);

    //도난당한 학생
    for(int i=0; i<lost.size(); i++){
        student[lost[i]-1]--;
    } 

    //여벌복 가진 학생
    for(int i=0; i<reserve.size(); i++){
        student[reserve[i]-1]++;
        
        if(reserve[i] != 1){
            student[reserve[i]-2]++;
        }
        if(student[i] != n){
            student[reserve[i]]++;
        }
    }

    //체육복 없는 학생 수 세기

    for(int i=0; i<n; i++){
        if(student[i] != -1) answer++; 
    }

    return answer;
}