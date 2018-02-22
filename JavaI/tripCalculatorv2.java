//Trip Calculator v2.
//Drop down options use predetermined values
//Allow to choose from presets, or perform custom calculations


import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.text.DecimalFormat;

public class tripCalculatorv2 extends JApplet implements ActionListener
{
DecimalFormat df = new DecimalFormat("#.00");
final double OIL_COST = 30.00;
static double miles = 0.0;
static double gasCost = 0.0;
static double totalCost = 0.0;
static String beginLoc;
static String endLoc;
static String vehicle;
static String gas;


public tripCalculatorv2()
{
								Container container = getContentPane();
								container.setLayout(new FlowLayout());

								String[] begin = {"Beginning Location","St. Louis", "New York City", "Los Angeles", "San Francisco", "Seattle", "Chicago"};
								JComboBox<String> beginning = new JComboBox<>(begin);
								container.add(beginning);
								beginning.addActionListener((ActionEvent e)->{
																								beginLoc = beginning.getSelectedItem().toString();
																});

								String[] destination = {"Ending Location","New Orleans", "Houston", "Boston", "Atlanta", "Las Vegas", "Pittsburg"};
								JComboBox<String> ending = new JComboBox<>(destination);
								container.add(ending);
								ending.addActionListener((ActionEvent e)->{
																								endLoc = ending.getSelectedItem().toString();
																});

								String[] vehicles = {"Vehicle Type","Compact", "Mid", "Luxury", "SUV"};
								JComboBox<String> vehicleType = new JComboBox<>(vehicles);
								container.add(vehicleType);
								vehicleType.addActionListener((ActionEvent e)->{
																								vehicle = vehicleType.getSelectedItem().toString();
																});

								String[] gases = {"Gas Type","Leaded", "Unleaded", "Super", "Diesel"};
								JComboBox<String> gasType = new JComboBox<>(gases);
								container.add(gasType);
								gasType.addActionListener((ActionEvent e)->{
																								gas = gasType.getSelectedItem().toString();
																});

								JLabel milesLabel = new JLabel("Total Miles:");
								milesLabel.setVisible(false);
								container.add(milesLabel);
								JTextField milesField = new JTextField(5);
								milesField.setVisible(false);
								container.add(milesField);

								JLabel gasLabel = new JLabel("Gas Price:");
								gasLabel.setVisible(false);
								container.add(gasLabel);
								JTextField gasField = new JTextField(5);
								gasField.setVisible(false);
								container.add(gasField);

								JLabel costLabel = new JLabel("Total Cost:");
								container.add(costLabel);
								JTextField costField = new JTextField(5);
								container.add(costField);

								Button CalculateCustomize = new Button("Submit");
								CalculateCustomize.setVisible(false);
								container.add(CalculateCustomize);
								CalculateCustomize.addActionListener((ActionEvent e)->{
																								miles = Double.parseDouble(milesField.getText());
																								gasCost = Double.parseDouble(gasField.getText());
																								double mpg = miles/30.0;
																								totalCost = ((mpg*gasCost) + OIL_COST);
																								String results = String.format("%.2f", totalCost);
																								costField.setText(totalCost);
																});

								Button CalculateStandard = new Button("Submit");
								container.add(CalculateStandard);
								CalculateStandard.addActionListener((ActionEvent e)->{
																								miles = calculateMiles(beginLoc, endLoc);
																								gasCost = calculateGasCost(miles, gas);
																								double mpg;
																								if(vehicle.equals("Compact"))
																								{
																																mpg = miles/30;
																								}
																								else if(vehicle.equals("Mid"))
																								{
																																mpg = miles/25;
																								}
																								else if(vehicle.equals("Luxury"))
																								{
																																mpg = miles/27;
																								}
																								else
																								{
																																mpg = miles/23;
																								}
																								totalCost = ((mpg*gasCost) + OIL_COST);
																								String results = String.format("%.2f", totalCost);
																								costField.setText(results);
																});

								Button Clear = new Button("Clear");
								container.add(Clear);
								Clear.addActionListener((ActionEvent e)->{
																								beginning.setSelectedIndex(0);
																								ending.setSelectedIndex(0);
																								vehicleType.setSelectedIndex(0);
																								gasType.setSelectedIndex(0);
																								milesField.setText("");
																								gasField.setText("");
																								costField.setText("");
																});

								Button Back = new Button("Back");
								Back.setVisible(false);
								container.add(Back);
								Back.addActionListener((ActionEvent e)->{
																								milesLabel.setVisible(false);
																								milesField.setVisible(false);
																								gasLabel.setVisible(false);
																								gasField.setVisible(false);
																								beginning.setVisible(true);
																								ending.setVisible(true);
																								vehicleType.setVisible(true);
																								gasType.setVisible(true);
																								CalculateStandard.setVisible(true);
																								CalculateCustomize.setVisible(false);
																								Back.setVisible(false);
																});

								Button Customize = new Button("Customize");
								container.add(Customize);
								Customize.addActionListener((ActionEvent e)->{
																								milesLabel.setVisible(true);
																								milesField.setVisible(true);
																								gasLabel.setVisible(true);
																								gasField.setVisible(true);
																								beginning.setVisible(false);
																								ending.setVisible(false);
																								vehicleType.setVisible(false);
																								gasType.setVisible(false);
																								CalculateStandard.setVisible(false);
																								CalculateCustomize.setVisible(true);
																								Back.setVisible(true);
																								Customize.setVisible(false);
																});

}

public static double calculateMiles(String beginLoc, String endLoc)
{
								switch(beginLoc)
								{
								case "St. Louis":
																switch(endLoc)
																{
																case "New Orleans":
																								miles = 676.14;
																								break;
																case "Houston":
																								miles = 775.89;
																								break;
																case "Boston":
																								miles = 1192.51;
																case "Atlanta":
																								miles = 553.92;
																								break;
																case "Las Vegas":
																								miles = 1597.13;
																								break;
																case "Pittsburg":
																								miles = 601.75;
																								break;
																}
																break;
								case "New York City":
																switch(endLoc)
																{
																case "New Orleans":
																								miles = 1305.34;
																								break;
																case "Houston":
																								miles = 1628.44;
																								break;
																case "Boston":
																								miles = 215.31;
																								break;
																case "Atlanta":
																								miles = 873.76;
																								break;
																case "Las Vegas":
																								miles = 2522.37;
																								break;
																case "Pittsburg":
																								miles = 371.05;
																								break;
																}
																break;
								case "Los Angeles":
																switch(endLoc)
																{
																case "New Orleans":
																								miles = 1893.89;
																								break;
																case "Houston":
																								miles = 1547.91;
																								break;
																case "Boston":
																								miles = 2893.33;
																								break;
																case "Atlanta":
																								miles = 2173.31;
																								break;
																case "Las Vegas":
																								miles = 269.43;
																								break;
																case "Pittsburg":
																								miles = 2425.38;
																								break;
																}
																break;
								case "San Francisco":
																switch(endLoc)
																{
																case "New Orleans":
																								miles = 2274.82;
																								break;
																case "Houston":
																								miles = 1928.83;
																								break;
																case "Boston":
																								miles = 3099.98;
																								break;
																case "Atlanta":
																								miles = 2472.51;
																								break;
																case "Las Vegas":
																								miles = 568.63;
																								break;
																case "Pittsburg":
																								miles = 2577.6;
																								break;
																}
																break;
								case "Seattle":
																switch(endLoc)
																{
																case "New Orleans":
																								miles = 2577.62;
																								break;
																case "Houston":
																								miles = 2307.1;
																								break;
																case "Boston":
																								miles = 2051.49;
																								break;
																case "Atlanta":
																								miles = 2634.92;
																								break;
																case "Las Vegas":
																								miles = 1116.64;
																								break;
																case "Pittsburg":
																								miles = 2529.11;
																								break;
																}
																break;
								case "Chicago":
																switch(endLoc)
																{
																case "New Orleans":
																								miles = 926.38;
																								break;
																case "Houston":
																								miles = 1083.43;
																								break;
																case "Boston":
																								miles = 983.88;
																								break;
																case "Atlanta":
																								miles = 716.46;
																								break;
																case "Las vegas":
																								miles = 1747.59;
																								break;
																case "Pittsburg":
																								miles = 461.5;
																								break;
																}
																break;
								}
								return miles;
}

public static double calculateGasCost(double miles, String gas)
{
								switch(gas)
								{
								case "Leaded":
																gasCost = 2.50;
																break;
								case "Unleaded":
																gasCost = 2.90;
																break;
								case "Diesel":
																gasCost = 4.00;
																break;
								case "Super Unleaded":
																gasCost = 3.00;
																break;
								}

								return gasCost;
}

public static void main(String[] args)
{
								run(new tripCalculatorv2(), 670, 140);
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
