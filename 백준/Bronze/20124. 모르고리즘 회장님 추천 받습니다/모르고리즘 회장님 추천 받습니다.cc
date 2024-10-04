#include <iostream>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
int main()
{
    FIO;
    int n;
    std::cin>>n;
    std::string result;
    int max = -1;
    while(n--){
        std::string str;
        int num;
        std::cin>>str>>num;
        if(max == -1 || max < num){
            result = str;
            max = num;
            continue;
        }
        else if(max == num && str < result){
            result = str;
        }
    }
    std::cout<<result<<"\n";

    return 0;
}