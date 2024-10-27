#include <iostream>
#include <random>
#define MAX_SIZE 10000
int check1[MAX_SIZE + 1];
int check2[MAX_SIZE + 1];
int main() {
    int resp;
    int a;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10000);
    while(true){
        a = dist(gen);
        if(check1[a]) continue;
        std::cout << "? A " << a << std::endl;

        // 채점기의 답변을 입력받는다.
        std::cin >> resp;
        check1[a] = 1;
        if(resp == 1) break;
    }
    int b;
    while(true){
        b = dist(gen);
        if(check2[b]) continue;
        std::cout << "? B " << b << "\n";
        std::cin >> resp;
        check2[b] = 1;
        if(resp == 1) break;
    }
    std::cout << "! " << a + b;
}
