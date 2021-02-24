#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    vector<string> used_words;
    int order= 0;

    for(order = 0; order< words.size(); order++){
        //현재 낱말
        string curWord = words[order];
        cout << "현재 단어는" <<curWord <<"\n";
        //조건3
        if(order != 0){
            string befWord = words[order-1];
            if(befWord[befWord.length()-1] != curWord[0]){
                break;
            }
        }
        //조건4
        bool find = false;
        for (string str : used_words){
            if(str == curWord) find = true;
        }
        if(find) break;

        //통과시
        used_words.push_back(curWord);
    }

    cout << order;

    //탈락자 없음
    if(order == words.size()){
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    
    int order_person = (order+1) % n;
    if (order_person == 0) order_person = n;

    int order_word = (order+1) /n;
    if (order_person != n) order_word ++;
    answer.push_back(order_person);
    answer.push_back(order_word);
    
    return answer;
}