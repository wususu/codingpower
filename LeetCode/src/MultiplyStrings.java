
// https://leetcode.com/problems/multiply-strings/description/
public class MultiplyStrings {
		
	private char[] reverse(char [] a){
		char [] b = new char[a.length];
		int j =0;
		for(int i=a.length-1;i>=0; i--){
			b[j++] = a[i];
		}
		return b;
	}
	
	public String multiply(String num1, String num2) {
		char [] a = reverse(num1.toCharArray());
		char [] b = reverse(num2.toCharArray());
		int[]data  = new int[a.length+b.length-1];
		for(int i=0;i<a.length;i++){
			int mul1 = a[i] - '0';
			for(int j=0;j<b.length;j++){
				data[i+j] += mul1 * (b[j] - '0');
			}
		}
		String resut = "";
		int w=0;
		for(int i=0;i<data.length; i++){
			w += data[i];
			resut = w%10 + resut;
			w /= 10;
		}
		if (w!=0) {
			resut = w + resut;
		}
		char[]  dd= resut.toCharArray();
		int i =0;
		while(i<dd.length &&dd[i] == '0')
			i++;
		
		if(i == dd.length)
			return  "0";
		return resut.substring(i);
    }

	public static void main(String[] args) {
		String num1 = "9133";
		String num2 = "0";
		System.out.println(new MultiplyStrings().multiply(num1, num2));
	}
}
