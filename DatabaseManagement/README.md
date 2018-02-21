# Database Management

The focus of this course was various database management roles, such as creating a database, creating users for said database,
assigning privileges for the users, creating and normalizing tables in the database, and writing a GUI in Java to connect to the database
and run queries. 

## Real Estate Project

This project is the main focus of the course, with components being added each week. It requires a database holding information for a 
Real Estate company. The program then displays a GUI for the user to add a property or agent, view current agents and properties, and
view scheduling information. It is connected to a database to query to display the results, as well as update when new agents or
properties are added. 

### Database Information:
#### Name: 
dbproject
#### User Information:
Username: projectUser

Password: projectPassword

Privileges: INSERT, SELECT

#### Tables:
Agent: agent_id (PK)[int], office_id (FK)[int], agent_fname[varchar], agent_lname[varchar], agent_email[varchar], agent_phone[varchar],
agent_zip [int]

Assistant: assistant_id (PK)[int], assistant_fname [varchar], assistant_lname [varchar], assistant_phone [varchar]

Schedule: schedule_id (PK)[int], agent_id (FK)[int], assistant_id(FK)[int]

Office: office_id (PK)[int], office_address[varchar], office_name[varchar]

Status: status_id (PK)[int], status_condition [varchar]

Property: property_id (PK)[int], agent_id (FK)[int], status_id (FK)[int], property_zip[int], property_address [varchar], 
property_state[varchar], property_city[varchar]

### Compilation:
javac *.java

### Execution:
*Note this requires the JDBC driver. The following path should be changed to wherever the driver is kept.

java -cp .;"C:\Program Files\Java\jdbc\mysql-connector-java-5.1.45-bin.jar" RealEstate

### Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/databaseAddAgent.JPG "Add new agent")
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/databaseAddProp.JPG "Add new property")
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/databaseAgentInfo.JPG "View current agents information")
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/databaseAptStat.JPG "View apartment information")
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/databaseHouseStat.JPG "View house information")
