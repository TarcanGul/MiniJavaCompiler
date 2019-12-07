// This example contains straight-line assignment and printing statements in a single method, that is the main method
class simple {
    public static void main(String [] args) {
	    int x = 1, y = 100, z;
	    String bale;
	    boolean abra = true;
	    String hello = "hello";
	    String concat = " concat";
	    z = x*y - (y - 1) + 1;
            System.out.println("This line should be printed. A bunch of expressions:");
	    System.out.println(hello);
	    hello = "Reassigned string";
	    System.out.println(hello + concat);
	    System.out.println(hello);
            System.out.print("x = ");
            System.out.println(x);
            System.out.print("y = ");
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
            System.out.print("z = ");
            System.out.println(z);
            System.out.print("x+y = ");
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
            System.out.println(x*y-(b-1));
	    int[] array = new int[5];
	    array[2] = 45;
	    array[4] = 34343; 
            System.out.println(array[2]);
            System.out.println(array[4]);
	    boolean[] array2 = new boolean[6];
	    array2[5] = true;
	    array2[4] = false;
	    System.out.println(array2[5]);
	    System.out.println(array2[4]);
	    String[] array3 = new String[4];
	    array3[1] = "Hello";
	    array3[2] = " world!";
	    System.out.println(array3[1]);
	    System.out.println(array3[2]);

	    AnotherClass obj = new AnotherClass();
	    AnotherClass obj2;
	    AnotherClass obj3;

	    obj2 = new AnotherClass();
	    obj3 = obj;	    

	    obj.property = 5;
            obj.another = "Hey from the other side!";
	    System.out.print(obj.property);
	    System.out.println(obj.another);

  	    obj.doSomething(); //Basic method call.
	    obj.add(23, 42);
    }
}

class AnotherClass
{
  int property;
  int size;
  String another;


  public int doSomething()
  {
	int ab = 345;
	System.out.println(ab);
	System.out.println("Called doSomething()");
  }

  public int add(int aa, int bb)
  {
	System.out.print("Addition result: ");
	System.out.println(aa + bb);
  }
}
