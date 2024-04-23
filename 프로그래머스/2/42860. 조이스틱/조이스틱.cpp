#include <string>
#include <vector>
#include <iostream>

using namespace std;

int calc(char c){
    return min(c-'A', 26-(c-'A'));
}

int solution(string name) {
    int answer = 0;
    int arr[name.length()];
    int n = name.length();
    for(int i=0;i<name.length();i++){
        answer += calc(name[i]);
    }
    int result = n - 1;
    for(int x=0;x<n;x++){
        int y = x + 1;      //왼쪽탐색으로 확인해야되는 index
        while(y<n && name[y] == 'A') y++;
        result = min(result, x + n - y + min(x, n - y));
    }

    return answer + result;
    
}