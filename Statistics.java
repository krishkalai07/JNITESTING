public class Statistics {
    public static native double sum (int[] numbers);
    public static native double avg (int[] numbers);
    public static native double stddev (int[] numbers);

    static {
        System.loadLibrary("statistics");
    }

    public static void main(String[] args) {
        int[] numbers = {22, 33, 33};

        System.out.println("In Java, the sum is " + sum(numbers));
        System.out.println("In Java, the average is " + avg (numbers));
        System.out.println("In java, the standard dev is " + stddev(numbers));
    }

}
