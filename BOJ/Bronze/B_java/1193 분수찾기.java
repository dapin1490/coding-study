import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		int n = scn.nextInt();
		int layer = 1;
		int total = 1;
		
		while (n > total)
		{
			layer++;
			total += layer;
		}
		layer++;
		
		int div = total - n + 1;
		
		if (layer % 2 == 1)
			System.out.println((layer - div) + "/" + div);
		else
			System.out.println(div + "/" + (layer - div));
		
		
		scn.close();

	}

}
