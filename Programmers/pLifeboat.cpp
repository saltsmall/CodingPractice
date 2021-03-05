#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int size = people.size();
    int min = 0;

    sort(people.begin(), people.end());

    while(!people.empty()){
        if(people.size() <= min ) break;
        if(people.back() + people[min] <= limit){
            min += 1;
        }
        people.pop_back();
        answer++;

    }
    return answer;
}