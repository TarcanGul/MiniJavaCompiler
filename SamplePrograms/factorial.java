

class Factorial {
    public static void main(String[] a) {
        String b = "Hello! This is Program Factorial";
	System.out.println(b);
	int number = Integer.parseInt(a[0]);			
	
	System.out.print("Factorial(");
	System.out.print(number);
	System.out.print(") is  ");
			
      	System.out.println(new Fac().ComputeFac(number));
    }
}
class Fac {
    public int ComputeFac(int num) {
        int num_aux;
        if (num < 1)
            num_aux = 1;
        else
            num_aux = num * (this.ComputeFac(num-1));
        return num_aux;
    }
}
