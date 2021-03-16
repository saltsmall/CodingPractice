/*  
https://www.acmicpc.net/problem/1451
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> square(101, vector<int>(101));

 long long getSquareValue(int n1, int n2, int m1, int m2){
    long long result = 0;
    for(int i=n1; i<=n2; i++){
        for(int j=m1; j<=m2; j++){
            result += square[i][j];
        }
    }
    return result;
}

int main(){
    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin >> c;
            square[i][j] = c - '0';            
        }
    }

    long long ans = 0;
    //case1
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            long long s1 = getSquareValue(0,i,0,M-1);
            long long s2 = getSquareValue(i+1,j,0,M-1);
            long long s3 = getSquareValue(j+1,N-1,0,M-1);
            ans = max(ans, s1 * s2 * s3);
        } 
    }

    //case2
    for(int i=0; i<M-2; i++){
        for(int j=i+1; j<M-1; j++){
            long long s1 = getSquareValue(0,N-1,0,i);
            long long s2 = getSquareValue(0,N-1,i+1,j);
            long long s3 = getSquareValue(0,N-1,j+1,M-1);
            ans = max(ans, s1 * s2 * s3);
        } 
    }

    //case3
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            long long s1 = getSquareValue(0,i,0,j);
            long long s2 = getSquareValue(i+1,N-1,0,j);
            long long s3 = getSquareValue(0,N-1,j+1,M-1);
            ans = max(ans, s1 * s2 * s3);
        }
    }

    //case4
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            long long s1 = getSquareValue(0,N-1,0,j);
            long long s2 = getSquareValue(0,i,j+1,M-1);
            long long s3 = getSquareValue(i+1,N-1,j+1,M-1);
            ans = max(ans, s1 * s2 * s3);
        }
    }


    //case5
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            long long s1 = getSquareValue(0,i,0,M-1);
            long long s2 = getSquareValue(i+1,N-1,0,j);
            long long s3 = getSquareValue(i+1,N-1,j+1,M-1);
            ans = max(ans, s1 * s2 * s3);
        }
    }
    
    //case6
    for(int i=0; i<N-1; i++){
        for(int j=0; j<M-1; j++){
            long long s1 = getSquareValue(0,i,0,j);
            long long s2 = getSquareValue(0,i,j+1,M-1);
            long long s3 = getSquareValue(i+1,N-1,0,M-1);
            ans = max(ans, s1 * s2 * s3); 
        }
    }
    cout << ans;

    return 0;
}