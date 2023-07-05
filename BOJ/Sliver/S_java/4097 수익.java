// https://www.acmicpc.net/problem/4097

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;

/*
 * 차이가 가장 큰 구간 구하기
 * 2차원 배열에 종류별 누적합 기록 -> 다 저장하지는 말고 누적합만 저장한 다음 차례로 뺄셈
 * 최댓값 찾기
 * reference: https://velog.io/@pss407/%EB%B0%B1%EC%A4%804097-%EC%88%98%EC%9D%B5
 */

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); // 입력 버퍼 생성
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out)); // 출력 버퍼 생성
        int n = -1, temp, max_revenue;
        ArrayList<Integer> nums = new ArrayList<>();

        while (true) {
            n = Integer.parseInt(reader.readLine());

            if (n == 0)
                break;

            nums.add(Integer.parseInt(reader.readLine()));
            max_revenue = nums.get(0);
            for (int i = 1; i < n; i++) {
                temp = Integer.parseInt(reader.readLine());
                nums.add(Math.max(nums.get(i - 1) + temp, temp));
                if (nums.get(i) > max_revenue)
                    max_revenue = nums.get(i);
            }

            writer.write(max_revenue + "\n");
            max_revenue = Integer.MIN_VALUE;
            nums.clear();
        };

        reader.close();
        writer.flush();
        writer.close();
    }
}
