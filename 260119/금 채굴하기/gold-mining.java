import java.util.Scanner;

public class Main {

    static int n, m;
    static int[][] grid;
    static boolean[][] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        
        int maxCnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // 자기 자신만 채굴
                maxCnt = Math.max(maxCnt, grid[i][j] - 1);

                // 마름모꼴로 채굴
                int cnt = 0;
                long cost = 0;
                for(int k = 1; k <= 2*(n-1); k++){
                    cost = k*k + (k+1)*(k+1);
                    cnt = find(i, j, k);
                    if(m*cnt-cost < 0) continue;
                    maxCnt = Math.max(maxCnt, cnt);
                }
            }
        }
        System.out.println(maxCnt);
    }

    static int find(int row, int col, int k){
        int res = 0;

        visited = new boolean[n][n];
        // 위
        for(int i = row+1; i <= row+k; i++){
            int x = k - (i - row);
            for(int j = col-x; j <= col+x; j++){
                if(i < 0 || i >= n || j < 0 || j >= n) continue;
                if(visited[i][j]) continue;
                visited[i][j] = true;
                res += grid[i][j];
            }
        }

        // 아래
        for(int i = row-1; i >= row-k; i--){
            int x = k - (row - i);
            for(int j = col-x; j <= col+x; j++){
                if(i < 0 || i >= n || j < 0 || j >= n) continue;
                if(visited[i][j]) continue;
                visited[i][j] = true;
                res += grid[i][j];
            }
        }

        // 오른쪽
        for(int j = col+1; j <= col+k; j++){
            int x = k - (j - col);
            for(int i = row-x; i <= row+x; i++){
                if(i < 0 || i >= n || j < 0 || j >= n) continue;
                if(visited[i][j]) continue;
                visited[i][j] = true;
                res += grid[i][j];
            }
        }

        // 왼쪽
        for(int j = col-1; j >= col-k; j--){
            int x = k - (col - j);
            for(int i = row-x; i <= row+x; i++){
                if(i < 0 || i >= n || j < 0 || j >= n) continue;
                if(visited[i][j]) continue;
                visited[i][j] = true;
                res += grid[i][j];
            }
        }

        // 본인 추가
        if(!visited[row][col]) res += grid[row][col];

        return res;
    }
}