/*
https://www.acmicpc.net/problem/1654
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int ans;
    int K, N;
    cin >> K >> N;

    vector<long long> lenWires;
    int sum = 0;
    for(int i=0; i<K; i++){
        int num;
        cin >> num; 
        sum += num;
        lenWires.push_back(num);
    }

    sort(lenWires.begin(), lenWires.end());

    long long min = 1;
    long long max = lenWires.back();
    
    while (min <= max) {
        long long mid = (min + max)/2;
        int n =0;

        for(long long wire: lenWires){
            n += wire/mid;
        }
        if(n < N){
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
    return 0;
}