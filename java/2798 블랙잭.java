// 참고 15650 N과 M (2)
// 백트래킹 사용

import java.util.*;

public class Main {

    int n, m; // 입력값
    boolean [] nvi; // 카드 사용 여부 저장
    Vector<Integer> v; // 더해야 할 3장의 카드 저장
    int [] card; // 전체 카드 저장
    int maxSum = 0; // 답
    int idx = 0; // 최근 사용한 카드의 인덱스 저장

    public Main(int a, int b)
    {
        n = a;
        m = b;
        v = new Vector<>(3);
        nvi = new boolean[a];
        card = new int[a];
    }

    // 2798 블랙잭
    void jack()
    {
        // 3장을 다 뽑았을 때
        if (v.size() == 3)
        {
            int temp = 0; // 지금 뽑은 3장의 합 저장
            for (int i = 0; i < 3; i++) {
                temp += v.get(i);
            }
            if (temp > maxSum && temp <= m) { // 정답 조건에 맞으면 답에 저장
                maxSum = temp;
            }
            return;
        }

        // 카드 3장 뽑기
        for (int i = 0; i < n; i++)
        {
            if (nvi[i] || i < idx) // 중복 방지, 오름차순
                continue;
            v.add(card[i]); // 더해야 할 카드에 추가
            idx = i; // 인덱스 기록
            nvi[i] = true; // 사용 여부 기록
            jack(); // 재귀 호출
            v.remove(v.get(v.size() - 1));// 사용한 카드 버림
            idx = 0; // 인덱스 초기화
            nvi[i] = false; // 사용 여부 초기화
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int a = scn.nextInt();
        int b = scn.nextInt();

        Main j = new Main(a, b);

        for (int i = 0; i < j.n; i++) {
            int temp = scn.nextInt();
            j.card[i] = temp;
        }

        j.jack();

        System.out.println(j.maxSum);

        scn.close();
    }

}
