
// 求1~n的累加和,不能使用乘除,for,while,if else, switch case,A?B:C等
class Solution{

    private static int sum = 0;

    private static boolean add(int n){
        sum += n;
        return (n-1 > 0 && add(n-1)); // 利用&&的短路机制实现
    }

    public static int sum(int n){
        sum = 0;
        add(n);
        return sum;
    }

    public static void main(String[] args) {
        System.out.println(sum(10));
        System.out.println(sum(0));
        System.out.println(sum(1));
    }
}