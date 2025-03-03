import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		int n = scn.nextInt();
		int layer = 1;
		int total = 1;
		
		while (n > total)
		{
			total += layer * 6;
			layer++;
		}
		
		System.out.println(layer);
		
		
		scn.close();

	}

}
