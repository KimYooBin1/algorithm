#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), cmp);
    int index = 0;
    int cnt = 0;
    while(index < routes.size()){
        cnt++;
        int e = routes[index++][1];
        while(index < routes.size()){
            if(e < routes[index][0]) break;
            index++;
        }
    }
    return cnt;
}