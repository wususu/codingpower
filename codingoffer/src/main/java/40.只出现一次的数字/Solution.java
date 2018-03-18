
class Solution{

    public static int yihuo(int[] arr, int start, int end){
        if(end < start){
            return 0;
        }
        int a = 0;
        for(int i=start; i<end; i++){
            a = a ^ arr[i];
        }
        return a;
    }

    public static int[] sort(int[] arr){
        if(arr.length == 0 ){
            return null;
        }
        if(arr.length == 1){
            return new int[]{arr[0]};
        }
        int yihuoSum = yihuo(arr, 0, arr.length);
        int flag = 0; // 异或结果中从右起第一个1的位置,两个数这一位一定不一样
        if ((yihuoSum & 1) != 1){
            yihuoSum = yihuoSum >> 1;
        }
        int arr1[] = new int[arr.length];
        int arr2[] = new int[arr.length];
        int a=0,b=0;
        // 根据该位0/1把两个数分到两个数组中
        for(int i=0;i<arr.length; i++){
            if( ((arr[i] >> flag) & 1) == 1){
                arr1[a++] = arr[i];
            }else{
                arr2[b++] = arr[i];
            }
        }
        int result[] = new int[]{yihuo(arr1, 0, a), yihuo(arr2, 0, b)};
        return result;
    }


    public static void main(String[] args) {
        int a[] = sort(new int[]{1,2,3,1,4,3,2,5});
        System.out.println(Arrays.toString(a));
    }
}