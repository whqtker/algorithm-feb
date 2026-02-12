import java.util.*;
import java.io.*;

public class Main {
    // 그래프 구성 {점수, 다음 idx} (파란선은 여기서 취급 X)
    static int[][] graph = new int[][] {
            { 0, 1 }, { 2, 2 }, { 4, 3 }, { 6, 4 }, { 8, 5 },
            { 10, 6 },
            { 12, 7 }, { 14, 8 }, { 16, 9 }, { 18, 10 },
            { 20, 11 },
            { 22, 12 }, { 24, 13 }, { 26, 14 }, { 28, 15 },
            { 30, 16 },
            { 32, 17 }, { 34, 18 }, { 36, 19 }, { 38, 20 },
            { 40, 21 },
            { 0, -1 }, //
            { 13, 23 }, { 16, 24 }, { 19, 25 },
            { 25, 26 },
            { 30, 27 }, { 35, 20 },
            { 22, 29 }, // idx: 29
            { 24, 25 },
            { 28, 31 }, // idx: 31
            { 27, 32 },
            { 26, 25 }
    };

    static int[] dice = new int[10];
    static int[] horses = new int[4];
    static int maxScore = 0;

    static void dfs(int turn, int score) {
        if (turn == 10) {
            maxScore = Math.max(maxScore, score);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int currentPos = horses[i];

            if (currentPos == 21)
                continue;

            int moveVal = dice[turn];
            int nextPos = currentPos;

            if (currentPos == 5) {
                nextPos = 22;
                moveVal--;
            } else if (currentPos == 10) {
                nextPos = 28;
                moveVal--;
            } else if (currentPos == 15) {
                nextPos = 30;
                moveVal--;
            }

            while (moveVal > 0) {
                nextPos = graph[nextPos][1];
                if (nextPos == 21)
                    break;
                moveVal--;
            }

            if (nextPos != 21 && isPossible(nextPos, i)) {
                continue;
            }

            horses[i] = nextPos;
            int addScore = (nextPos == 21) ? 0 : graph[nextPos][0];
            dfs(turn + 1, score + addScore);
            horses[i] = currentPos;
        }
    }

    static boolean isPossible(int targetIdx, int myIdx) {
        for (int i = 0; i < 4; i++) {
            if (i == myIdx)
                continue;
            if (horses[i] == targetIdx)
                return true;
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        dice = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();

        dfs(0, 0);
        System.out.println(maxScore);

        br.close();
    }
}