import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        String [] name = {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};
        int [] work = {0, 0, 0, 0, 0, 0, 0};

        HashMap<String, Integer> v = new HashMap<>();
        v.put("Re", 0);
        v.put("Pt", 1);
        v.put("Cc", 2);
        v.put("Ea", 3);
        v.put("Tb", 4);
        v.put("Cm", 5);
        v.put("Ex", 6);

        double [] cwork = new double[7];
        double cnt = 0;
        while (scn.hasNext()) {
            String n = scn.next();
            cnt++;
            if (v.containsKey(n))
                work[v.get(n)]++;
        }

        for (int i = 0; i < 7; i++) {
            cwork[i] = (double)work[i] / cnt;
            System.out.printf("%s %d %.2f\n", name[i], work[i], cwork[i]);
        }
        System.out.printf("Total %d 1.00", (int)cnt);

        scn.close();
    }
}
