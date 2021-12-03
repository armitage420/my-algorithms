import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Vector;

public class Collections {
    public static void main(String[] args) {
        // ArrayList: Dynamically resizing arrays which grows as we insert elements, not synchronised, 50% increment of size if exceeded capacity.
        ArrayList<String> arrList = new ArrayList<>();
        arrList.add("Araika");
        arrList.add("Singh");
        int a = arrList.size();
        for(String x : arrList){
            System.out.println("ArrayList " + x + " size " + a);
        }

        // Vector is slow because it is synchronized, i.e., in a multithreading environment, it holds the other threads in runnable or non-runnable state until current thread releases the lock of the object.
        // 100% increment of size if capacity exceeded 
        Vector<String> v = new Vector<>();
        v.add("Araika");
        v.add("Singh");
        int n = v.size();
        for(String x : v){
            System.out.println("Vector " + x + " size " + n);
        }

        LinkedList<String> ll = new LinkedList<>();
        ll.add("Singh");
        ll.addFirst("Araika");
        ll.add("Singh");
        ll.removeLast();
        int b = ll.size();

        for(String s : ll){
            System.out.println("LinkedList " + s + " size " + b);
        }

        HashMap<String, String> hmap = new HashMap<>();
        hmap.put("First name", "Araika");
        hmap.put("Last name", "Singh");

        for(Map.Entry<String, String> m : hmap.entrySet()){
            System.out.println("Key--> " + m.getKey() + " Value--> " + m.getValue());
        }

        // min heap by default 
        PriorityQueue<Integer> pqMin = new PriorityQueue<>();
        pqMin.add(1);
        pqMin.add(2);
        pqMin.add(3);
        pqMin.add(3);
        System.out.println("Top element: " + pqMin.peek());
        System.out.println("Removed Top element: " + pqMin.poll());
        System.out.println("Removed element not it's duplicate: " + pqMin.remove(3));

        for(int x : pqMin){
            System.out.println(x);
        }

        // max heap 
        PriorityQueue<Integer> pqMax = new PriorityQueue<>((x,y) -> y.compareTo(x));
        pqMax.add(1);
        pqMax.add(2);
        pqMax.add(3);
        pqMax.add(3);
        System.out.println("Top element: " + pqMax.peek());
        System.out.println("Removed Top element: " + pqMax.poll());
        System.out.println("Removed element not it's duplicate: " + pqMax.remove(3));

        for(int x : pqMax){
            System.out.println(x);
        }
    }
    
}
