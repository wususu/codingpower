class Solution{

    // f(n,m) = 0                       (n = 1)
    //        = [f(n-1, m) + m] % n     (n > 1)
    public static int lastRemaining(int n, int m){
        
        if(n < 1 || m < 1){
            return -1;
        }

        int last = 0;
        for(int i=2; i<=n; i++){
            last = (m+last) % i;
        }
        return last;
    }

    public static void main(String[] args) {
        System.out.println(lastRemaining(5, 3)); // 01234 3th
    }
}