#include <string>
#include <vector>

using namespace std;

int dfs(int target, vector<int> num, int index, int sum){
    if(index == num.size()){
        if(target == sum) return 1;
        return 0;
    }
    return dfs(target, num, index+1, sum + num[index])
        + dfs(target, num, index+1, sum - num[index]);
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(target, numbers, 0, 0);
    return answer;
}