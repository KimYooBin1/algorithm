#include <string>
#include <vector>
#include <climits>
#include <unordered_set>
#include <iostream>
using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int>> v(9);
    v[0].insert(0);
    for(int i=1;i<9;i++){
        int pre = *v[i-1].begin();
        v[i].insert(pre*10+N);
        if(pre*10+N == number) return i;
    }
    for(int i=2;i<9;i++){
        for(int j=1;j<i;j++){
            for(auto s1:v[j]){
                for(auto s2:v[i-j]){
                    int result1 = s1 + s2;
                    int result2 = s1 - s2;
                    int result3 = s1 * s2;
                    int result4 = 0;
                    if(s2!=0){
                        result4 = s1 / s2;    
                    }
                    v[i].insert(result1);
                    v[i].insert(result2);
                    v[i].insert(result3);
                    v[i].insert(result4);
                    
                    if(result1 == number || result2 == number || result3 == number || result4 == number) return i;
                }
            }
        }
    }
    return -1;
}