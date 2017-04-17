/* Paige Eckstein */
/* Java 1 */
/* 4/18/16 */
/* This program will display the current date */

import java.util.*;
import java.text.*;


public class printDate {
	public static void main(String args[]) {
	
		Date currentDate = new Date( );
		SimpleDateFormat displayFormat = new SimpleDateFormat ("EEEEE, MMMMM d, yyyy");
		System.out.println(displayFormat.format(currentDate));
		
	}
}