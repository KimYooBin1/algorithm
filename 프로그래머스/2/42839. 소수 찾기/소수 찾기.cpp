#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX_SIZE 10000001
using namespace std;
bool check[MAX_SIZE];

int calc(string numbers){
    int num = 0;
    for(int i=0;i<numbers.size();i++){
        num *= 10;
        num += numbers[i]-'0';
    }
    return num;
}

int solution(string numbers) {
    int answer = 0;
    check[0] = true;
    check[1] = true;
    for(int i=2;i<MAX_SIZE;i++){
        if(check[i]) continue;
        for(int j=i*2;j<MAX_SIZE;j+=i) check[j] = true;
    }
    int len = numbers.size();
    for(int i=0;i<(1<<len);i++){
        string num = "";
        int z_cnt = 0;
        for(int j=0;j<len;j++){
            if(!(i&(1<<j))) continue;
            num += numbers[j];
        }
        if(num == "") continue;
        sort(num.begin(), num.end());
        
        do{
            int number = calc(num);
            if(check[number]) continue;
            check[number] = true;
            answer++;
        }while(next_permutation(num.begin(), num.end()));        
    }
    
    return answer;
}