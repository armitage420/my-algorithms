package Overriding;

public class Circle extends Shape {
    private double radius = 10;
    public void printMe(){
        System.out.println("I am a Circle sub class of Shape");
    }

    public double computeArea(){
        return radius *radius * 3.14;
    }
}
