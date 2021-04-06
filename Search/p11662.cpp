/*  
https://www.acmicpc.net/problem/11662
*/

#include<iostream>
#include<cmath>
using namespace std;

int a[2], b[2], c[2], d[2];
double p, q;

double getDistance(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

pair<double, double> getLocation_Minho(double interval){
    return {a[0] + (b[0] - a[0])*(interval/100), a[1] + (b[1] - a[1])*(interval/100)};
}

pair<double, double> getLocation_Kangho(double interval){
    return {c[0] + (d[0] - c[0])*(interval/100), c[1] + (d[1] - c[1])*(interval/100)};
}

int main(){
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1] >> d[0] >> d[1];
    double low = 0;
    double high = 100;
    double ans = getDistance(a[0],a[1],c[0],c[1]);

    while(high-low >= 1e-6){
        //삼분 탐색
        p = (2*low + high)/3;
        q = (low + 2*high)/3;
        pair<double, double> m_p = getLocation_Minho(p);
		pair<double, double> m_q = getLocation_Minho(q);
		pair<double, double> k_p = getLocation_Kangho(p);
		pair<double, double> k_q = getLocation_Kangho(q);

        double p_len = getDistance(m_p.first, m_p.second, k_p.first, k_p.second);
        double q_len = getDistance(m_q.first, m_q.second, k_q.first, k_q.second);

        ans = min(ans, min(p_len, q_len));
        if(p_len >= q_len) low = p;
        else high = q;

    }

    cout.setf(ios::fixed);
    cout.precision(10);
    cout << ans;
}

