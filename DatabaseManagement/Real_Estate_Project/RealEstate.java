//Tabbed Panes: https://docs.oracle.com/javase/tutorial/uiswing/components/tabbedpane.html

import javax.swing.*;
import javax.swing.table.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.Vector;

@SuppressWarnings("serial")
class RealEstate extends JApplet implements ActionListener
{

private static Connector connection;

//constructor calls setup
RealEstate() throws SQLException
{
        connection = new Connector();
        setup(this);
}

//main creates new application
public static void main(String[] args) throws SQLException
{
        RealEstate realEstate = new RealEstate();
}

//setup creates tabbed pane, tab icons, individual tab's
//panels and main frame
private void setup(RealEstate realEstate) throws SQLException
{
        //Create tabbed pane
        JTabbedPane tabbedPane = new JTabbedPane();

        //get icons for tabs
        ImageIcon propertyIcon = createImageIcon("images/property.jpg");
        ImageIcon agentIcon = createImageIcon("images/person.jpg");

        //create panel for add agent tab
        JComponent agentPanel = setupAgentPanel();

        //add agent panel to tabbed pane
        //Parameters are:
        //("Tab Name", icon, individualPanel, "Hover Text")
        tabbedPane.addTab("Add Agent", agentIcon, agentPanel, "Add Agent Information");

        //create panel for houses status tab
        JComponent agentInfoPanel = setupAgentInfoPanel();

        //add housesPanel to tabbed pane
        //Parameters are:
        //("Tab Name", icon, individualPanel, "Hover Text")
        tabbedPane.addTab("Agent Information", agentIcon, agentInfoPanel, "View Agent Information");


        //create panel for add property tab
        JComponent propertyPanel = setupPropertyPanel();

        //add property panel to tabbed pane
        //Parameters are:
        //("Tab Name", icon, individualPanel, "Hover Text")
        tabbedPane.addTab("Add Property", propertyIcon, propertyPanel, "Add Property Information");

        //create panel for houses status tab
        JComponent housesPanel = setupHousesPanel();

        //add housesPanel to tabbed pane
        //Parameters are:
        //("Tab Name", icon, individualPanel, "Hover Text")
        tabbedPane.addTab("Houses Status", propertyIcon, housesPanel, "View House Statuses");

        //create panel for houses status tab
        JComponent aptPanel = setupAptPanel();

        //add aptPanel to tabbed pane
        //Parameters are:
        //("Tab Name", icon, individualPanel, "Hover Text")
        tabbedPane.addTab("Apartment Status", propertyIcon, aptPanel, "View Apartment Statuses");

        //add tabbed pane to real estate
        add(tabbedPane);

        //create main frame, give it a title, and set size
        JFrame mainFrame = new JFrame("Real Estate");
        mainFrame.setSize(500, 400);

        //closes window when appropriate
        mainFrame.addWindowListener(new WindowAdapter(){
                        public void windowClosing(WindowEvent windowEvent){
                                System.exit(0);
                        }
                });

        //add real estate with tabbed panel to main frame
        //and make visible
        mainFrame.add(realEstate);
        mainFrame.setVisible(true);

}

//setup panel for add agent tab
private static JComponent setupAgentPanel() throws SQLException
{
        //create panel
        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());

        //Office drop down menu
        String[] officeList = {"Red Office", "Blue Office", "Green Office", "Orange Office", "Yellow Office"};
        JComboBox<String> offices = new JComboBox<String>(officeList);
        //drop down menu displays
        //workaround to set width of combo box
        offices.setPrototypeDisplayValue("XXXXXXXXXXXXXXXXXXXXXX");
        panel.add(offices);

        //Agent first name label and field
        JLabel firstNameLabel = new JLabel("First Name:");
        JTextField firstNameField = new JTextField(20);
        panel.add(firstNameLabel);
        panel.add(firstNameField);

        //Agent last name label and field
        JLabel lastNameLabel = new JLabel("Last Name:");
        JTextField lastNameField = new JTextField(20);
        panel.add(lastNameLabel);
        panel.add(lastNameField);

        //Agent email label and field
        JLabel emailLabel = new JLabel("Email:");
        JTextField emailField = new JTextField(20);
        panel.add(emailLabel);
        panel.add(emailField);

        //Agent phone label and field
        JLabel phoneLabel = new JLabel("Phone:");
        JTextField phoneField = new JTextField(20);
        panel.add(phoneLabel);
        panel.add(phoneField);

        //Agent zip code label and field
        JLabel zipLabel = new JLabel("Zip:");
        JTextField zipField = new JTextField(20);
        panel.add(zipLabel);
        panel.add(zipField);

        //submit button for add agent tab
        JButton submit = new JButton("Submit");
        panel.add(submit);
        submit.addActionListener((ActionEvent e)->{
                        //variables to hold user input
                        //will be used in query after being stripped
                        final int officeID;
                        final String firstName;
                        final String lastName;
                        final String email;
                        final String phone;
                        final int zip;

                        //if any fields are empty, show error message
                        if(firstNameField.getText().isEmpty() || lastNameField.getText().isEmpty() || emailField.getText().isEmpty() || phoneField.getText().isEmpty() || zipField.getText().isEmpty()) {
                                JOptionPane.showMessageDialog(new JFrame(), "All fields must be filled.", "Error", JOptionPane.ERROR_MESSAGE);
                        }
                        //if all fields filled:
                        else {
                                officeID = getOfficeID(offices.getSelectedItem().toString());
                                firstName = firstNameField.getText();
                                lastName = lastNameField.getText();
                                email = emailField.getText();
                                phone = phoneField.getText();
                                zip = Integer.parseInt(zipField.getText());

                                runAgentQuery(officeID, firstName, lastName, email, phone, zip);
                        }

                });

        return panel;
}

//setup panel for add property tab
private static JComponent setupPropertyPanel() throws SQLException
{
        //create panel
        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());

        //agent id label and field
        //possibly change to agent name then lookup their id for user
        //or add option for user to search for id by agent name
        JLabel agentLabel = new JLabel("Agent ID:");
        JTextField agentField = new JTextField(13);
        panel.add(agentLabel);
        panel.add(agentField);

        //Status drop down menu
        String[] statusList = {"Sold", "Under Contract", "Available for Rent", "Available for Sale", "Leased"};
        JComboBox<String> statuses = new JComboBox<String>(statusList);
        //Status displays
        JLabel statusLabel = new JLabel("Status: ");
        //work around to force size of JComboBox
        statuses.setPrototypeDisplayValue("XXXXXXXXXXXXXXXXXXXXXXX");
        panel.add(statusLabel);
        panel.add(statuses);

        //State label and field
        //Should be abbreviated form
        //Might change to drop down box then convert to abrv. form
        JLabel stateLabel = new JLabel("State:");
        JTextField stateField = new JTextField(20);
        panel.add(stateLabel);
        panel.add(stateField);

        //address label and field
        JLabel addressLabel = new JLabel("Street Address:");
        JTextField addressField = new JTextField(20);
        panel.add(addressLabel);
        panel.add(addressField);

        //city label and field
        JLabel cityLabel = new JLabel("City:");
        JTextField cityField = new JTextField(20);
        panel.add(cityLabel);
        panel.add(cityField);

        //zip code label and field
        JLabel zipLabel = new JLabel("Zip:");
        JTextField zipField = new JTextField(20);
        panel.add(zipLabel);
        panel.add(zipField);

        //add property submit button
        JButton submit = new JButton("Submit");
        panel.add(submit);
        submit.addActionListener((ActionEvent e)->{
                        final int agentID;
                        final int statusID;
                        final int zip;
                        final String address;
                        final String state;
                        final String city;

                        if(agentField.getText().isEmpty() || zipField.getText().isEmpty() || cityField.getText().isEmpty() || stateField.getText().isEmpty() || addressField.getText().isEmpty()) {
                                JOptionPane.showMessageDialog(new JFrame(), "All fields must be filled.", "Error", JOptionPane.ERROR_MESSAGE);
                        }
                        //if all fields filled:
                        else {
                                statusID = getStatusID(statuses.getSelectedItem().toString());
                                agentID = Integer.parseInt(agentField.getText());
                                zip = Integer.parseInt(zipField.getText());
                                address = addressField.getText();
                                state = stateField.getText();
                                city = cityField.getText();

                                runPropertyQuery(statusID, agentID, zip, address, state, city);
                        }
                });

        return panel;
}


//setup panel for agent information tab
private static JComponent setupAgentInfoPanel() throws SQLException
{
        //create panel
        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());

        TableModel tableModel = buildTableModel(getData(1));
        JTable table = new JTable(tableModel);
        panel.add(new JScrollPane(table));

        return panel;
}


//setup panel for home information
private static JComponent setupHousesPanel() throws SQLException
{
        //create panel
        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());

        TableModel tableModel = buildTableModel(getData(2));
        JTable table = new JTable(tableModel);
        panel.add(new JScrollPane(table));

        return panel;
}


//setup panel for apartment information tab
private static JComponent setupAptPanel() throws SQLException
{
        //create panel
        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout());

        TableModel tableModel = buildTableModel(getData(3));
        JTable table = new JTable(tableModel);
        panel.add(new JScrollPane(table));

        return panel;
}

private static ResultSet getData(int type) throws SQLException
{
        ResultSet rs = null;
        //agent information query
        if(type == 1)
        {
                try{
                        rs = connection.agentInfoQuery();
                } catch(SQLException e) {
                        System.out.println(e);
                }
        }
        else if(type == 2)
        {
                try{
                        rs = connection.houseQuery();
                } catch(SQLException e) {
                        System.out.println(e);
                }
        }
        else if(type == 3)
        {
                try{
                        rs = connection.aptQuery();
                } catch(SQLException e) {
                        System.out.println(e);
                }
        }

        return rs;
}

private static TableModel buildTableModel(ResultSet rs) throws SQLException
{
        int columnCount = rs.getMetaData().getColumnCount();

        Vector<String> columnNames = new Vector<>();
        for(int columnIndex = 1; columnIndex <= columnCount; columnIndex++)
        {
                columnNames.add(rs.getMetaData().getColumnName(columnIndex));
        }

        Vector<Vector<Object> > dataVector = new Vector<>();
        while(rs.next())
        {
                Vector<Object> rowVector = new Vector<>();
                for(int columnIndex = 1; columnIndex <= columnCount; columnIndex++)
                {
                        rowVector.add(rs.getObject(columnIndex));
                }
                dataVector.add(rowVector);
        }

        return new DefaultTableModel(dataVector, columnNames);
}
private static void runAgentQuery(int officeID, String firstName, String lastName, String email, String phone, int zip)
{
        try{
                connection.agentQuery(officeID, firstName, lastName, email, phone, zip);
        } catch(SQLException e) {
                System.out.println(e);
        }
}

private static void runPropertyQuery(int statusID, int agentID, int zip, String address, String state, String city)
{
        try{
                connection.propertyQuery(statusID, agentID, zip, address, state, city);
        }catch(SQLException e) {
                System.out.println(e);
        }
}

//Create ImageIcon or return null if path is incorrect/not there
private static ImageIcon createImageIcon(String path)
{
        java.net.URL imgURL = RealEstate.class.getResource(path);
        if(imgURL != null)
        {
                return new ImageIcon(imgURL);
        }
        else
        {
                System.err.println("Couldn't find file: " + path);
                return null;
        }
}

private static int getOfficeID(String officeName)
{
        int officeNumber = 0;
        if(officeName.equals("Red Office")) {
                officeNumber = 1;
        }
        else if(officeName.equals("Blue Office")) {
                officeNumber = 2;
        }
        else if(officeName.equals("Green Office")) {
                officeNumber = 3;
        }
        else if(officeName.equals("Orange Office")) {
                officeNumber = 4;
        }
        else if(officeName.equals("Yellow Office")) {
                officeNumber = 5;
        }
        return officeNumber;
}

private static int getStatusID(String statusName)
{
        int statusNumber = 0;

        if(statusName.equals("Sold")) {
                statusNumber = 1;
        }else if(statusName.equals("Under Contract")) {
                statusNumber = 2;
        }else if(statusName.equals("Available for Sale")) {
                statusNumber = 3;
        }else if(statusName.equals("Available for Rent")) {
                statusNumber = 4;
        }else if(statusName.equals("Leased")) {
                statusNumber = 5;
        }

        return statusNumber;
}
@Override
public void actionPerformed(ActionEvent e){
        throw new UnsupportedOperationException("Not supported yet.");
}

}
