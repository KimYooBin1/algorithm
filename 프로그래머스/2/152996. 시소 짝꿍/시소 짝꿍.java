import java.util.*;

class Solution {
    public long solution(int[] weights) {
        long answer = 0;
        Arrays.sort(weights);
        HashMap<Double, Integer> cnt = new HashMap<>();
        for(int i=0;i<weights.length;i++){
            double w = weights[i];
            double a = w * 1.0;
            double b = w * 2/3;
            double c = w * 1/2;
            double d = w * 3/4;
            if(cnt.containsKey(a)) answer += cnt.get(a);
            if(cnt.containsKey(b)) answer += cnt.get(b);
            if(cnt.containsKey(c)) answer += cnt.get(c);
            if(cnt.containsKey(d)) answer += cnt.get(d);
            cnt.put(w, cnt.getOrDefault(w, 0) + 1);
            
        }
        return answer;
    }
}