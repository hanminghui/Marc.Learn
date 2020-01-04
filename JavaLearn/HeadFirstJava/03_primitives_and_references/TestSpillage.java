public class TestSpillage {
    public static void main (String[] args) {
        int x = 24;
		// don't work, there's the possibility of spilling
		byte b = x;
    }
}
