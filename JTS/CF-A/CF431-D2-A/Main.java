//    Date : 2019-03-20
//  Author : Rahul Sharma
// Problem : http://codeforces.com/contest/431/problem/A

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[] count = new int[4];
        for (int i = 0; i < 4; i++)
            count[i] = sc.nextInt();

        sc.nextLine();
        String s = sc.nextLine();
        int calories = 0;
        for (int i = 0; i < s.length(); i++)
            calories += count[s.charAt(i) - '1'];
        System.out.println(calories);
    }
}
