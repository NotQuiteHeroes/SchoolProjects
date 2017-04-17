//Updated Trip Calculator
//6/1/16

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class tripCalculator extends JApplet implements ActionListener
{
	
	public tripCalculator()
	{
		Container container = getContentPane();
		container.setLayout(new FlowLayout());
		
		String[] begin = {"Beginning Destiation","St. Louis", "New York City", "Los Angeles", "San Francisco", "Seattle", "Chicago"};
		JComboBox<String> beginning = new JComboBox<>(begin);
		container.add(beginning);
		
		String[] destination = {"Ending Destination","New Orleans", "Houston", "Boston", "Atlanta", "Los Vegas", "Pittsburg"};
		JComboBox<String> ending = new JComboBox<>(destination);
		container.add(ending);
		
		String[] vehicle = {"Vehicle Type","Compact", "Mid", "Luxury", "SUV"};
		JComboBox<String> vehicleType = new JComboBox<>(vehicle);
		container.add(vehicleType);
		
		String[] gases = {"Gas Type","Leaded", "Unleaded", "Super", "Diesel"};
		JComboBox<String> gasType = new JComboBox<>(gases);
		container.add(gasType);
		
		JLabel milesLabel = new JLabel("Total Miles:");
        container.add(milesLabel);
		JTextField milesField = new JTextField(5);
		container.add(milesField);
		
        JLabel gasLabel = new JLabel("Gas Price:");
        container.add(gasLabel);
		JTextField gasField = new JTextField(5);
		container.add(gasField);
		
		JLabel costLabel = new JLabel("Total Cost:");
		add(costLabel);
        JTextField costField = new JTextField(5);
        add(costField);
		
		Button Calculate = new Button("Submit");
		container.add(Calculate);
		Calculate.addActionListener((ActionEvent e) -> {
        	double oil = 39.99;
            double miles = Double.parseDouble(milesField.getText());
            double gas = Double.parseDouble(gasField.getText());
            double totalCost = ((miles*gas) + oil);
            costField.setText(String.valueOf(totalCost));
        });
		
		Button Clear = new Button("Clear");
		container.add(Clear);
		Clear.addActionListener((ActionEvent e) -> {
			beginning.setSelectedIndex(0);
			ending.setSelectedIndex(0);
			vehicleType.setSelectedIndex(0);
			gasType.setSelectedIndex(0);
			milesField.setText("");
			gasField.setText("");
			costField.setText("");
		});
			
	}
	
	public static void main(String[] args)
	{
		run(new tripCalculator(), 700, 150);
	}
	
	public static void run(JApplet applet, int width, int height)
	{
		JFrame f = new JFrame();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.getContentPane().add(applet);
		f.setSize(width, height);
		applet.start();
		f.setVisible(true);
	}
	
	@Override
    public void actionPerformed(ActionEvent e) 
    {
    throw new UnsupportedOperationException("Not supported yet.");
    }
    
}
		
