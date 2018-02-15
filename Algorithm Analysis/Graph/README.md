# Graph

Graph class represents an undirected graph. It holds information on the graph's vertices and edges. It also contains a LinkedList
called adj that contains the graph's adjacency list information.

To be used with a file containing graph information in the format:

V x

E x

ATL HOUS 0 1

etc. to represent airline connections, where V x is the number of vertices, and E x is the number of edges.

Or with file in the format:

x1

x2

y1 y2

etc. to represent graph information, where x1 is the number of vertices, x2 is the number of edges, and y1 y2 is the connection
information

## Output

x vertices, y edges

vertex: [adjacency list]

Average degree = y

Self loops = z

## Compilation:

javac *.java

## Execution:
java GraphClient testFile.txt

## Usage
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/graph1.JPG "Graph test")
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/graph2.JPG "Graph test")
