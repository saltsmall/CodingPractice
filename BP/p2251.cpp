/*
https://www.acmicpc.net/problem/2251
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 201

int A, B, C;
//물병 3개 방문 확인용
vector<vector<vector<bool>>> visited(MAX, vector<vector<bool>>(MAX, vector<bool>(MAX, false)));
priority_queue<int, vector<int>, greater<int> > result;

int main(){
    cin >> A >> B >> C;

    queue<pair<int,pair<int, int>>> q;
    q.push(make_pair( 0, make_pair(0, C)));
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        if(visited[a][b][c]) continue;
        visited[a][b][c] = true;

        //a값이 0일 때
        if(a == 0){
            result.push(c);
        }

        //a -> b
        if(a + b <= B)
            q.push(make_pair(0, make_pair(a+b, c)));
        else
            q.push(make_pair(a+b - B, make_pair(B, c)));


        //a -> c        
        if(a + c <= C)
            q.push(make_pair(0, make_pair(b, a+c)));
        else
            q.push(make_pair(a+c - C, make_pair(b, C)));
        
        //b -> a
        if(b + a <= A)
            q.push(make_pair(a+b, make_pair(0, c)));
        else
            q.push(make_pair(A, make_pair(a+b - A, c)));

        //b -> c
        if(b + c <= C)
            q.push(make_pair(a, make_pair(0, b+c)));
        else
            q.push(make_pair(a, make_pair(b+c - C , C)));
        
        //c -> a
        if(c + a <= A)
            q.push(make_pair(a+c , make_pair(b, 0)));
        else
            q.push(make_pair(A, make_pair(b, a+c - A)));

        //c -> b
        if(c + b <= B)
            q.push(make_pair(a, make_pair(b+c, 0)));
        else
            q.push(make_pair(a, make_pair(B, b+c - B)));
    }

    int size = result.size();
    for(int i=0; i<size; i++){
        cout << result.top() << " ";
        result.pop();
    }
    cout << "\n";
    return 0;
}