// 不用加减乘除法做加法
class Solution{

    public static int addByByteOpeation(int a, int b){
        int simpleAdd = a;
        int interByte = b;

        do{
            int temp = simpleAdd;
            simpleAdd = simpleAdd ^ interByte;
            interByte = (temp & interByte) << 1;
        }while(interByte !=  0 );
        return simpleAdd;
    }

    public static void main(String[] args) {
        int a = addByByteOpeation(10, 20);
        int b = addByByteOpeation(9, 3);
        int c = addByByteOpeation(-3, -2);
        int d = addByByteOpeation(-3, 1);
        int e = addByByteOpeation(-3, 5);

        System.out.print(a + " " + b + " " +c +" " +d + " " + e);

    }
}