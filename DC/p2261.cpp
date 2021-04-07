/*  
https://www.acmicpc.net/problem/2261
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 100000
typedef pair<int, int> Point;

vector<Point> points;
int N;

bool compare_x(Point a, Point b){
    return a.first < b.first;
}

bool compare_y(Point a, Point b){
    return a.second < b.second;
}

//두점의 거리 구하기
int getDistance(Point a, Point b){
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int getLength_Y(Point a, Point b){
    return pow(a.second-b.second, 2);
}

int closest_pair(vector<Point>::iterator it, int n){
    if(n==2)
        return getDistance(it[0], it[1]);
    if(n==3)
        return min({getDistance(it[0],it[1]), getDistance(it[1],it[2]), getDistance(it[2],it[0])});

    //좌우로 나누는 기준선
    int line = (it[n/2 -1].first + it[n/2].first)/2;
    /* 
    1) 0(begin) ~ n/2까지 가장 가까운 거리 = d1
    2) 0(being)+n/2 ~ n까지 가장 가까운 거리 = d2
    d  = d1과 d2의 최소값
    */
    int d = min(closest_pair(it, n/2), closest_pair(it+n/2, n-n/2));

    //좌,우에 하나씩 점이 있을 경우
    vector<Point> mid;
    mid.reserve(n);

    for(int i=0; i<n; i++){
        int t = line - it[i].first;
        if (t*t <d) // 더 작은 경우 추가.
            mid.push_back(it[i]);
    }   

    sort(mid.begin(), mid.end(), compare_y);

    int size_mid = mid.size();
    for(int i=0; i<size_mid; i++){
        for(int j = i+1; j<size_mid && getLength_Y(mid[i], mid[j]) <d; j++){
            d = min(d, getDistance(mid[i], mid[j]));
        }
    }
    return d;
}



int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    sort(points.begin(), points.end(), compare_x);
    cout << closest_pair(points.begin(), N);
    return 0;
}