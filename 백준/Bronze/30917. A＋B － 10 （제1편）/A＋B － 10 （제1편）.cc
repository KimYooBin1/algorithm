#include <iostream>
int main() {
    int resp;
    for(int a=1; a<=9; a++){
        // A가 a인지 물어보고 flush를 한다.
        // endl은 자동으로 flush도 해준다.
        std::cout << "? A " << a << std::endl;

        // 채점기의 답변을 입력받는다.
        std::cin >> resp;

        if(resp == 1){
            // 답변이 "예"이므로 A의 값은 a이다.
            // B의 값도 알아내야 하는데, 이 부분은 직접 채워보자.
            int b = 0;
            for (b = 1; b < 10; b++) {
                std::cout << "? B " << b << "\n";
                
                std::cin >> resp;
                if(resp) break;
            }
            std::cout << "! " << a + b;
            break;
        }
    }
}
