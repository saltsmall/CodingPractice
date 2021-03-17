/*  
https://www.acmicpc.net/problem/11728
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);
    vector<int> C(N+M);

    //A배열 삽입
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    //B배열 삽입
    for(int i=0; i<M; i++){
        cin >> B[i];
    }

    int i=0, j=0, k=0; // A, B, C 배열 위치 저장

    //반복문이 끝날 경우, A, B 배열 중 하나는 모두 C에 삽입됨
    while(i<N && j<M){
        if(A[i]<B[j]){
            C[k++] = A[i++];
        }
        else C[k++] = B[j++];
    }
    
    //
    while(i<N) C[k++] = A[i++];
    while(j<M) C[k++] = B[j++];

    for(int num: C){
        cout << num << " ";
    }
    
    return 0;
}