import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = {};
        List<Integer> list = new ArrayList<>();
        HashMap<Character, Integer> map = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(!map.containsKey(c)){
                list.add(-1);
            }
            else{
                list.add(i-map.get(c));   
            }
            map.put(c, i);
        }
        return list.stream().mapToInt(i->i).toArray();
    }
}