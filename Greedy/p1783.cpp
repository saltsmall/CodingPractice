/*  
https://www.acmicpc.net/problem/1783
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace  std;

/* 
1. 2칸 위로, 1칸 오른쪽
2. 1칸 위로, 2칸 오른쪽
3. 1칸 아래로, 2칸 오른쪽
4. 2칸 아래로, 1칸 오른쪽
 
-N=1일 경우, 진행할 수 없음.
-N=2일 경우, 2번, 3번만 사용가능하나 이동횟수는 4를 넘을 수 없음.
-N=3이상 일경우,
    최소 가로길이가 6보다 커야지 모든 이동 방식을 사용햘 수 있음.   
    최대 길이는 2번,3번은 한번 씩만 사용하고 1번,4번을 사용함.
    이때, 2번, 3번으로만 이루어졌을 때 다섯칸 중 세칸만 방문가능함. 따라서
    M-2를 해야함.  

*/

int main(){
    int N, M;
    cin >> N >> M;

    if(N==1) cout << "1\n";
    else if(N==2) cout << min(4, (M+1)/2) << "\n";
    else if(N>=3) {
        if(M<=6) cout << min(4, M) << "\n";
        else cout << M-2 << "\n";
    }
     return 0;
}