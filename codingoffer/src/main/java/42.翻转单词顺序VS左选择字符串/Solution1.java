import javax.sound.sampled.Line;

class Solution1{

    public static String reserveWorlds(String line){
        String[] worlds = line.split(" ");
        StringBuffer sf = new StringBuffer();
        for(int i=worlds.length-1; i>=0; i--){
            sf.append(worlds[i] + " ");
        }
        return sf.substring(0, sf.length()-1).toString();
    }

    public static void main(String[] args) {
        String resWorlds = reserveWorlds("I am a student.");
        System.out.println(resWorlds);
    }
}