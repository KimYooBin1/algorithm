import java.util.*;

class Solution {
    public int solution(int number, int limit, int power) {
        int answer = 0;
        for(int i=1;i<=number;i++){
            int cnt = 0;
            for(int j=1;j*j<=i;j++){
                if(j*j == i) cnt+=1;
                else if(i%j == 0) cnt+= 2;
            }
            System.out.println(cnt);
            if(limit < cnt) answer += power;
            else answer += cnt;
        }
        return answer;
    }
}