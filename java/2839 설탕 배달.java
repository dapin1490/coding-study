import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		int sugar = 0;
		int n = scn.nextInt();

		while (true)
		{
			if (n % 5 == 0 && n >= 0)
				break;
			else if (n < 0)
			{
				sugar = -1;
				break;
			}

			n -= 3;
			sugar++;
		}

		System.out.println(sugar + (n / 5));
		
		
		scn.close();

	}

}
