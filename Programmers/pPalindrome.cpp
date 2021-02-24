/*  
https://school.programmers.co.kr/courses/10517/lessons/67670
*/

#include <iostream>
#include <string> //string
#include <algorithm> //reverse

using namespace std;

int main(){
    int n, m, count = 0;
    string number;
    cin >> n >> m;
    
    //숫자 str로 분리하기 
    for(int i=n; i<=m; i++){
        number =to_string(i); 
        int length = number.length(); //문자열 길이
        
        string num1 = number.substr(0,length/2); //문자열 자르기
        string num2 = number.substr((length/2)+(length%2));
        reverse(num2.begin(), num2.end()); //거꾸로하기
        if(num1 == num2){
            count++;
        }
    }
    cout << count;



    return 0;
}