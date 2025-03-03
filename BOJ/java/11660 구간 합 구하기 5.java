// https://www.acmicpc.net/problem/11660

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

/*
 * https://www.acmicpc.net/problem/11660
 * 표에서 주어진 사각형 영역의 합 구하기
 * 어떻게 시간을 줄일 수 있을까?
 */

public class Main {
    static int[][] mat;

    static int matSum(int x1, int y1, int x2, int y2) {
        int ans = 0;

        if (y1 == 0) {
            for (int x = x1; x <= x2; x++)
                ans += mat[x][y2];
        } else {
            for (int x = x1; x <= x2; x++)
                ans += (mat[x][y2] - mat[x][y1 - 1]);
        }

        return ans;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); // 입력 버퍼 생성
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out)); // 출력 버퍼 생성
        //int[][] mat;
        int n, m;
        String[] token = reader.readLine().split(" ");

        n = Integer.parseInt(token[0]);
        m = Integer.parseInt(token[1]);

        mat = new int[n][n];

        for (int i = 0; i < n; i++) {
            token = reader.readLine().split(" ");
            mat[i][0] = Integer.parseInt(token[0]);
            for (int j = 1; j < n; j++) {
                mat[i][j] = mat[i][j - 1] + Integer.parseInt(token[j]);
            }
        }

        for (int i = 0; i < m; i++) {
            token = reader.readLine().split(" ");
            writer.write(matSum(Integer.parseInt(token[0]) - 1,
                    Integer.parseInt(token[1]) - 1,
                    Integer.parseInt(token[2]) - 1,
                    Integer.parseInt(token[3]) - 1) + "\n");
        }

        reader.close();
        writer.flush();
        writer.close();
    }
}
