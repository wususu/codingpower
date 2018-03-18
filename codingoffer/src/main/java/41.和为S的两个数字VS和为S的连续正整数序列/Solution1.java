import java.util.Arrays;

import javax.lang.model.util.ElementScanner6;

class Solution1{


    public static int[] get(int[] arr, int s){
        int low = 0, high = arr.length-1;
        Arrays.sort(arr);
        int sum;
        while(low < high){
            if( (arr[low] + arr[high]) > s){
                high--;
            }else if(arr[low] + arr[high] < s){
                low++;
            }else{
                return new int[]{arr[low], arr[high]};
            }
        }
        return null;
    }

    public static void main(String[] args) {
        System.out.println(Arrays.toString(get(new int[]{1,2,3,42,1,4,6,3,1}, 4)));
        System.out.println(Arrays.toString(get(new int[]{1,2,3,42,1,4,6,3,1}, 23)));

    }
}