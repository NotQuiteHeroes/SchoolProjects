//Prepared Statement: https://docs.oracle.com/javase/tutorial/jdbc/basics/prepared.html
import java.sql.*;
import java.lang.*;
import java.awt.Dialog;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

class Connector
{

//Connection object
private Connection con;

//Constructor calls openConnection
Connector()
{
        con = openConnection();
}

//Create connection
private Connection openConnection()
{
        try{
                Class.forName("com.mysql.jdbc.Driver");
                con = DriverManager.getConnection("jdbc:mysql://localhost:3306/dbProject", "projectUser", "projectPassword");
                return con;
        } catch(Exception e) {
                System.out.println(e);
                return null;
        }
}

//Closes connection
private void closeConnection()
{
        try{
                if(con != null)
                {
                        con.close();
                }
        }
        catch(Exception e)
        {
                System.out.println(e);
        }

}

//Query to add information to agent table
public void agentQuery(int officeID, String firstName, String lastName, String email, String phone, int zip) throws SQLException
{
        //store statement as string, using prepared statement format
        String stmt = "INSERT INTO agent (office_id, agent_fname, agent_lname, agent_email, agent_phone, agent_zip) values (?, ?, ?, ?, ?, ?)";

        //create prepared statement
        PreparedStatement pStmt = con.prepareStatement(stmt);

        //add information in to take ? place in prepared statement
        try {
                pStmt.setInt(1, officeID);
                pStmt.setString(2, firstName);
                pStmt.setString(3, lastName);
                pStmt.setString(4, email);
                pStmt.setString(5, phone);
                pStmt.setInt(6, zip);

                //run query
                pStmt.executeUpdate();
                JOptionPane.showMessageDialog(new JFrame(), "Insert Success!");
        } catch (SQLException e) {
                System.out.println(e);
                JOptionPane.showMessageDialog(new JFrame(), "Insert failed.", "Error", JOptionPane.ERROR_MESSAGE);
        }
        finally {
                try{
                        //close statement connection
                        if(pStmt != null)
                        {
                                pStmt.close();
                        }
                }catch(Exception e) {
                        System.out.println(e);
                }
        }

}

public ResultSet houseQuery() throws SQLException
{
        String stmt = "SELECT a.property_address, b.status_condition, c.agent_fname, c.agent_lname, c.agent_phone FROM property a INNER JOIN status b ON a.status_id = b.status_id INNER JOIN agent c ON a.agent_id = c.agent_id WHERE b.status_condition = 'Sold' OR b.status_condition = 'Under Contract' OR b.status_condition = 'Available For Sale';";

        PreparedStatement pStmt = con.prepareStatement(stmt);
        ResultSet rs = null;
        try {
                rs = pStmt.executeQuery();
        } catch (SQLException e) {
                System.out.println(e);
                JOptionPane.showMessageDialog(new JFrame(), "Select failed.", "Error", JOptionPane.ERROR_MESSAGE);
        }
        return rs;
}

public ResultSet aptQuery() throws SQLException
{
        String stmt = "SELECT a.property_address, b.status_condition, c.agent_fname, c.agent_lname, c.agent_phone FROM property a INNER JOIN status b ON a.status_id = b.status_id INNER JOIN agent c ON a.agent_id = c.agent_id WHERE  b.status_condition = 'Leased' OR b.status_condition = 'Available For Rent';";

        PreparedStatement pStmt = con.prepareStatement(stmt);
        ResultSet rs = null;
        try {
                rs = pStmt.executeQuery();
        } catch (SQLException e) {
                System.out.println(e);
                JOptionPane.showMessageDialog(new JFrame(), "Select failed.", "Error", JOptionPane.ERROR_MESSAGE);
        }
        return rs;
}

public ResultSet agentInfoQuery() throws SQLException
{
        String stmt = "SELECT a.agent_fname, a.agent_lname, a.agent_phone, b.office_address, c.assistant_fname, c.assistant_lname, c.assistant_phone FROM agent a INNER JOIN office b ON a.office_id = b.office_id INNER JOIN schedule d ON a.agent_id = d.agent_id INNER JOIN assistant c ON d.assistant_id = c.assistant_id;";

        PreparedStatement pStmt = con.prepareStatement(stmt);
        ResultSet rs = null;
        try {
                rs = pStmt.executeQuery();
        } catch (SQLException e) {
                System.out.println(e);
                JOptionPane.showMessageDialog(new JFrame(), "Select failed.", "Error", JOptionPane.ERROR_MESSAGE);
        }
        return rs;
}

//query to add information to property table
public void propertyQuery(int statusID, int agentID, int zip, String address, String state, String city) throws SQLException
{
        //save query as string using prepared statement format
        String stmt = "INSERT INTO property (agent_id, status_id, property_zip, property_address, property_state, property_city) values (?, ?, ?, ?, ?, ?)";

        //create prepared statement
        PreparedStatement pStmt = con.prepareStatement(stmt);

        //add information to take place of ? in prepared statement
        try {
                pStmt.setInt(1, agentID);
                pStmt.setInt(2, statusID);
                pStmt.setInt(3, zip);
                pStmt.setString(4, address);
                pStmt.setString(5, state);
                pStmt.setString(6, city);

                //run query
                pStmt.executeUpdate();
                JOptionPane.showMessageDialog(new JFrame(), "Insert Success!");
        } catch (SQLException e) {
                System.out.println(e);
                JOptionPane.showMessageDialog(new JFrame(), "Insert failed.", "Error", JOptionPane.ERROR_MESSAGE);
        }
        finally {
                try{
                        //close statement connection
                        if(pStmt != null)
                        {
                                pStmt.close();
                        }
                }
                catch(Exception e) {
                        System.out.println(e);
                }
        }

}
}
