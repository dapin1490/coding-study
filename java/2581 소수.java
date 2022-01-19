import java.util.*;

public class Main {

    static boolean sosu(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i < n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int sum = 0;
        int min = 10001;
        int m = scn.nextInt();
        int n = scn.nextInt();

        for (int i = m; i <= n; i++) {
            if (sosu(i)) {
                sum += i;
                if (i < min)
                    min = i;
            }
        }

        if (sum == 0)
            System.out.println(-1);
        else
            System.out.println(sum + "\n" + min);

        scn.close();
    }
}
