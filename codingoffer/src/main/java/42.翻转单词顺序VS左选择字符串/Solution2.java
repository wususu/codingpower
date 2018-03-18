class Solution2{

    public static String leftChange(String s, int i){
        String result = "";
        result += s.substring(i,s.length());
        result += s.substring(0, i);
        return result;
    }

    public static void main(String[] args) {
        String ww = leftChange("abscefg", 2);
        System.out.println(ww);
    }
}