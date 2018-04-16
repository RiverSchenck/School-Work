// Discrete Probability Library

public class DProb
{

  public static double Permutations(long N, long X)
  {
    double perm = 1.0;
   
   for(long i = N - X + 1;i <= N; i++)
   {
      perm = perm * (double)(i);  
   }

    return perm;
  }
  
//end permutations


  public static double Combinations(long N, long X)
  {
    double comb = 1.0;
    
    long i;
    
    if(X==0||X==N)
    return comb; 
    
    
    if(N-X>X)
    {
       for(i=1;i<=X;i++)
       comb = comb*(double)(N-i+1)/(double)(i);  
       return comb;
          
       
    }
    
    else
    {
       for(i=1;i<=N-X;i++) 
       comb = comb*(double)(N-i+1)/((double)(i));  
       return comb;
    }
    
    
  }

//end compbinations


  public static double HyperGeometric(long Np, long Xp, long N, long X)
  {
    double probX = 0.0;
    
    probX = ((Combinations(Xp, X) * Combinations(Np - Xp, Np - X))/(Combinations(Np, N)));
    
    return probX;
  }

//end HyperGeometric


  public static double Binomial(double P, long N, long X)
  {
    double probX = 0.0;

    probX = (Combinations(N,X) * Math.pow(P,X) * Math.pow(1-P,N-X)); 

    return probX;
  }

//end Binomial


   public static double Poisson(double Xmean, long X)
  {
    double probX = 1.0;

    probX = (Math.exp(-Xmean)*Math.pow(Xmean,X)/(Permutations(X,X)));

    return probX;
  }

//end Poisson


public static void main(String args[])
{

System.out.println("\nPart 1a "+DProb.Permutations(33, 4));

System.out.println("\nPart 1b " + DProb.Combinations(33, 4));

System.out.println("\nPart 2a " + DProb.HyperGeometric(50,9,8,0));

System.out.println("\nPart 2b " + DProb.HyperGeometric(30,4,8,0));

double hold = DProb.HyperGeometric(50,9,8,0)+DProb.HyperGeometric(30,4,4,0);

System.out.println("\nPart 2c " + hold);

System.out.println("\nPart 2d " + DProb.HyperGeometric(80,13,8,0));

System.out.println("\nPart 3a " + DProb.HyperGeometric(71,5,10,2));

hold = DProb.HyperGeometric(71,5,10,1) + DProb.HyperGeometric(71,5,10,0);

System.out.println("\nPart 3b " + hold);

System.out.println("\nPart 4a " + DProb.Binomial(0.069,30,3));

hold = DProb.Binomial(0.069,30,2) + DProb.Binomial(0.069,30,1) + DProb.Binomial(0.069,30,0);

System.out.println("\nPart 4b " + hold);

System.out.println("\nPart 5a binomial " + DProb.Binomial(0.026,125,4));

System.out.println("\nPart 5a poisson " + DProb.Poisson(3.25,4));

hold = DProb.Binomial(0.026,125,3) + DProb.Binomial(0.026,125,2) + DProb.Binomial(0.026,125,1)+DProb.Binomial(0.026,125,0);

System.out.println("\nPart 5b binomial " + hold);

hold = DProb.Poisson(3.25,3) + DProb.Poisson(3.25,2) + DProb.Poisson(3.25,10)+ DProb.Poisson(3.25,0);

System.out.println("\nPart 5b poisson " + hold);

}




} // end class
