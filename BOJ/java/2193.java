import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        boj2193();
    }

    public static void boj2193() throws IOException {
        // 입력 속도 최적화를 위해 BufferedReader 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        long a = 1;
        long b = 1;
        long c = a + b;

        // Circular Buffer 로직 적용
        for (int i = 4; i <= n; i++) {
            switch (i % 3) {
                case 0: c = a + b; break;
                case 1: a = b + c; break;
                case 2: b = a + c; break;
            }
        }

        switch (n % 3) {
            case 0: System.out.println(c); break;
            case 1: System.out.println(a); break;
            case 2: System.out.println(b); break;
        }
    }
}