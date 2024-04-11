import java.util.*;

class Solution {
    public String solution(int[] food) {
        String answer = "";
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=1;i<food.length;i++){
            map.put(i, food[i]);  
        }
        for(int i=1;i<food.length;i++){
            int cnt = map.get(i)/2;
            while(cnt != 0){
                cnt--;
                answer+=(char)(i+'0');
            }
        }
        answer += '0';
        for(int i=food.length-1;1<=i;i--){
            int cnt = map.get(i)/2;
            while(cnt != 0){
                cnt--;
                answer+=(char)(i+'0');
            }
        }
        return answer;
    }
}