#include <string>
#include <vector>

/*  
[동적계획법]

 전체 문제를 작은 문제로 단순화하고 점화식으로 만들고
재귀적인 구조를 활용하여 전체 문제를 해결하는 방식이다.

1. 전체 문제를 작은 문제로 단순화하여 부분 문제를 정의한다.
2. 재귀적인 구조를 화룡할 수 있는 점화식을 만든다.
3. 전체 문제를 해결한다.

map[i][j]까지의 최단 경로 수 = map[i][j] = map[i][j-1] + map[j-1][i]

*/



using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> part(n+1, vector<int>(m+1,0));
    vector<vector<int>> map(n+1, vector<int>(m+1,0));
    for(vector<int> v : puddles){
        map[v[1]][v[0]] = 1; //물 웅덩이
    }

    part[1][0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(map[i][j] == 1){ //물웅덩이
                part[i][j] = 0;
            }
            else {
                part[i][j] = (part[i][j-1] + part[i-1][j]) % 1000000007;
            }
        }
    }
    answer = part[n][m];

    return answer;
}