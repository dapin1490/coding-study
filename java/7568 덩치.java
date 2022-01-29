import java.util.*;

public class Main {

    int [][] v;
    int n;

    public Main(int a) {
        n = a;
        v = new int [a][3];
    }

    public void dc() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i][0] < v[j][0] && v[i][1] < v[j][1])
                    v[i][2] += 1;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int m = scn.nextInt();
        Main d = new Main(m);

        for (int i = 0; i < d.n; i++) {
            d.v[i][0] = scn.nextInt();
            d.v[i][1] = scn.nextInt();
            d.v[i][2] = 1;
        }

        d.dc();

        for (int i = 0; i < d.n; i++) {
            System.out.print(d.v[i][2] + " ");
        }

        scn.close();
    }

}
