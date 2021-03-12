/*
https://www.acmicpc.net/problem/2110
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int ans;
    int N,C;
    cin >> N >> C;
    
    vector<int> houses;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        houses.push_back(num);
    }
    sort(houses.begin(), houses.end());

    int min = 1;
    int max = houses.back()-houses.front();
    while(min<=max){
        int mid = (min+max)/2;
        int c = 1;
        int start = houses.front();
        for(int i=1;i<houses.size();i++){
            if(mid <= (houses[i]-start)){
                c++;
                start = houses[i];
            }
        }
        if(c<C){
            max = mid -1;
        }
        else{
            if(mid<=max){
                ans = mid;
            }
            min = mid +1;
        }
    }
    cout << ans;
}