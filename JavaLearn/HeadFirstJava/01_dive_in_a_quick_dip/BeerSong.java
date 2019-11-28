public class BeerSong {
    public static void main (String[] args) {
        int numbers = 99;
		String word = " bottles";

		while (numbers > 0) {
			if (numbers == 1) {
				word = " bottle";
			}
			System.out.println(numbers + word + 
					           " of beer on the wall, " + 
					           numbers + word + 
							   " of beer.");
			numbers--;
			if (numbers == 1) {
				word = " bottle";
			}
			if (numbers > 0) {
				System.out.println("Take one down and pass it around, " + 
								   numbers + word + 
								   " of beer on the wall.");
			} else {
				System.out.println("Take one down and pass it around, " + 
								   "no more bottles of beer on the wall.");
			}
			System.out.println("");
		}
		System.out.println("No more bottles of beer on the wall, " + 
				           "no more bottles of beer.");
		System.out.println("Go to the store and buy some more, " + 
				           "99 bottles of beer on the wall.");
    }
}
