import java.util.*;

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        HashMap<String, Integer> t = new HashMap<>();
        t.put("code", 0);
        t.put("date", 1);
        t.put("maximum", 2);
        t.put("remain", 3);
        int[][] answer = Arrays.stream(data).filter(x -> x[t.get(ext)] < val_ext).toArray(int[][]::new);
        Arrays.sort(answer, (o1, o2) -> Integer.compare(o1[t.get(sort_by)],o2[t.get(sort_by)]));
        return answer;
    }
}