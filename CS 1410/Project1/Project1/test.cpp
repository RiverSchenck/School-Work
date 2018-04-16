import java.util.*;
import java.lang.*;
import java.io.*;
/* Name of the class has to be "Main" only if the class is public. */
class Prime
{
	static boolean isPrime(int X)
	{
		//if X is 1 ,it's not prime
		if (X == 1)
			return false;

		//if X is 2 ,it's prime
		if (X == 2)
			return true;

		for (int i = 2; i <= X / 2; ++i)
		{
			if (X%i == 0)
				return false;
		}
		return true;
	}
	public static void main(String[] args) throws java.lang.Exception
	{
		//assign number to check weather it'sprime or not
		int number = 169;

	if (isPrime(number))
	{
		System.out.printf("Number %d is prime\n",number);
	}
	else
	{
		System.out.printf("Number %d is not prime\n",number);
	}
	}
}