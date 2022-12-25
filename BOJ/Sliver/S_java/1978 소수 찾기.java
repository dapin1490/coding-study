import java.util.*;

public class Main {

    static boolean sosu(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int count = 0;
        int t = scn.nextInt();

        for (int i = 0; i < t; i++)
        {
            int n = scn.nextInt();
            if (sosu(n))
                count++;
        }

        System.out.println(count);

        scn.close();
    }
}
