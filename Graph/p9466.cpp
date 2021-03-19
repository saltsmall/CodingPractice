/*
https://www.acmicpc.net/problem/9466
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> vec(100000);
vector<bool> visited(100000, false);
int ans;

void DFS(int cur){
    if(vec[cur] == cur){}

}

int main(){
    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        ans = 0;
        int N;
        cin >> N;
        for(int n=1; n<=N; n++){
            cin >> vec[n];
        }

        
    }

    return 0;
}
