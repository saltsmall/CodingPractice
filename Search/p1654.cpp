/*
https://www.acmicpc.net/problem/1654
*/
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int ans;
    int K, N;
    cin >> K >> N;

    vector<int> lenWires;
    int sum = 0;
    for(int i=0; i<K; i++){
        int num;
        cin >> num; 
        sum += num;
        lenWires.push_back(num);
    }
    //cout << "sum :" << sum << "\n";
    int min = 1;
    int max = sum/N;
    
    while (min <= max) {
        int mid = (min + max)/2;
        int n =0;
        //cout << "min : " << min << "\n";
        //cout << "mid : " << mid << "\n";
        //cout << "max : " << max << "\n";

        for(int wire: lenWires){
            n += wire/mid;
        }
        //cout << "n : " << n << "\n";
        if(n < N){
            max = mid -1;
        }
        else{
            if(mid<=max){
                ans = mid;
                //cout << "ans : " << mid << "\n";
            }
            min = mid +1;
        }
        //cout << "\n\n";
    }

    cout << ans;
    return 0;
}