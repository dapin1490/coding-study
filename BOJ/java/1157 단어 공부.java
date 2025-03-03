import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		String s = scn.next();
		s = s.toUpperCase();
		
		int [] ar = new int [26];
		for (int i = 0; i < 26; i++)
			ar[i] = 0;
		
		for (int i = 0; i < s.length(); i++)
		{
			int index = (int)(s.charAt(i) - 'A');
			ar[index]++;
		}
		
		int max = 0;
		int maxIndex = 0;
		boolean doubleMax = false;
		for (int i = 0; i < 26; i++)
		{
			if (ar[i] > max)
			{
				max = ar[i];
				maxIndex = i;
			}
		}
		
		for (int i = maxIndex + 1; i < 26; i++)
		{
			if (ar[i] == max)
				doubleMax = true;
		}
		
		if (doubleMax)
			System.out.println("?");
		else
			System.out.println((char)(maxIndex + 'A'));
		
		
		scn.close();

	}

}
