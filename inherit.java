// This example contains straight-line assignment and printing statements in a single method, that is the main method
class simple {
    public static void main(String [] args) {
 	Dad child = new Dad();
	child.add(2, 3);   
    }
}

class AnotherClass
{
  int property;
  int size;
  String another;

  public int add(int aa, int bb)
  {
	System.out.print("Addition result: ");
	System.out.println(aa + bb);
  }

}

class Dad extends AnotherClass
{}
