import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int cnt = 0;
        int i = 666;
        int n = scn.nextInt();

        while (true) {
            if (cnt == n)
                break;

            String s = Integer.toString(i);
            if (s.contains("666"))
                cnt++;
            i++;
        }

        System.out.println(i - 1);

        scn.close();
    }

}
