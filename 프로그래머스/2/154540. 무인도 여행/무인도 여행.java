import java.util.*;
import java.awt.*;
class Solution {
    public int[] solution(String[] maps) {
        int n = maps.length;
        int m = maps[0].length();
        java.util.List<Integer> result = new ArrayList<>();
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        int dist[][] = new int [n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j] = -1;
            }
        }
        Queue<Point> q = new LinkedList<>();
        int g_num = 0;
        for(int i=0;i<maps.length;i++){
            for(int j=0;j<maps[i].length();j++){
                if(maps[i].charAt(j) == 'X') continue;
                if(dist[i][j] != -1) continue;
                q.add(new Point(i, j));
                dist[i][j] = g_num++;
                result.add(maps[i].charAt(j)-'0');
                while(!q.isEmpty()){
                    Point point = q.poll();
                    int x = point.x;
                    int y = point.y;
                    for(int z=0;z<4;z++){
                        int nx = x + dx[z];
                        int ny = y + dy[z];
                        if(nx<0 || n<=nx || ny<0 || m<=ny) continue;
                        if(maps[nx].charAt(ny) == 'X') continue;
                        if(dist[nx][ny] != -1) continue;
                        dist[nx][ny] = dist[x][y];
                        result.set(dist[nx][ny], 
                                   result.get(dist[nx][ny]) + maps[nx].charAt(ny) - '0');
                        q.add(new Point(nx, ny));
                    }
                }
            }
        }
        int answer[] = result.stream().sorted().mapToInt(i -> i).toArray();
        if(answer.length == 0){
            int tmp[] = {-1};
            return tmp;
        }
        return answer;
    }
}