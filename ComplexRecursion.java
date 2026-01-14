// RECURRENCE RELATION -> T(n)=3T(n/2) + (nlogn+n)
// WE GOT CASE 1 : a>b^k
// TIME COMPLEXITY IS O(n^log(base 2) 3)


import java.util.*;

public class ComplexRecursion {
    
    static long totalOps = 0;
    static int maxDepth = 0;

    static void complexRec(int n, int currentDepth) {
        if (currentDepth > maxDepth){
         maxDepth = currentDepth;
        }    
        
        if (n <= 2) {
            return;
        }
    
        int p = n;
        while (p > 0) {
            int[] temp = new int[n];
            for (int i = 0; i < n; i++) {
                temp[i] = i ^ p;
                totalOps++; 
            }
            p >>= 1;
        }

        int[] small = new int[n];
        for (int i = 0; i < n; i++) {
            small[i] = i * i;
            totalOps++; 
        }

        reverseArray(small);
        complexRec(n / 2, currentDepth + 1);
        complexRec(n / 2, currentDepth + 1);
        complexRec(n / 2, currentDepth + 1);
    }

    private static void reverseArray(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int inputN=sc.nextInt();
        
        long startTime = System.nanoTime(); 
        complexRec(inputN, 0);
        long endTime = System.nanoTime();   

        long durationNs = endTime - startTime;
        double durationMs = durationNs / 1_000_000.0;

        System.out.println("Analysis for n = " + inputN);
        System.out.println("-------------------------");
        System.out.println("Max Tree Depth:        " + maxDepth);
        System.out.println("Estimated Operations:  " + totalOps);
        System.out.println("Time Taken:            " + durationNs + " ns (" + durationMs + " ms)");
    }
}
