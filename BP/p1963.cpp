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
[�����佺�׳׽��� ü]
�Ҽ��� ����� 1�� ����, 1�� ������ ���� ����� ���� �ʴ´�.

�����佺�׳׽��� ü�� �̷��� �Ҽ��� ������ �̿��� �˰�������
������ �� n������ �Ҽ��� �����ڰ��� ��
"2���� n�� �����ٱ��� ���� ��� ������� �Ҽ����� ���ܽ�Ű�� ���"

*/
void eratos(){
    for(int i=2; i < sqrt(MAX); i++){
        for(int j=i*i; j< MAX; j+=i){
            prime[j] = false;
            //������� ã�Ƽ� �����ֱ�
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

            //���� end_num�� ���� ���
            if(current == end_num){
                return cnt;
            }

            if(visited[current]) continue;
            visited[current] = true;

            for(int i=0; i<4; i++){
                string str_num = to_string(current);
                for(int j=0; j<10; j++){
                    str_num[i] = j + '0'; // ���ں�ȯ
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