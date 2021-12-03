package Overriding;

public class CircleKid extends Circle{
    private double radius = 2;
    public void printMe(){
        System.out.println("I am circle's kid");
    }
    public double computeArea(){
        return radius * radius * 3.14;
    }
}
