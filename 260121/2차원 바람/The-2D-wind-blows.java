import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int q = sc.nextInt();
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = sc.nextInt();
        int[][] queries = new int[q][4];
        for (int i = 0; i < q; i++)
            for (int j = 0; j < 4; j++)
                queries[i][j] = sc.nextInt();

        // Please write your code here.
        int[][] next = new int[n][m];
    
        for(int i = 0; i < q; i++){
            int r1 = --queries[i][0];
            int c1 = --queries[i][1];
            int r2 = --queries[i][2];
            int c2 = --queries[i][3];

            // 경계를 시계방향으로 회전
            int temp1 = grid[r1][c2];
            for(int col = c2; col > c1; col--) grid[r1][col] = grid[r1][col-1];
            int temp2 = grid[r2][c2];
            for(int row = r2; row > r1; row--) grid[row][c2] = grid[row-1][c2];
            grid[r1+1][c2] = temp1;
            temp1 = grid[r2][c1];
            for(int col = c1; col < c2; col++) grid[r2][col] = grid[r2][col+1];
            grid[r2][c2-1] = temp2;
            temp2 = grid[r1][c1];
            for(int row = r1; row < r2; row++) grid[row][c1] = grid[row+1][c1];
            grid[r2-1][c1] = temp1;
            grid[r1][c1+1] = temp2;

            int[] dr = {1, 0, -1, 0};
            int[] dc = {0, 1, 0, -1};
            for(int row = 0; row < n; row++){
                for(int col = 0; col < m; col++){
                    if(row < r1 || col < c1 || row > r2 || col > c2){
                        next[row][col] = grid[row][col];
                        continue;
                    }

                    // 평균값 구하기
                    int sum = grid[row][col], size = 1;
                    for(int dir = 0; dir < 4; dir++){
                        int nr = row + dr[dir];
                        int nc = col + dc[dir];

                        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                        sum += grid[nr][nc];
                        size++;
                    }
                    next[row][col] = (int)Math.floor(sum / size);

                }
            }

            for(int row = 0; row < n; row++){
                for(int col = 0; col < m; col++){
                    grid[row][col] = next[row][col];
                }
            }

        }

        print(grid);
    }

    static void print(int[][] grid){
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid[i].length; j++){
                System.out.print(grid[i][j] + " ");
            }System.out.println();
        }
    }
}