
// 不能用于负数
// 不用加减乘除做加法
class Solution{

    public static int addByByteOpeation(int a, int b){
        int simpleAdd = a;
        int interByte = b;

        do{
            int temp = simpleAdd;
            simpleAdd = simpleAdd ^ interByte;
            interByte = (temp & interByte) << 1;
        }while(interByte > 0 );
        return simpleAdd;
    }

    public static void main(String[] args) {
        int a = addByByteOpeation(10, 20);
        int b = addByByteOpeation(9, 3);

        System.out.print(a + " " + b);

    }
}