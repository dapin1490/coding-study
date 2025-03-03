// 동적 계획법

import java.util.*;

public class Main {

    int a, b, c;
    int [][][] me;

    public Main() {
        a = 0;
        b = 0;
        c = 0;
        me = new int [102][102][102];
    }

    public int w(int a, int b, int c) {
        if (me[50 + a][50 + b][50 + c] != 0) {
            return me[50 + a][50 + b][50 + c];
        }

        if (a <= 0 || b <= 0 || c <= 0) {
            int ans = 1;
            me[50 + a][50 + b][50 + c] = ans;
            return ans;
        }
	else if (a > 20 || b > 20 || c > 20) {
            int ans = w(20, 20, 20);
            me[50 + a][50 + b][50 + c] = ans;
            return ans;
        }
	else if (a < b && b < c) {
            int ans = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
            me[50 + a][50 + b][50 + c] = ans;
            return ans;
        }
	else {
            int ans = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
            me[50 + a][50 + b][50 + c] = ans;
            return ans;
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int a, b, c;

        Main m = new Main();

        while (true) {
            a = scn.nextInt();
            b = scn.nextInt();
            c = scn.nextInt();
            if (a == -1 && b == -1 && c == -1)
                break;
            System.out.println("w(" + a + ", " + b + ", " + c + ") = " + m.w(a, b, c));
        }

        scn.close();
    }

}
