#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> map;

    for(vector<string> v: clothes){
        string key = v[1];
        string value = v[0]
        if(map.end() == map.find(key)){
            map.insert(make_pair(key,1));
        }
        else{
            map[key]++;
        }
    }

    unordered_map<string, int>::iterator iter;
    for(iter = map.begin(); iter!= map.end(); iter++){
        answer = answer * ((iter->second)+1)
    }
    answer--;
    return answer;
}