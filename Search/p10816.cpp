/*  
https://www.acmicpc.net/problem/10816
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

        cout << upper_bound(cards.begin(), cards.end(), card) - lower_bound(cards.begin(), cards.end(), card) << " ";
    }
    cout << "\n";

    return 0;
}