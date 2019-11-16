// This example contains straight-line assignment and printing statements in a single method, that is the main method
class simple {
    public static void main(String [] args) {
	    int x = 1, y = 100, z;
	    boolean abra = true;
	    //z = x*y - (y - 1) + 1;
            //System.out.println("This line should be printed. A bunch of expressions:");
            //System.out.print("x = ");
            System.out.println(x);
            //System.out.print("y = ");
            System.out.println(y * 2 + 2);
	    z = (4 - x) * 16;
	    System.out.println(x);
	    System.out.println(z);
	    System.out.println(abra);
	    System.out.print(4 * 4 * 4);
	    System.out.print(true && false);
	    if(abra || false)
	    {
		System.out.println(1000);
		System.out.println(abra);
		int rr = 5;
		System.out.println(rr);
	    }
	    else
	    {
		System.out.println(-959);
	    }
            int i = 5;
	    while(i > 0)
	    {
		System.out.println(420);
		i = i-1;
	    }       
            //System.out.print("z = ");
            //System.out.println(z);
            /*System.out.print("x+y = ");
            System.out.println(x+y);
            System.out.print("x*y-(y-1) = ");
            System.out.print(x*y-(y-1));
	    int a = 10, b = 100;
	    x = x + a;
	    z = x*y - (b - 10) + 1;
            System.out.print("a = ");
            System.out.println(a);
            System.out.print("b = ");
            System.out.println(b);
            System.out.print("z = ");
            System.out.println(z);
            System.out.print("x+y = ");
            System.out.println(x+y);
            System.out.print("x*y-(b-1) = ");
            System.out.println(x*y-(b-1));*/
    }
}
