package Overriding;

public class Overridingmain {
    public static void main(String[] args) {
        Overriding.Shape[] shapes = new Overriding.Shape[2];
        Overriding.Circle circle = new Overriding.Circle();
        circle.printMe();
        Overriding.Ambiguous ambiguous = new Overriding.Ambiguous();
        ambiguous.printMe();

        shapes[0] = circle;
        shapes[1] = ambiguous;

        for(Shape s : shapes){
            s.printMe();
            System.out.println(s.computeArea());
        }

        Overriding.Shape circle2 = new Overriding.Circle();
        circle2.printMe();

        Overriding.Circle circleKid = new Overriding.CircleKid();
        circleKid.printMe();

        Overriding.Shape circleKid2 = new Overriding.CircleKid();
        circleKid2.printMe();
    }
}
