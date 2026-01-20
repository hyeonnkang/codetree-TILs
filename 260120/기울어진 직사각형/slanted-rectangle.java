import java.util.*;

public class Main {

    static int n;
    static int[][] grid;
    static int answer = 0;
    static int[] dr = {-1, -1, 1, 1};
    static int[] dc = {1, -1, -1, 1};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                bfs(i, j);
            }
        }

        System.out.println(answer);
    }

    static void bfs(int row, int col){
        int frow = row + dr[0];
        int fcol = col + dc[0];
        if(frow < 0 || frow >= n || fcol < 0 || fcol >= n) return;

        Queue<int[]> q = new ArrayDeque<>(); // (row, col, dir, sum);
        q.add(new int[]{frow, fcol, 0, grid[row][col] + grid[frow][fcol]});

        while(!q.isEmpty()){
            int[] cur = q.poll();

            if(cur[0] == row && cur[1] == col && cur[3] > grid[row][col]){
                answer = Math.max(answer, cur[3] - grid[row][col]);
                continue;
            }

            for(int i = cur[2]; i <= cur[2]+1 && i <= 3; i++){
                int nr = cur[0] + dr[i];
                int nc = cur[1] + dc[i];
                
                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                q.add(new int[]{nr, nc, i, cur[3]+grid[nr][nc]});
            }
        }
    }
}