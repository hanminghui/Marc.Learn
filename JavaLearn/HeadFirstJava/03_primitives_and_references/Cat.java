// Original code is Dog, but the filename is already used

public class Cat {

	String name;

	public void meow () {
	    System.out.println(name + " says Miaow!");
	}

	public void eat () {
	}

	public static void main (String[] args) {
		// make a Cat object and access it
		Cat cat1 = new Cat();
		cat1.meow();
		cat1.name = "Amy";

		// now make a Cat array
		Cat[] myCats = new Cat[3];
		// and put some cats in it
		myCats[0] = new Cat();
		myCats[1] = new Cat();
		myCats[2] = cat1;

		// now access the Cats using the array references
		myCats[0].name = "Kat";
		myCats[1].name = "Mary";

		// Hmmm... what is myCats[2] name?
		System.out.print("last cat's name is ");
		System.out.println(myCats[2].name);

		// now loop through the array
		// and tell all cats to meow
		int x = 0;
		while (x < myCats.length) {
		    myCats[x].meow();
			x++;
		}
	}
}
