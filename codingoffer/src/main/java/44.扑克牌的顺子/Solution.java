import java.util.Arrays;

// 大王小王为0,A为1,J为11,Q为12,K为13
class Solution{
    
    public static boolean isContinus(int numbers[]){
        Arrays.sort(numbers);
        int zeroCount = 0;
        int interruptCount = 0;
        for(int i=0; i<numbers.length; i++ ){
            if(numbers[i] == 0){
                zeroCount++;
                continue;
            }
            if(numbers[i-1] != 0 && numbers[i] != numbers[i-1]+1){
                interruptCount += numbers[i] - numbers[i-1] - 1;
            }
        }
        return zeroCount >= interruptCount;
    }


    public static void main(String[] args) {
        boolean one = isContinus(new int[]{9,5,6,4,8,0,0});
        boolean two = isContinus(new int[]{1,5,6,4,8,0,0});
        System.out.print(one);
        System.out.print(two);

    }
}