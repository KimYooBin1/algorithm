#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
int main(){
    FIO;
    std::string str;
    std::cin >> str;
    std::vector<std::string> v;
    for (int i = 0; i < str.length(); i++) {
        v.push_back(str.substr(i));
    }
    sort(v.begin(), v.end());
    for(auto s :  v){
        std::cout << s << "\n";
    }
    return 0;
}
