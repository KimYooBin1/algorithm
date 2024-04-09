import java.util.*;

class Solution {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    public int[] solution(String[] park, String[] routes) {
        HashMap<Character, Integer> dir = new HashMap<>();
        int x=0, y=0;
        for(int i=0;i<park.length;i++){
            for(int j=0;j<park[i].length();j++){
                if(park[i].charAt(j)=='S'){
                    x = i; y = j;
                }
            }
        }
        System.out.println(y);
        dir.put('N', 0);
        dir.put('S', 1);
        dir.put('W', 2);
        dir.put('E', 3);
        
        int n = park.length;
        int m = park[0].length();
        for(int i=0;i<routes.length;i++){
            int d = dir.get(routes[i].charAt(0));
            int len = routes[i].charAt(2) - '0';
            int tmp_x = x;
            int tmp_y = y;
            boolean check = true;
            for(int j=0;j<len;j++){
                tmp_x += dx[d];
                tmp_y += dy[d];
                if(tmp_x<0 || n<=tmp_x || tmp_y<0 || m<=tmp_y){
                    check = false;
                    break;
                }
                if(park[tmp_x].charAt(tmp_y) == 'X'){
                    check = false;
                    break;
                }
            }
            if(!check) continue;
            x = tmp_x;
            y = tmp_y;
        }
        int[] answer = {x, y};
        return answer;
    }
}