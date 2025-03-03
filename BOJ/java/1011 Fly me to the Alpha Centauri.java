import java.util.*;

public class Main {

    static int fly(int start, int end) {
        int len = end - start;
        int count = 0;
        int distance = 1;

        while (true)
        {
            if (len == 0)
                break;

            if (len >= distance * 2)
            {
                len -= distance * 2;
                count += 2;
                distance++;
            }
            else if (len >= (distance * 2 - 1) && distance != 1)
            {
                len -= (distance * 2 - 1);
                count += 2;
            }
            else if (len == distance)
            {
                len -= distance;
                count++;
            }
            else
                distance--;
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int t = scn.nextInt();
        for (int i = 0; i < t; i++)
        {
            int a = scn.nextInt();
            int b = scn.nextInt();
            System.out.println(fly(a, b));
        }

        scn.close();
    }
}
