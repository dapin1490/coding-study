import java.util.*;

public class Main {

    public static int eu(int big, int small)
    {
        if (big < small) {
            int temp = big;
            big = small;
            small = temp;
        }

        int last = 1;

        while (true)
        {
            if (big % small == 0)
                break;
            last = big % small;
            big = small;
            small = last;
        }

        return small;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int a = scn.nextInt();
        int b = scn.nextInt();
        int n = eu(a, b);

        System.out.println(n + "\n" + a * b / n);

        scn.close();
    }

}
