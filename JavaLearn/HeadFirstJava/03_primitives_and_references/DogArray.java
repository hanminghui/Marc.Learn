public class DogArray {
	public static void main (String[] args) {

		Dog[] pets;
		pets = new Dog[7];

		pets[0] = new Dog();
		pets[0].name = "black";
		pets[1] = new Dog();
		pets[1].name = "white";

		System.out.println(pets[0]);
		System.out.println(pets[0].name);
		System.out.println(pets[1]);
		System.out.println(pets[1].name);

		pets[2] = pets[0];
		System.out.println(pets[2]);
		System.out.println(pets[2].name);
	}
}
