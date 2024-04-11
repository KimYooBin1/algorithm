import java.util.*;

class Solution {
    static class Info{
        private int value;
        private int index;
        public Info(int value, int index){
            this.value = value;
            this.index = index;
        }
    }
    public int[] solution(int[] numbers) {
        int[] answer = new int[numbers.length];
        for(int i=0;i<numbers.length;i++){
            answer[i] = -1;
        }
        Stack<Info> s = new Stack<>();
        for(int i=0;i<numbers.length;i++){
            if(!s.isEmpty() && s.peek().value < numbers[i]){
                while(true){
                    Info tmp = s.pop();
                    answer[tmp.index] = numbers[i];
                    if(s.isEmpty()) break;
                    if(numbers[i] <= s.peek().value) break;
                }
            }
            s.push(new Info(numbers[i], i));
        }
        return answer;
    }
}