#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    int index = 0;
    string str = "";
    vector<string> result;
    for(int i=0;i<my_string.length();i++){
        if(my_string[i] == ' '){
            result.push_back(str);
            str = "";
            continue;
        }
        str += my_string[i];
    }
    result.push_back(str);
    return result;
}