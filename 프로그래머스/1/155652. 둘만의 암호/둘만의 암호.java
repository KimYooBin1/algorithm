import java.util.*;

class Solution {
    public String solution(String s, String skip, int index) {
        HashMap<Integer, Integer> check = new HashMap<>();
        for(int i = 0;i<skip.length();i++){
            check.put(skip.charAt(i)-'a',1);
        }
        String answer = "";
        for(int i=0;i<s.length();i++){
            int num = s.charAt(i)-'a';
            for(int j=0;j<index;j++){
                num += 1;
                if(26<=num) num=0;
                while(check.containsKey(num)){
                    num++;
                    if(26<=num) num=0;
                }
                System.out.println((char)('a' + num));
            }
            System.out.println("-----");
            answer += (char)('a'+num);
        }
        return answer;
    }
}