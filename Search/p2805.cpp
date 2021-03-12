/*
https://www.acmicpc.net/problem/2805
*/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int ans;
    int N, M;
    cin >> N >> M;

    vector<int> trees;
    for(int i=0; i<N; i++){
        int num; 
        cin >> num;
        trees.push_back(num);
    }
    int min = 1;
    int max = *max_element(trees.begin(), trees.end());
    
    while(min<= max){
        int mid = (min+max)/2;

        int m=0;
        for(int tree: trees){
            if(tree>=mid) m += (tree - mid); 
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

    cout << ans;



    return 0;
}