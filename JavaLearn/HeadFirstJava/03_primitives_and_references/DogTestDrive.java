public class DogTestDrive {
	public static void main (String[] args) {

		System.out.println(Dog.discribe);
		Dog black = new Dog();
		System.out.println(black.name);
		black.bark();

		final Dog white = new Dog();
		// white = black;
		// white = null;
		white.bark();

		black = null;
		System.out.println(black.name);
		black.bark();
	}
}
