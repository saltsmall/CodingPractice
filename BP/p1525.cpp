/*  
https://www.acmicpc.net/problem/1525
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<int> dir = {-1, 1, -3, 3};
set<string> visited;

int BFS(string str){
    queue<string> q;
    q.push(str);

    int result = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){
            string cur = q.front();
            q.pop();
            if(cur == "123456780") return result;

            int index = cur.find("0");
            for(int i=0; i<4; i++){
                int swap_index = index + dir[i];
                
                if(swap_index < 0 || swap_index >=9 || (index%3 == 0 && i == 0) || (index%3 == 2 && i == 1)){
                    continue;
                }
                string temp = cur;
                swap(temp[index], temp[swap_index]);
                if(visited.count(temp) == 0){
                    visited.insert(temp);
                    q.push(temp);
                }
            }
        }
        result ++;
    }
    return -1;
}


int main(){
    char c;
    string start = "";
    for(int i=0; i<9; i++){
        cin >> c;
        start += c;
    }

    cout << BFS(start);
    return 0;
}