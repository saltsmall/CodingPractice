#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    unordered_map<string, int> map;
    for(string e : completion){
        if(map.end() == map.find(e)){
            map.insert(make_pair(e, 1));
        }
        else map[e]++;
    }

    for(string e: participant){
        if(map.end() == map.find(e)){
            answer = e;
        }
        else {
            map[e]--;
            if(map[e]<0){
                answer = e;
                break;
            }
        }
    }

    return answer;
}

