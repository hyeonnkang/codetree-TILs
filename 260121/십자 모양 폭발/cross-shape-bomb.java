import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        int r = sc.nextInt();
        int c = sc.nextInt();
        // Please write your code here.
        boolean[][] visited = new boolean[n][n];
        int[] dr = {1, 0, -1, 0};
        int[] dc = {0, 1, 0, -1};
        visited[--r][--c] = true;
        for(int i = 0; i < 4; i++){
            // (r, c) 좌표의 숫자만큼 폭발
            for(int k = 1; k < grid[r][c]; k++){
                int nr = r + dr[i] * k;
                int nc = c + dc[i] * k;

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
                visited[nr][nc] = true;
            }
        }

        int[][] answer = new int[n][n];
        for(int j = 0; j < n; j++){
            int ti = n-1;
            for(int i = n-1; i >= 0; i--){
                if(visited[i][j]) continue;

                answer[ti--][j] = grid[i][j];
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(answer[i][j] + " ");
            }System.out.println();
        }
    }
}