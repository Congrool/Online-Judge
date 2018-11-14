import java.util.*;
import java.math.*;
public class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in).useDelimiter("\\s*/\\s*|\\s*\n\\s*|\\s* \\s*");
		while(cin.hasNext()){
			int a = cin.nextInt();
			int b = cin.nextInt();
			BigDecimal num1 = new BigDecimal(a);
			BigDecimal num2 = new BigDecimal(b);
			int scale = cin.nextInt();
			try{
				System.out.println(num1.divide(num2));
			}
			catch(ArithmeticException e){
				System.out.println(num1.divide(num2,scale,BigDecimal.ROUND_DOWN));
			}
		}		
	}
};
