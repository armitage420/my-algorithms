public class Overloading {
    // Overloading is a term used to describe when two methods have the same name but differ in type or number of arguments
    public static void add(int a, int b){
        int c = a + b;
        System.out.println("Added value of " + a + " and " + b + " is " + c);
    }

    public static void add(String a, String b){
        String s = a + b;
        System.out.println("String concatenation of " + a + " and " + b + " is " + s);
    }
    public static void main(String[] args) {
        add(2, 4);
        add("Araika", "Singh");
    }
}
