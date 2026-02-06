package algorithm;

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {
            int N = Integer.parseInt(br.readLine());
            int[] cards = new int[N + 1];
            int[][] dp = new int[N + 1][N + 1];
            int[] sum = new int[N + 1];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= N; i++) {
                cards[i] = Integer.parseInt(st.nextToken());
                sum[i] = sum[i - 1] + cards[i];
            }

            for (int len = 1; len <= N; len++) {
                for (int i = 1; i <= N - len + 1; i++) {
                    int j = i + len - 1;

                    if (len == 1) {
                        dp[i][j] = cards[i];
                    } else {
                        int totalSum = sum[j] - sum[i - 1];

                        dp[i][j] = Math.max(totalSum - dp[i + 1][j],
                                totalSum - dp[i][j - 1]);
                    }
                }
            }
            System.out.println(dp[1][N]);
        }
    }
}