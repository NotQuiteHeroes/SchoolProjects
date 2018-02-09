# Edge Weighted Graph

Edge Weighted Graph class represents an edge weighted graph. 

It holds information on the graph's vertices and edges.

It also contains a LinkedList called adj that contains the graph's adjacency list information, made up of Edge objects.

To be used with a file containing graph information in the format:

total vertices

total edges

integer first edge, integer second edge, double weight

## Output:

x vertices, y edges.

vertex: connection weight, connection weight, connection weight

etc. for each vertex, where connection is the connection point between vertices, and weight is the weight of
said connection. 

## Files:

+ EdgeWeightedGraph: implementation
+ Edge: Edge class to be used with EdgeWeightedGraph's adjacency lists
+ GraphClient: test file for EdgeWeightedGraph
+ sampleEdgeWeightedGraph.txt: text file containing graph information, to be used with GraphClient to test

## Compilation:

javac *.java

## Execution:
java GraphClient sampleEdgeWeightedGraph.txt

## Usage:
![alt text](https://github.com/NotQuiteHeroes/Resources/blob/master/ScreenShots/edgeWeightedGraph.JPG "GUI Version")
