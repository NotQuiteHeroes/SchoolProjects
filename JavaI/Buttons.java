/*
	Chapter 6:	Borders
	Programmer: Paige Eckstein
	Date: 5/15/16
	Filename:	Borders.java
	Purpose: Change background color depending on user input
*/

import java.awt.*;
import java.awt.event.*;


public class Buttons extends Frame implements ActionListener, ItemListener
{
	public Buttons()
	{
		//set the layout
		setLayout(new  BorderLayout(20, 5));

      	//Add buttons
      	Button Red = new Button("Red");
      	Button Yellow = new Button("Yellow");
      	Button Cyan = new Button("Cyan");
      	Button Magenta = new Button("Magenta");
      	
      	//Add Color Choice box
      	Choice colors = new Choice();
      	
		//Add buttons and colors choice, attaching ActionListeners and ItemListener
		add(Red, BorderLayout.NORTH);
		Red.addActionListener(this);
		
		add(Yellow, BorderLayout.SOUTH);
		Yellow.addActionListener(this);
		
		add(Cyan, BorderLayout.EAST);
		Cyan.addActionListener(this);
		
		add(Magenta, BorderLayout.WEST);
		Magenta.addActionListener(this);
		
		add(colors, BorderLayout.CENTER);
		colors.addItemListener(this);
		
		//Add color options to colors choice box
		colors.add("Red");
		colors.add("Yellow");
		colors.add("Cyan");
		colors.add("Magenta");
		colors.add("White");


		//override the windowClosing event
		addWindowListener(
			new WindowAdapter()
				{
				public void windowClosing(WindowEvent e)
					{
					   System.exit(0);
					}
				}
		);

	}

   	public static void main(String[] args)
   	{
	   	// set frame properties
		Buttons f = new Buttons();
      	f.setTitle("Border Application");
      	f.setBounds(200,200,300,300);
	    f.setVisible(true);
	    
	    //Change background color to Red
	    f.setBackground(Color.RED);
   }
   
   //used to set background color to save on repetitive code
   private void setColor(String arg)
   {
   		if(arg.equals("Red")){
   			setBackground(Color.red);
   		}
   		else if(arg.equals("Yellow")){
   			setBackground(Color.yellow);
   		}
   		else if(arg.equals("Cyan")){
   			setBackground(Color.cyan);
   		}
   		else if(arg.equals("Magenta")){
   			setBackground(Color.magenta);
   		}
   		else if(arg.equals("White")){
   			setBackground(Color.white);
   		}
   	}
   
   //Monitors button clicks and calls setColor with appropriate argument
   //depending on button clicked.	
   public void actionPerformed(ActionEvent e)
   {
   
   		setColor(e.getActionCommand());
   	}
   	
   	//Casts object returned from getItem as String
   	//passes string as appropriate argument to setColor depending on
   	//user selection in colors Choice box
   	public void itemStateChanged(ItemEvent ie)
   	{
   		String arg = (String)ie.getItem();
   		setColor(arg);
   	}
}