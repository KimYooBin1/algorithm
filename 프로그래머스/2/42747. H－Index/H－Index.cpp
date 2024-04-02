#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int len = citations.size();
    int result = 0;
    for(int i = 0;i<len;i++){
        if(citations[i]>=len-i){
            result = max(result, len-i);
        }
    }
    return result;
}