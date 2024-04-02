#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string &str1, string &str2){
    return str1+str2 > str2+str1;
}

string solution(vector<int> numbers) {
    vector<string> v;
    for(int i=0;i<numbers.size();i++){
        v.push_back(to_string(numbers[i]));
    }    
    sort(v.begin(), v.end(), cmp);
    string result = "";

    for(int i=0;i<v.size();i++){
        result += v[i];
    }
    if(result[0] == '0') return "0";
    return result;
}