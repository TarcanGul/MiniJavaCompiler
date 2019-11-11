// This example contains straight-line assignment and printing statements in a single method, that is the main method
class simple {
    public static void main(String [] args) {
           int[] a = new int[5];
 	   {
		int sc = 2;
	   }
		System.out.println(sc);
            int i = "merhaba";
	    boolean b = true + false; 
	    while(i < 5)
	    {
		System.out.println(i);
		a[i] = i;
		i = i+1;
            }
	    int j = 0;
	    if(j > i)
            {
	      while(j < 5)
	      {
	        System.out.println(a[j]);
	        j = j+1;                     	
	      }
	    }
	    else
  	    {
	      System.out.println("Hey");
	      int[][][] b = new int[5][6][3];
	      b[3][2][1] = 5;
	      System.out.println(b[3][2][1]);
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
