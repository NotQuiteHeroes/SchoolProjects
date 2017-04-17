/*

	Programmer: Paige Eckstein
	Date: 5/15/16
	Filename: TripCalc.java
	Purpose: Calculate cost of trip given miles and gas price by user and an added 
	39.99 for an oil change
*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TripCalc extends Frame implements ActionListener
{


    
	public TripCalc()
	{
                FlowLayout tripLayout = new FlowLayout();
		setLayout(tripLayout);
		
		JLabel milesLabel = new JLabel("Total Miles:");
                add(milesLabel);
		JTextField milesField = new JTextField(5);
		add(milesField);
		
                JLabel gasLabel = new JLabel("Gas Price:");
                add(gasLabel);
		JTextField gasField = new JTextField(5);
		add(gasField);
		
		JLabel costLabel = new JLabel("Total Cost:");
		add(costLabel);
                JTextField costField = new JTextField(5);
                add(costField);
		
		Button Calculate = new Button("Calculate");
		add(Calculate);
		Calculate.addActionListener((ActionEvent e) -> {
                    double oil = 39.99;
                    double miles = Double.parseDouble(milesField.getText());
                    double gas = Double.parseDouble(gasField.getText());
                    double totalCost = ((miles*gas) + oil);
                    costField.setText(String.valueOf(totalCost));
                });
		
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
		TripCalc f = new TripCalc();
		f.setTitle("Trip Calculator");
		f.setBounds(200, 200, 500, 100);
		f.setVisible(true);
	}

    @Override
    public void actionPerformed(ActionEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

	
	
}

	
	
			