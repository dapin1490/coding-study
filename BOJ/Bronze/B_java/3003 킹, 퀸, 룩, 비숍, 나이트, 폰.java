import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int king = scn.nextInt();
        int queen = scn.nextInt();
        int rook = scn.nextInt();
        int bishop = scn.nextInt();
        int knight = scn.nextInt();
        int pone = scn.nextInt();

        System.out.printf("%d %d %d %d %d %d", 1 - king, 1 - queen, 2 - rook, 2 - bishop, 2 - knight, 8 - pone);

        scn.close();
    }
}
