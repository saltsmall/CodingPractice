/* 
https://www.acmicpc.net/problem/2873
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int R, C;
    cin >> R >> C;
    vector<vector<int>> map(R, vector<int>(C));

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> map[i][j];
        }
    }
    
    string ans = ""; 

    if(R%2 == 1){/*행이 홀수일 경우*/
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(i==R-1 && j== C-1) break;
                if(j == C-1) ans += "D";
                else{
                    if(i%2==0) ans += "R";
                    else ans += "L";
                }
           }
        }
    }
    else if(C%2 ==1){ /*열이 홀수일 경우*/
        for(int j=0; j<C; j++){
            for(int i=0; i<R; i++){
                if(i==R-1 && j== C-1) break;
                if(i == R-1) ans += "R";
                else{
                    if(j%2==0) ans += "D";
                    else ans += "U";
                }
           }
        }
    }
    else{
        //가장 낮은 행복지수를 가지는 흰색칸 찾기
        int find_r=0, find_c=1;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if((i+j)%2 == 1){
                    if(map[find_r][find_c] > map[i][j]){
                        find_r = i;
                        find_c = j;
                    } 
                }
            }
        }
        //축소하기
        //시작점에서 시작, 종점에서 시작
        string start = "";
        string end = "";
        int start_r, end_r;

        if(find_r%2 == 1){
            start_r = find_r-1;
            end_r = find_r;
        }
        else{
            start_r = find_r;
            end_r = find_r+1;
        }

        int i = 0, j = 0;
        while(1){
            if(i == start_r) break;
            if(i%2 == 0){
                start.append(C-1,'R');
                start.append("D");
            }
            else{
                start.append(C-1,'L');
                start.append("D");
            }
            i++;
        }

        while(1){
            if(j == find_c){
                break;
            }
            else if(i%2 == 0 && j%2 ==0){
                start.append("D");
                i ++;   
            }
            else if(i%2 == 1 && j%2 ==0){
                start.append("R");
                j ++;
            }
            else if(i%2 == 1 && j%2 == 1){
                start.append("U");
                i --;
            }
            else{
                start.append("R");
                j ++;
            }
        }
        
        i = R-1, j = C-1;
        while(1){
            if(i == end_r) break;
            if(i%2 == 0){
                end.append(C-1,'L');
                end.append("D");
            }
            else{
                end.append(C-1,'R');
                end.append("D");
            }
            i--;
        }

        while(1){
            if(j == find_c){
                break;
            }
            else if(i%2 == 0 && j%2 ==0){
                end.append("U");
                i ++;   
            }
            else if(i%2 == 1 && j%2 ==0){
                end.append("R");
                j --;
            }
            else if(i%2 == 1 && j%2 == 1){
                end.append("D");
                i --;
            }
            else{
                end.append("R");
                j --;
            }
        }
        //cout << start << "\n";
        reverse(end.begin(), end.end());
        //cout << end << "\n";
        ans = start + end;
    }
    

    cout << ans;
    return 0;
}