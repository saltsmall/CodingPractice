#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*  
[BFS와 DFS]

<DFS> : 스택 -> 재귀사용
-조합(최단거리로 갈 수 있는 경로의 수)
-목적지에 도달할 수 있는지 여부
-n에 대해서 조건
-모드 노드 확인

<BFS> : 큐 ->재귀사용못함. while문 사용
-최단거리(최단경로),
-가중치 같고 최소비용 또는 최소횟수
*/


/* 
[단어 변환]

최소 몇 단계의 과정을 거쳐 begin을 target으로 변환할 수 있는가에 대해서
-> BFS를 사용하자

*/

bool findWord(string begin, string word){
    int differnt = 0;
    int size = begin.size();
    for(int i=0; i<size; i++){
        if(begin[i] != word[i]) differnt ++;
    }
    if(differnt == 1) return true;
    return false;
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, pair<int, int>>> q; //단어, 인덱스, 깊이 저장
    vector<bool> visited(words.size()+1, false);
    pair<string, pair<int, int>> word;

    //초기 queue 넣기
    q.push(make_pair(begin, make_pair(words.size(),0)));
    while(!q.empty()){ // 더 이상 나아갈 수 없음.
        word = q.front(); q.pop();        
        int index = word.second.first;
        int depth = word.second.second;

        //방문한 노드인가?
        if(visited[index]) continue;
        visited[index] = true;
        //cout <<"word: " <<word.first << "  depth: " <<depth << "\n"; 

        
        if(word.first == target) return depth; //target 찾음

        //방문할 수 있는 노드 찾기
        int size = words.size();
        for(int j=0; j<size; j++){
            if(findWord(word.first, words[j])) q.push(make_pair(words[j], make_pair(j, depth+1)));
        }
    }
    cout << word.first << "\n"; 
    return 0; //target 못찾음
}