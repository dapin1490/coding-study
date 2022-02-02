import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        while (true) {
            String s = scn.nextLine();
            if (s.equals("END")) {
                break;
            }

            for (int i = s.length() - 1; i >= 0; i--) {
                System.out.print(s.charAt(i));
            }
            System.out.println();
        }

        scn.close();
    }

}
