 /*  
 https://www.acmicpc.net/problem/1744
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    for(int i=0; i<N; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    
    long long ans = 0;
    int i, j;
    //음수일 경우
    for(i=0; i<N-1; i+=2){
        if(nums[i] < 1 && nums[i+1] < 1){
            ans += nums[i] * nums[i+1];
        }
        else break;
    }

    //양수일 경우
    for(j=N-1; j>0; j-=2){
        if(nums[j] > 1 && nums[j-1] > 1){
            ans += nums[j] * nums[j-1];
        }
        else break;
    }

    for(; j>= i; j--){
        ans += nums[j];
    }

    cout << ans << "\n";
    return 0;
}