#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int size = brown + yellow;
    vector<int> answer;
    for(int i=3;i<=2000;i++){
        for(int j=3;j<=2000;j++){
            if(size == i*j && (i-2) * (j-2) == yellow){
                answer.push_back(max(i, j));
                answer.push_back(min(i, j));
                return answer;
            }
        }
    }

    return answer;
}