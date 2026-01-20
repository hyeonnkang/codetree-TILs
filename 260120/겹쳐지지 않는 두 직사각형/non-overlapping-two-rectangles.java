import java.util.Scanner;

public class Main {
    static int n, m;
    static int[][] grid;
    static boolean[][] visited;
    static int answer = Integer.MIN_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        grid = new int[n+1][m+1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                grid[i][j] = sc.nextInt();
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                
                for(int h = 1; h <= n; h++){
                    if(i-h < 0) continue;
                    for(int w = 1; w <= n; w++){
                        if(j-w < 0) continue;

                        visited = new boolean[n+1][n+1];
                        // 첫번째 직사각형의 h, w 결정됨
                        int sum1 = 0;
                        for(int row = i-h+1; row <= i; row++){
                            for(int col = j-w+1; col <= j; col++){
                                sum1 += grid[row][col];
                                visited[row][col] = true;
                            }
                        }

                        // 두번째 직사각형 위치 결정
                        int sum2 = Integer.MIN_VALUE;
                        for(int r = 1; r <= n; r++){
                            for(int c = 1; c <= n; c++){
                                if(visited[r][c]) continue;

                                for(int h2 = 1; h2 <= n; h2++){
                                    if(r-h2 < 0) continue;
                                    for(int w2 = 1; w2 <= n; w2++){
                                        if(c-w2 < 0) continue;

                                        boolean isok = true;
                                        int temp = 0;
                                        // 두번째 직사각형의 h2, w2 결정됨
                                        for(int row = r-h2+1; row <= r; row++){
                                            for(int col = c-w2+1; col <= c; col++){
                                                if(visited[row][col]){
                                                    isok = false;
                                                    break;
                                                }
                                                temp += grid[row][col];
                                            }
                                        }
                                        if(isok) sum2 = Math.max(sum2, temp);
                                    }
                                }
                            }
                        }
 
                        if(sum2 > Integer.MIN_VALUE)
                            answer = Math.max(answer, sum1+sum2);
                    }   
                
                }
            }
        }
        System.out.println(answer);
    }
}