import java.util.*;
import java.util.stream.Collectors;
import java.util.function.Function;

public class SortFrequency {

    public static void main(String[] args) {
        List<Integer> numbers = new ArrayList<Integer>(Arrays.asList(4, 3, 5, 5, 5, 1, 3, 0, 2, 0));
        Map<Integer, Long> freq = numbers.stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
        numbers.sort((Integer n1, Integer n2) -> Long.compare(freq.get(n2), freq.get(n1)));
        System.out.println(Arrays.toString(numbers.toArray()));
    }
}
