#include <string>
#include <vector>

using namespace std;

/* 
    [변의 길이]
    X0 = 1

    X1 = X0
    X2 = X1 + X0
    X3 = X2 + X1
    X4 = X3 + X2
    ...
    Xn = Xn-1 + Xn-2

    [둘레]
    L1 = 1* X1  : 4
    L2 = L1 + X1*2 :6
    L3 = L2 + X2*2 :10
    L4 = L3 + X3*2 :16
    ...
    Ln = Ln-1 + Xn-1*2 

 */
long long solution(int N) {
    long long answer = 0;

    long long x0 = 1;
    long long x1 = 1;
    long long x2;

    answer  = x1*4;

    for(int i = 2; i<=n; i++){
        
        answer += x1*2; 
        
        x2 = x1 + x0;
        x0 = x1;
        x1 = x2;
    }  

    return answer;
}