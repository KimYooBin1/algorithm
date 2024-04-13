import java.util.*;


class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        int index = people.length-1;
        for(int i=0;i<=index;i++){
            if(people[i] + people[index] <= limit){
                answer++;
                index--;
            }
            else{
                answer++;
                index--;
                i--;
            }
        }
        return answer;
    }
}