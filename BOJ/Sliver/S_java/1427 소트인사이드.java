import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String s = scn.next();
        int len = s.length();
        char [] a = new char[len];

        for (int i = 0; i < s.length(); i++) {
            a[i] = s.charAt(i);
        }

        Arrays.sort(a);

        for (int i = len - 1; i >= 0; i--) {
            System.out.print(a[i]);
        }

        scn.close();
    }

}
