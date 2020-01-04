public class Dog {

	static String discribe = "Dog is a kind of animal.";

    String name = "VOID";
	void bark () {
	    System.out.println("woof woof woof");
	}

	@Override
	public String toString() {
		return "I'm " + name + 
			" [" + getClass().getName() + "@" + Integer.toHexString(hashCode()) + "]";
	}
}
