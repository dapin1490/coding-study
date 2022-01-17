import java.util.*;

public class Main {
	
	static String findRoom(int h, int w, int n) {
		int line = 1;
		int address = h;
		
		while (n > address)
		{
			address += h;
			line++;
		}
		
		if (line > w)
			return "There is no room.";
		
		int xx = line;
		int yy = h - (address - n);
		String room;
		
		if (xx < 10)
			room = Integer.toString(yy) + "0" + Integer.toString(xx);
		else
			room = Integer.toString(yy) + Integer.toString(xx);
		
		return room;
	}
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		int t = scn.nextInt();
		
		for (int i = 0; i < t; i++)
		{
			int hh = scn.nextInt();
			int ww = scn.nextInt();
			int nn = scn.nextInt();
			
			System.out.println(findRoom(hh, ww, nn));
		}
		
		
		scn.close();

	}

}
