#include <string>
#include <vector>
#include <stack>

using namespace std;

bool solution(string s) {
    bool answer = true;

    stack<char> st;

    char bracket;
    int s_size = s.size();
    for(int i=0; i<s_size; i++){
        if(s[i] == '(' || s[i] == '{'|| s[i] == '['){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(!st.empty()){
                bracket = st.top();
                if(bracket == '(') st.pop();
                else return false;
            }
            else return false;
        }
        else if(s[i] == '}'){
            if(!st.empty()){
                bracket = st.top();
                if(bracket == '{') st.pop();
                else return false;
            }
            else return false;
        }
        else if(s[i] == ']'){
            if(!st.empty()){
                bracket = st.top();
                if(bracket == '[') st.pop();
                else return false;
            }
            else return false;
        }
    }
    if(!st.empty()) return false; //만약 스택이 다 안비워져 있다면 false
    return answer;
}