/* 
https://www.acmicpc.net/problem/2741
*/

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    for (int i=1; i<=n ; i++){
        cout << i <<"\n";
    }

    return 0;
}

/*  
endl은 단순 개행이 아닌 개행 후 출력 버퍼를 비워주는 역할을 추가로 하기
때문에 작업 속도가 매우 느리다
*/