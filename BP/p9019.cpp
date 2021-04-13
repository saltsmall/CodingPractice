/*  
https://www.acmicpc.net/problem/9019
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 10001

vector<bool> visited(MAX, false);
int T, start_num, end_num;

int to_int(string str){
    int result = 0;
    for(int i=0; i<4; i++){
        result  = result *10 + (str[i]-'0');
    }

    return result;
}

int click_D(int num){
   return (num*2) % 10000;
}

int click_S(int num){
    if(num == 0) return 9999;
    return num-1;
}

int click_L(int num){
    return (num % 1000)*10 +num/1000;
}

int click_R(int num){
    return (num%10)*1000 + num/10;
}

string BFS(int num, int end_n){
    queue<pair<int, string> > q;
    q.push(make_pair(num,""));

    while(!q.empty()){
        int cur = q.front().first;
        string path = q.front().second;
        q.pop();

        if(cur == end_n){
            return path;
        }

        int next = click_D(cur);
        if(!visited[next]){
            visited[next] = true;
            q.push(make_pair(click_D(cur), path + 'D'));
        }

        next = click_S(cur);
        if(!visited[next]){
            visited[next] = true;
            q.push(make_pair(click_S(cur), path + 'S'));
        }

        next = click_L(cur);
        if(!visited[next]){
            visited[next] = true;
            q.push(make_pair(click_L(cur), path + 'L'));
        }

        next = click_R(cur);
        if(!visited[next]){
            visited[next] = true;
            q.push(make_pair(click_R(cur), path + 'R'));
        }
    }
    return "";
}


int main(){
    cin >> T;
    for(int i=0; i<T; i++){
        visited.assign(MAX, false);
        cin >> start_num >> end_num;
        
        cout << BFS(start_num, end_num) << "\n";
    }

    return 0;
}