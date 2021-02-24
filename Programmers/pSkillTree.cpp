#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    /*  
    1. 현재 스킬은  선행 스킬이 필요한 스킬인가 확인
    1-1. 아니다 : continue;
    
    2. 맞다 : 선행 스킬을 모두 배웠는가 확인.
    2-1. 맞다: 다음 스킬 확인;
    
    */

    for(string str : skill_trees){
        bool success = true;
        vector<char> learned_skill;
        cout << str << "\n";
        int i;
        for(i=0; i<str.length(); i++){
            int order = skill.find(str[i]);

            //현재 스킬은 선행 스킬이 필요한가?
            if(order== string::npos || order == 0){
                learned_skill.push_back(str[i]);
                continue;
            }

            //선행스킬은 배웠는가?
            bool find = false;
            for(char c : learned_skill){
                if(skill[order-1] == c){
                    learned_skill.push_back(str[i]);
                    find = true;
                    break;
                }
            }
            if(find) continue;
            success = false;
            break;
        }
        if(success) answer++;
    }

    return answer;
}
