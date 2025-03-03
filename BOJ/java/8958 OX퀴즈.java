import java.util.*;

public class Main {
	
	public static int getScore(String t) {
		int len = t.length();
		int total = 0;
		int count = 0;
		
		for (int i = 0; i < len; i++)
		{
			switch(t.charAt(i))
			{
			case 'O':
				count++;
				total += count;
				break;
			case 'X':
				count = 0;
				break;
			}
		}
		
		return total;
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		int n = scn.nextInt();
		
		for (int i = 0; i < n; i++)
		{
			String s = scn.next();
			System.out.println(getScore(s));
		}
		
		
		scn.close();

	}

}
