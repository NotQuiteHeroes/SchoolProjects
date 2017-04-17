/* Paige Eckstein */
/* Java 1 */
/* 4/24/16 */
/* This program will display the circumference of a circle given the radius */

import java.util.Scanner;

public class Circumference {

	public static void main(String args[]) {
	
		Scanner reader = new Scanner(System.in);
		System.out.println("Enter the radius: ");
		double radius = reader.nextDouble();

		getCircum(radius);
		
	}

	public static void getCircum(double n) {

		
		double pi = 3.14;
		double circumference = 2*pi*n;
		System.out.println("The circumference is: " + circumference);
	}
}