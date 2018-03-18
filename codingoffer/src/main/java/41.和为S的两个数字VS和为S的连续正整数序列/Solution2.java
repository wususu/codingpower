import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.lang.model.util.ElementScanner6;
import javax.security.auth.login.LoginException;

class Solution2{

    private static class Inner{
        private int low;
        private int high;
        public Inner(int low, int high){
            this.low = low;
            this.high = high;
        }
        @Override
        public String toString() {
            return "[low= "+ low + "] [high=" + high + "]";
        }
    }

    static List<Object> list = new ArrayList<>();

    public static int sum(int low, int high){
        int sum=0;
        for(int i=low; i<high; i++){
            sum += i;
        }
        return sum;
    }

    public static void getArr(int s){
        int low = 0, high = 2, sum;
        while(2*low <= s){
            sum = sum(low, high);
            if (sum == s){
                list.add(new Inner(low, high));
                high++;
            }
            else if(sum < s){
                high++;
            }
            else{
                low++;
            }
        }
    }

    public static void main(String[] args) {
        getArr(9);
        System.out.println(list);
    }
}