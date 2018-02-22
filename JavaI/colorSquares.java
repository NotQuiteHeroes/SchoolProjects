/** Paige Eckstein
 * Java I
 * 5/1/16
 * This applet will create randomly colored squares
 */

/* Graphics and Color */

import java.awt.*;

import java.applet.*;

public class colorSquares extends Applet {

int width, height;

public void init(){

								width = getSize().width;
								height = getSize().height;

}

public void paint(Graphics g) {

								/*Variables to be used to hold RGB values */
								int redVal, greenVal, blueVal;

								for (int i = 30; i < (height - 25); i+=30) {
																for (int j = 5; j < (width - 25); j+=30) {

																								/*Use Math.floor to get a whole number randomly chosen
																								   from between 0 and 256*/
																								redVal = (int)Math.floor(Math.random() * 256);
																								greenVal = (int)Math.floor(Math.random() * 256);
																								blueVal = (int)Math.floor(Math.random() * 256);

																								/* This will create a color using the randomized
																								   RGB values from above and set g to it */
																								g.setColor(new Color(redVal, greenVal, blueVal));
																								g.fillRect(j, i, 25, 25);
																								g.setColor(Color.black);

																								/* This will draw a square of width 25 and height 25 at
																								   (i-1, j-1) */
																								g.drawRect(j, i, 25, 25);

																}
								}
}
}
