#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> m;
vector<string> v;
int solution(vector<vector<string>> clothes) {
    for(int i=0;i<clothes.size();i++){
        if(m.find(clothes[i][1]) == m.end()){
            v.push_back(clothes[i][1]);
        }
        m[clothes[i][1]]++;
    }
    int sum = 1;
    for(int i=0;i<v.size();i++){
        sum *= m[v[i]] + 1;
    }
    return sum - 1;
}