#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    for(int i = 1; i<phone_book.size();i++){
        string prefix = phone_book[i-1];
        string str = phone_book[i];
        int len = prefix.length();
        bool check = true;
        for(int j=0;j<len;j++){
            if(str[j] != prefix[j]){
                check = false;
                break;
            }
        }
        if(check) return false;
    }
    return answer;
}