import java.util.Scanner;

public class Main {
    static int n, m;
    static int[][] grid;

    static int[][] dx = {
        {0, 0, 0},
        {0, 1, 2},
        {0, 0, 1},
        {0, 0, 1},
        {0, 1, 1},
        {0, 1, 1}
    };
    static int[][] dy = {
        {0, 1, 2},
        {0, 0, 0},
        {0, 1, 0},
        {0, 1, 1},
        {0, 0, 1},
        {0, 0, -1}
    };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        grid = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        // Please write your code here.

        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                answer = Math.max(answer, getMaxSum(i, j));
            }
        }
        System.out.println(answer);
    }

    static int getMaxSum(int row, int col){
        int res = 0;
        for(int i = 0; i < dx.length; i++){
            int sum = 0;
            for(int j = 0; j < 3; j++){
                if(row+dx[i][j] < 0 || row+dx[i][j] >= n || col+dy[i][j] < 0 || col+dy[i][j] >= m){
                    sum = 0;
                    break;
                }
                sum += grid[row+dx[i][j]][col+dy[i][j]];
            }
            res = Math.max(res, sum);
        }
        return res;
    }
}
