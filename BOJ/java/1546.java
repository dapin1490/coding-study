import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);

		int n = scn.nextInt();
		double max = 0;
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			double a = scn.nextDouble();
			sum += a;
			if (a > max)
				max = a;
		}

		System.out.println((sum / max * 100) / n);

		scn.close();
	}
}
