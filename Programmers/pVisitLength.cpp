#include <string>
#include <iostream>
#include <vector>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    vector<vector<int>> paths;
    vector<int> locations(4); // 현재위치 / 다음 위치 나눠서 표기
    //시작 (0,0)
    locations[0] = 0; 
    locations[0] = 0;

    for(int i=0; i<dirs.length(); i++){
        //명령에 따라 locations 생성
        if(dirs[i] == 'U' && locations[1] + dy[2] <= 5){
            locations[2] = locations[0];
            locations[3] = locations[1] + dy[2]; 
        }
        else if(dirs[i] == 'D' && locations[1] + dy[3] >= -5){
            locations[2] = locations[0];
            locations[3] = locations[1] + dy[3];
        }
        else if(dirs[i] == 'R' && locations[0] + dx[0] <= 5){
            locations[2] = locations[0] + dx[0];
            locations[3] = locations[1];
        }
        else if (dirs[i] == 'L' && locations[0] + dx[1] >= -5){
            locations[2] = locations[0] + dx[1];
            locations[3] = locations[1];
        }
        else{
            //범위를 넘겼을 경우, 무시
            continue;
        }
        //경로 조사 ( 현재위치 다음위치 )
        bool find = false;
        for (vector<int>vec : paths){
            if (vec[0] == locations[0] && vec[1] == locations[1] && vec[2] == locations[2] && vec[3] == locations[3] ){
                find = true;
            }
            else if (vec[0] == locations[2] && vec[1] == locations[3] && vec[2] == locations[0] && vec[3] == locations[1] ){
                find = true;
            }
        }
        if(!find) {
            answer ++;
        }
        //경로 추가
        paths.push_back(locations);
        //현재위치 경신 
        locations[0] = locations[2];
        locations[1] = locations[3];
        
    }
    for (vector<int> vec:paths){
        for(int i: vec){
            cout << i;
        }
        cout << "\n";
    }

    return answer;
}