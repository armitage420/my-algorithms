package Overriding;

public abstract class Shape {
    // Overriding is a term when a method shares the same name and function signature as another method in it's super class
    public void printMe(){
        System.out.println("I am Shape super class.");
    }
    public abstract double computeArea();
}