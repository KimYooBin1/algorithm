#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        int from = commands[i][0];
        int to = commands[i][1];
        int index = commands[i][2];
        vector<int> v;
        for(int j=from-1;j<to;j++){
            cout<<j;
            v.push_back(array[j]);
        }
        sort(v.begin(), v.end());
        answer.push_back(v[index-1]);
    }
    return answer;
}