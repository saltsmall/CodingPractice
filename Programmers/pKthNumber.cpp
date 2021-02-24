#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i=0; i<commands.size(); i++){
        vector<int> split = array;
        for(int k=commands[i][0]; k<=commands[i][1]; k++){
            split.push_back(array[k-1]);
        }
        sort(split.begin(),split.end());
        answer.push_back(split[commands[i][2]-1]);
    }

    return answer;
}

