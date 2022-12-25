import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt();
        int div = 2;
        Vector<Integer> v = new Vector<Integer>();

        while (n != 1)
        {
            if (n % div == 0)
            {
                v.add(div);
                n /= div;
            }
            else
                div++;
        }

        for (int i = 0; i < v.size(); i++)
            System.out.println(v.get(i));

        scn.close();
    }
}
