#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    if(progresses.size()==0){
        answer.push_back(0);
        return answer;
    } 
    
    stack <int> s;
    int length = progresses.size();
    for(int i=length-1; i>=0; i--){
        int count = (100 - progresses[i]);
        if(count%speeds[i]>0) {
            count/= speeds[i];
            count ++;
        }
        else {
            count/= speeds[i];
        }
        s.push(count);
    }
    //스택 s에는 횟수가 저장됨. 

    int before = s.top();
    cout<< before << "\n";
    s.pop();
    int count = 1;
    
    for(int i=1; i<length; i++){
        int day = s.top();
        cout<<day <<"\n";
        s.pop();
        if(before >= day){ //이전과 비교해서 작을경우, 같은 날 배포가능
            count ++;
        }
        else{
            answer.push_back(count); // 아닐 경우, 배포가능한 수 푸쉬 
            count = 1;
            before = day;
        }
    }
    answer.push_back(count); // 남아있는 작업 푸쉬
    
    return answer;
}