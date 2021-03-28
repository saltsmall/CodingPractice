/*  
https://www.acmicpc.net/problem/10819
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    int ans = 0;
    sort(vec.begin(), vec.end());
    do{
        int temp = 0;
        for(int i=0; i<vec.size()-1; i++){
            temp += abs(vec[i]-vec[i+1]);
        }
        ans = max(ans, temp);
    }while(next_permutation(vec.begin(), vec.end()));

    cout << ans << "\n";

    return 0;
}