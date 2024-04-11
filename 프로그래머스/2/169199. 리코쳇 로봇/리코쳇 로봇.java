import java.util.*;
import java.awt.Point;

class Solution {
    private final int dx[] = {0,0,-1,1};
    private final int dy[] = {-1,1,0,0};
    private int n, m;
    public int solution(String[] board) {
        int answer = 0;
        n = board.length;
        m = board[0].length();
        int dist[][] = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j] = -1;
            }
        }
        Queue<Point> q = new LinkedList<>();
        int s_x=0, s_y=0, e_x=0, e_y=0;
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length();j++){
                if(board[i].charAt(j) == 'R'){
                    s_x = i;
                    s_y = j;
                }
                if(board[i].charAt(j) == 'G'){
                    e_x = i;
                    e_y = j;
                }
            }
        }
        Point s_p = new Point(s_x, s_y);
        dist[s_x][s_y] = 0;
        q.add(s_p);
        while(!q.isEmpty()){
            Point p = q.peek(); q.remove();
            int x = p.x;
            int y = p.y;
            for(int i=0;i<4;i++){
                boolean check = true;
                int nx = x;
                int ny = y;
                while(true){
                    nx += dx[i];
                    ny += dy[i];
                    if(nx<0 || n<=nx || ny<0 || m<=ny) break;
                    if(board[nx].charAt(ny) == 'D') break;
                }
                nx -= dx[i];
                ny -= dy[i];
                if(dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                q.add(new Point(nx,ny));
            }
        }
        Point e_p = new Point(e_x, e_y);
        return dist[e_x][e_y];
    }
}