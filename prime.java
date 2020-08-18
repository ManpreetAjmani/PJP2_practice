package java1;

import java.util.HashMap; 
import java.util.Map; 
import java.util.Arrays;
import java.util.Scanner;

public class prime {

	public static Map<String, String> primesieve(int n) {
		boolean check[]=new boolean[n+1];
		Arrays.fill(check, true);
		for (int i=2;i*i<=n;i++) {
			if (check[i]) {
				for (int j=i*2;j<=n;j+=i) {
					check[j]=false;
				}
			}
		}
		int k = 66;
		HashMap<String, String> primes=new HashMap<>();
		primes.put("A","1");
		for (int i=2;i<=n;i++) {
			if (check[i]) {
				String x=Character.toString((char) k);
				primes.put(x,Integer.toHexString(i));
				k++;
			}
		}
		return primes;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Map<String,String> map=primesieve(150);
		Scanner txt=new Scanner(System.in); 
		System.out.println("Enter name");

		String Name=txt.nextLine();
		String ans="";
		for (int i=0; i<Name.length();i++) {
			String t=Character.toString(Name.charAt(i));
			if (map.containsKey(t)) {
				String str=map.get(t);
				ans+=str;
			}
		}
		System.out.println(ans);
	}
}
