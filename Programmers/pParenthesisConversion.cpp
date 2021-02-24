/*
https://school.programmers.co.kr/courses/10517/lessons/67252  
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isRightPth(vector<char> v){
    int right = 0;
    int left = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i] == '(') right ++;
        else if(v[i] == ')') left ++;

        if(left > right) return false;
    }
    return true;
}


pair<vector<char>, vector<char>> divisionVector(vector<char> w){
    int right = 0;
    int left = 0;
    vector<char> v;
    for(int i=0; i<w.size(); i++){
        if(w[i] == '(') right ++;
        else if(w[i] == ')') left ++;
        
        if(right == left){
            for(int j=w.size()-1; j>=i+1; j--){
                v.push_back(w[j]);
                if(!w.empty()) w.pop_back();
            }
            if(!v.empty()) reverse(v.begin(), v.end());
            return make_pair(w, v);
        }
    }
    return make_pair(w,v);
}


vector<char> conversionPth(vector<char> w){
    if(w.empty()) return w;

    pair<vector<char>, vector<char>> p;

    p = divisionVector(w);

    if(isRightPth(p.first)) {
        vector<char> v = conversionPth(p.second);
        vector<char> u = p.first;
        u.insert(u.end(), v.begin(), v.end());
        return u;
    }
    else{
        vector<char> result;
        vector<char> v = conversionPth(p.second);
        vector<char> u = p.first;
        //v에 대해서
        result.push_back('(');
        result.insert(result.end(), v.begin(), v.end());
        result.push_back(')');
        
        //u에 대해서
        u.erase(u.begin());
        u.pop_back();
        for(int i=0; i<u.size(); i++){
            if(u[i] == '(') u[i] = ')';
            else if(u[i] == ')') u[i] = '(';
        }
        result.insert(result.end(), u.begin(), u.end());

        return result;
    }
}

int main(){
    string str;
    vector <char> v;
    vector <char> result;
    cin >> str;

    for(int i=0; i <str.length(); i++){
        v.push_back(str[i]);    
    }

    result = conversionPth(v);

    for(char c : result){
        cout << c;
    }
}