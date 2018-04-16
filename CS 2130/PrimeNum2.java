import java.util.Scanner;

public class PrimeNum2 {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
           int n = 0;
        
           
           System.out.println("Enter number");
           n = scanner.nextInt();
           
          int sum = 1;

	for(int k = 2; k * k <= n; ++k)
	{
		int p = 1;
		while(n % k == 0)
		{
			p = p * k + 1;
			n /= k;	
		}

		sum *= p;
	}

	if(n > 1)
		sum *= 1 + n;

	System.out.println(sum);
    }
}