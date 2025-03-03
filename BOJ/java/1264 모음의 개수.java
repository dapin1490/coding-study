import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int cnt = 0;
        String s;

        while (true) {
            s = scn.nextLine();
            if (s.equals("#"))
                break;

            for (int i = 0; i < s.length(); i++) {
                switch (s.charAt(i))
                {
                    case 'A': case 'a':
                    case 'E': case 'e':
                    case 'I': case 'i':
                    case 'O': case 'o':
                    case 'U': case 'u':
                        cnt++;
                        break;
                }
            }

            System.out.println(cnt);
            cnt = 0;
        }

        scn.close();
    }

}
