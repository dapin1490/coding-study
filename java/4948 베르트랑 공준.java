// 에라토스테네스의 체

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int ar[] = new int[123456 * 2 + 1]; // 전부 0으로 초기화됨
        ar[0] = 1;
        ar[1] = 1;

        while (true) {
            int n1 = scn.nextInt();
            if (n1 == 0)
                break;
            int n2 = n1 * 2;

            for (int i = 2; i < n2 + 1; i++) {
                for (int j = 2 * i; j < n2 + 1; j += i) {
                    if (ar[j] == 0)
                        ar[j] = 1;
                }
            }

            int count = 0;
            for (int j = n1 + 1; j < n2 + 1; j++)
            {
                if (ar[j] == 0)
                    count++;
            }
            System.out.println(count);
        }

        scn.close();
    }
}
