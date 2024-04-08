#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index = 0;
    while(index < progresses.size()){
        int cnt = 0;
        for(int i=0;i<progresses.size();i++){
            progresses[i] += speeds[i];
        }
        while(true){
            if(progresses[index] < 100 || progresses.size() <= index) break;
            index++;
            cnt++;
        }
        if(cnt != 0) answer.push_back(cnt);
    }
    return answer;
}