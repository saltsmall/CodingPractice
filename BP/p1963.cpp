/*  
https://www.acmicpc.net/problem/1963
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 10000

vector<bool> prime(MAX, true);
vector<bool> visited(MAX, false);
int T, start_n, end_n;


/*  
[에라토스테네스의 체]
소수는 약수가 1인 수로, 1을 제외한 수의 배수가 되지 않는다.

에라토스테네스의 체는 이러한 소수의 개념을 이용한 알고리즘으로
임의의 수 n까지의 소수를 구하자고할 때
"2부터 n의 제곱근까지 돌며 모든 배수들을 소수에서 제외시키는 방식"

*/
void eratos(){
    for(int i=2; i < sqrt(MAX); i++){
        for(int j=i*i; j< MAX; j+=i){
            prime[j] = false;
            //배수들을 찾아서 없애주기
        }
    }
}

int to_int(string str){
    int result = 0;
    for(int i=0; i<4; i++){
        result  = result *10 + (str[i]-'0');
    }

    return result;
}



int BFS(int start_num, int end_num){
    queue<int> q;
    q.push(start_num);
    int cnt = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i=0; i<size; i++){        
            int current = q.front();
            q.pop();

            //만약 end_num와 같을 경우
            if(current == end_num){
                return cnt;
            }

            if(visited[current]) continue;
            visited[current] = true;

            for(int i=0; i<4; i++){
                string str_num = to_string(current);
                for(int j=0; j<10; j++){
                    str_num[i] = j + '0'; // 숫자변환
                    int next =  to_int(str_num);

                    if(next >= 1000 && prime[next] == true){
                        q.push(next);
                    }
                }
            }
            
        } 
        cnt++;
    }
    return -1;
}


int main(){
    eratos();

    cin >> T;
    for(int i=0; i<T; i++){
        visited.assign(MAX, false);

        cin >> start_n >> end_n;
        int result = BFS(start_n, end_n);

        if(result == -1) cout << "Impossible\n";
        else cout << result << "\n";
    }

    return 0;
}