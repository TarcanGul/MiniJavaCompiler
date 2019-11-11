// This example contains straight-line assignment and printing statements in a single method, that is the main method
class simple {
    public static void main(String [] args) {
           int[] a = new int[5];
           int i = 0;
	    while(i < 5)	    
	    {
		{
	          int z = 5;
	           System.out.println(z);
		}
		{
		  int t = 3;
		  {		
			System.out.println(t);
		  }
		}
		  System.out.print("i : ");
		  System.out.println(i);
		  a[i] = i;
		  i = i+1;
            }
	    int j = 0;
	    second var = new second();
	    var.doAddition();
	    third var2 = new third();
	    var2.anotherOne();
	    if(j > i)
            {
	      while(j < 5)
	      {
	        System.out.println(a[j]);
	        j = j+1;                     	
	      }
	      int r = 15; 	  
	    }
	    else
  	    {
	      System.out.println("Hey");
	      int[][][] b = new int[5][6][3];
	      b[3][2][1] = 5;
	      System.out.println(b[3][2][1]);
	      System.out.print("r : ");
//	      System.out.println(r);
	    }
	    boolean[][] d2 = new boolean[2][2];
	    d2[1][1] = true;
	    System.out.println(d2[1][1]);
	    String ex = "taco";
	    System.out.println(ex);
	    String[][] d3 = new String[2][1];
	    d3[1][0] = "tarcan";
	    System.out.println(d3[1][0]);
    }
}

class second {
	int num = 7;
	String money = "I have money!";
	boolean hey = true;
	public int doAddition()
	{
		System.out.println("Addition lol");
		int a = 2 + 3;
		System.out.println(a);
		System.out.print("Num : ");
		System.out.println(num);

		{
		  System.out.println(money);
		  System.out.println(hey);
		}
	}
}

class third {
	public int anotherOne()
	{
		System.out.println("Another one.");
	}
}
