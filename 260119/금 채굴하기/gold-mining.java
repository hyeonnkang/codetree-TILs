import java.util.Scanner;

public class Main {

    static int n, m;
    static int[][] grid;

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
                    cost = (long)k*k + (long)(k+1)*(k+1);
                    cnt = find(i, j, k);
                    if (cnt * m >= cost) {
                        maxCnt = Math.max(maxCnt, cnt);
                    }
                }
            }
        }
        System.out.println(maxCnt);
    }

    static int find(int row, int col, int k){
        int res = 0;

        for (int i = row - k; i <= row + k; i++) {
            for (int j = col - k; j <= col + k; j++) {
                if (i >= 0 && i < n && j >= 0 && j < n) {
                    if (Math.abs(row - i) + Math.abs(col - j) <= k) {
                        res += grid[i][j];
                    }
                }
            }
        }

        return res;
    }
}