/*  
https://www.acmicpc.net/problem/1517
*/

#include <iostream>
#include <vector>

using namespace std;

vector<long long> vec(500001);
vector<long long> temp(500001);
long long ans =0;

void merge(int start, int end){
    int mid = (start+end)/2;

    int i = start;
    int j = mid+1;
    int k=0;
    while(i<=mid && j<=end){
        if(vec[i] <= vec[j]){
            temp[k++] = vec[i++];
        }
        else {
            ans += (mid+1)-i;
            temp[k++] = vec[j++];
        }
    } 
    while(i<=mid){
        temp[k++] = vec[i++];
    }
    while(j<=end){
        temp[k++] = vec[j++];
    }
    for(int i=start; i<=end; i++){
        vec[i] = temp[i-start];
    }
}
void bubbleSort(int start, int end){
    if(start == end) return;

    int mid = (start+end)/2;
    bubbleSort(start, mid);
    bubbleSort(mid+1, end);
    merge(start,end);
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }
    bubbleSort(0,N-1);

    cout << ans << "\n";
}