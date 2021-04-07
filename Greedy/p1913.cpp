/*  
https://www.acmicpc.net/problem/1931
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<long, long> Pair;

bool compare(Pair a, Pair b){
    if(a.second  == b.second) return a.first < b.first;
    else return a.second < b.second;
}


int main(){
    int N;
    cin >> N;
    vector<Pair> schedule(N);
    for(int i=0; i<N; i++){
        cin >> schedule[i].first >> schedule[i].second;
    }

    sort(schedule.begin(), schedule.end(), compare);
    int end = schedule[0].second;
    int count = 1;
    for(int i=1; i<N; i++){
        if(end <= schedule[i].first){
            count ++; 
            end = schedule[i].second;
        }
    }
    cout << count;



    return 0;
}