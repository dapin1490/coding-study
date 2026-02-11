import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int a = scn.nextInt();
		int b = scn.nextInt();
		int c = scn.nextInt();

		int n = a * b * c;
		String s = Integer.toString(n);

		int ar[] = new int[10];
		for (int i = 0; i < 10; i++)
			ar[i] = 0;

		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
			case '0': ar[0]++; break;
			case '1': ar[1]++; break;
			case '2': ar[2]++; break;
			case '3': ar[3]++; break;
			case '4': ar[4]++; break;
			case '5': ar[5]++; break;
			case '6': ar[6]++; break;
			case '7': ar[7]++; break;
			case '8': ar[8]++; break;
			case '9': ar[9]++; break;
			}
		}

		for (int i = 0; i < 10; i++)
			System.out.println(ar[i]);

		scn.close();
	}
}
