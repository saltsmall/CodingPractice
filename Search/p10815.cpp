/*  
https://www.acmicpc.net/problem/10815
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M;

    cin >> N;
    vector<long long> cards(N);
    for(int i=0; i<N; i++){
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());

    cin >> M;
    for(int i=0; i<M; i++){
        int card;
        cin >> card;

        long long min = 0;
        long long max = N-1;

        //탐색
        bool isFind = false;
        while(min <= max){
            long long mid = (min+max)/2;
            
            if(cards[mid] == card){
                isFind = true;
                break;
            }

            if(cards[mid]< card){
                min = mid + 1;
            }
            else{
                max = mid - 1;
            }
        }

        //결과
        if(isFind) cout << 1 << " ";
        else cout << 0 << " ";
    }

    return 0;
}