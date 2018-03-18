import java.math.BigDecimal;

class Solution{

    public static BigDecimal strToIn(String number){
        BigDecimal numeric = new BigDecimal(number);
        return numeric;
    }

    public static void main(String[] args) {
        System.out.print(strToIn("-12312312312312399999999992321"));
    }
}