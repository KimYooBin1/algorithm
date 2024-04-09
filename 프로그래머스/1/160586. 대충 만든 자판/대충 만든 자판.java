import java.util.*;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        HashMap<Character, Integer> cnt = new HashMap<>();
        for(int i=0;i<keymap.length;i++){
            for(int j=0;j<keymap[i].length();j++){
                if(!cnt.containsKey(keymap[i].charAt(j))){
                    cnt.put(keymap[i].charAt(j), j+1);
                }
                else{
                    if(cnt.get(keymap[i].charAt(j)) < j+1) continue;
                    cnt.put(keymap[i].charAt(j), j+1);
                }
            }
        }
        int[] answer = new int[targets.length];
        for(int i=0;i<targets.length;i++){
            int sum = 0;
            boolean check = true;
            for(int j=0;j<targets[i].length();j++){
                if(!cnt.containsKey(targets[i].charAt(j))){
                    check = false;
                    break;
                }
                sum += cnt.get(targets[i].charAt(j));
            }
            
            answer[i] = check?sum:-1;
        }
        
        return answer;
    }
}