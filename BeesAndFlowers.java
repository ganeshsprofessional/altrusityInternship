import java.util.*;

public class BeesAndFlowers {
    public static List<Integer> countBeesBetweenFlowers(String s, int[] startIndex, int[] endIndex) {
        int n = s.length();
        List<Integer> flowerPositions = new ArrayList<>();
        int[] beePrefixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '|') flowerPositions.add(i);
            beePrefixSum[i + 1] = beePrefixSum[i] + (s.charAt(i) == '*' ? 1 : 0);
        }
        List<Integer> results = new ArrayList<>();
        for (int q = 0; q < startIndex.length; q++) {
            int start = startIndex[q] - 1;
            int end = endIndex[q] - 1;
            int left = lowerBound(flowerPositions, start);
            int right = upperBound(flowerPositions, end) - 1;
            if (left < flowerPositions.size() && right >= 0 && flowerPositions.get(left) <= flowerPositions.get(right)) {
                int bees = beePrefixSum[flowerPositions.get(right) + 1] - beePrefixSum[flowerPositions.get(left)];
                results.add(bees);
            } else {
                results.add(0);
            }
        }
        return results;
    }

    private static int lowerBound(List<Integer> list, int target) {
        int left = 0, right = list.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) >= target) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    private static int upperBound(List<Integer> list, int target) {
        int left = 0, right = list.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (list.get(mid) > target) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the string (only '*' and '|'):");
        String s = scanner.nextLine();
        System.out.println("Enter the number of queries:");
        int q = scanner.nextInt();
        int[] startIndex = new int[q];
        int[] endIndex = new int[q];
        System.out.println("Enter the queries (startIndex and endIndex):");
        for (int i = 0; i < q; i++) {
            startIndex[i] = scanner.nextInt();
            endIndex[i] = scanner.nextInt();
        }
        List<Integer> results = countBeesBetweenFlowers(s, startIndex, endIndex);
        System.out.println("Results:");
        for (int result : results) {
            System.out.println(result);
        }
        scanner.close();
    }
}
