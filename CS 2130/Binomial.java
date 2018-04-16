import java.util.Random;

public class Binomial 
{

private double P; 
private long N; 

public Binomial(double P, long N) 
{
   this.N = N;
   this.P = P;
}

  public static double Permutations(long N, long X)
  {
    double perm = 1.0;
   
   for(long i = N - X + 1;i <= N; i++)
   {
      perm = perm * (double)(i);  
   }

    return perm;
  }

public double getP() 
{
   return P;
}

public void setP(double p) 
{
   P = p;
}

public long getN() 
{
   return N;
}

public void setN(long n) 
{
   N = n;
}

long randomX() 
{
   long y;
   
  y = new Random().nextInt(100);
  
  return y;
}

double mean() 
{
   return N*P;
}

double variance() 
{
   return N*P*(1-P);
}

double probX(long x) 
{
   double probX = 1.0;

    probX = (Math.exp(x)*Math.pow(x,x)/(Permutations(x,x)));

    return probX;


}

public static double fact(long n) 
{
   double ans = 0.0;
   for (int i = 1; i <= n; i++)
   ans *= i;
   return ans;
}

public static void main(String...s)
{
Binomial binomial2 = new Binomial(0.73, 6);
System.out.println("XPr(X)");
for(int i=0; i<=binomial2.getN(); i++) {
long rand2 = binomial2.randomX();
double prob = binomial2.probX(rand2);
System.out.println(i+","+rand2+","+prob);}


}
}