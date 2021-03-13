/*
https://www.acmicpc.net/problem/2805
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
    long long ans;
    int N, M;
    cin >> N >> M;

    vector<long long> trees;
    for(int i=0; i<N; i++){
        long long num; 
        cin >> num;
        trees.push_back(num);
    }

    long long min = 0;
    long long max = *max_element(trees.begin(), trees.end());
    
    while(min<= max){
        long long mid = (min+max)/2;

        long long m=0;
        for(long long tree: trees){
            if(tree>mid) m += (tree - mid); 
        }

        if(m<M){
            max = mid -1;
        }
        else{
            if(mid<=max){
                ans = mid;
            }
            min = mid+1;
        }
    }

    printf("%d", ans);

    return 0;
}