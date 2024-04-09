import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        HashMap<String, Integer> score = new HashMap<>();
        for(int i=0;i<name.length;i++){
            score.put(name[i], yearning[i]);
        }
        int sum = 0;
        int[] answer = new int[photo.length];
        for(int i=0;i<photo.length;i++){
            for(int j=0;j<photo[i].length;j++){
                if(!score.containsKey(photo[i][j])) continue;
                sum += score.get(photo[i][j]);    
            }
            answer[i] = sum;
            sum=0;
        }
        
        return answer;
    }
}