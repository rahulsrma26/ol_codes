import java.util.*;
import java.util.stream.Collectors;

public class LargestNumber {

    String find(List<Integer> ary) {
        List<String> numbers = ary.stream().map(String::valueOf).collect(Collectors.toList());
        numbers.sort((String n1, String n2) -> Integer.compare(Integer.parseInt(n2 + n1), Integer.parseInt(n1 + n2)));
        return String.join("", numbers);
    }

    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<Integer>(Arrays.asList(2, 20, 31, 4, 6, 8));
        System.out.println(new LargestNumber().find(numbers));
    }
}
