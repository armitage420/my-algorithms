import java.util.*;
public class hashy{
    public static void main(String[] args) {
        HashMap<Integer, Integer> m = new HashMap<>();
        m.put(1, 2);
        m.put(3, 4);

        m.forEach((k,v) -> System.out.println("key: "+k+" value:"+v));
    }
}