import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        // dp[i][j] : i번째 고양이가 j번 리본을 선택했을 때, 합산 점수의 최댓값
        int[][] dp = new int[N][K];

        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < K; j++) {
            dp[0][j] = Integer.parseInt(st.nextToken());
        }

        for (int i = 1; i < N; i++) {
            int prevMax1 = -1;
            int prevMax2 = -1;
            int prevMax1Idx = -1;

            for (int j = 0; j < K; j++) {
                if (dp[i - 1][j] > prevMax1) {
                    prevMax2 = prevMax1;
                    prevMax1 = dp[i - 1][j];
                    prevMax1Idx = j;
                } else if (dp[i - 1][j] > prevMax2) {
                    prevMax2 = dp[i - 1][j];
                }
            }

            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < K; j++) {
                int now = Integer.parseInt(st.nextToken());

                if (j == prevMax1Idx) {
                    // 현재 리본(j)이 이전 고양이가 최댓값을 냈던 리본과 같다면, 두 번째 최선책을 선택
                    dp[i][j] = now + prevMax2;
                } else {
                    // 리본이 겹치지 않는다면, 이전 고양이의 결과 중 무조건 제일 큰 값을 선택
                    dp[i][j] = now + prevMax1;
                }
            }
        }

        long result = 0;
        for (int j = 0; j < K; j++) {
            result = Math.max(result, dp[N - 1][j]);
        }

        System.out.println(result);
    }
}