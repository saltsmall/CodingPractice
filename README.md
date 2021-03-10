# CodingPractice

자료구조와 알고리즘을 공부하고 정리하는 개인 Repo입니다.

## 입출력 검사하기
모든 알고리즘 폴더에 적용됩니다.
inp / out 에 예제 입출력을 저장 한 뒤 다음 명령어를 수행하여 정답을 확인합니다.


    g++ {문제해답코드}.cpp && cat inp | ./a.out > output && diff -y out output

    g++ {문제해답코드}.cpp && type inp | a.exe > output && fc out output

- ```g++ {문제해답코드}.cpp``` 를 통하여 a.out 파일을 만듭니다.
- ```cat inp | ./a.out > output``` 명령어를 통하여 inp 파일을 읽어 표준 입력 형태로 a.out에게 보냅니다.
- 표준 출력을 ```> output``` 명령어를 통하여 output 파일로 저장합니다.
- ```diff``` 명령어를 통하여 ```out```과 ```output``` 의 파일을 비교합니다.

