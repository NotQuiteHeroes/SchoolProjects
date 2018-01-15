/**
 * Edge Weighted Graph class
 * Paige Eckstein
 * Algorithm Analysis
 *
 * Requires Edge.java
 * To be tested with GraphClient.java
 *
 * EdgeWeightedGraph class represents an edge weighted graph.
 * It holds information on the graph's vertices and edges.
 * Also contains a LinkedList called adj that contains
 * the graph's adjacency list information, made up of Edge objects.
 *
 * To be used with file containing graph information in the format:
 * Total vertices
 * Total Edges
 * integer first edge, integer second edge, double weight
 *
 */
import java.util.LinkedList;
import java.util.Scanner;

import java.io.File;
import java.io.FileNotFoundException;

class EdgeWeightedGraph
{
//Vertices
private int V;
//Edges
private int E;
//Adjacency List
LinkedList<Edge> adj[];

/**
 * Constructor to create empty Graph
 * @param  int V       [Number of vertices in Graph]
 */
public EdgeWeightedGraph(int V)
{
        //check if vertices is greater than 0, throw error if not.
        if (V < 0)
        {
                throw new IllegalArgumentException("Number of vertices must be nonnegative.");
        }

        //set graph's vertices
        this.V = V;
        //set graph's edges
        this.E = 0;
        //create linked list to hold adjacency information
        adj = new LinkedList[V];

        //each vertex gets its own adjacency list, so populate
        //adj with a series of adjacency lists
        for(int v = 0; v < V; v++)
        {
                adj[v] = new LinkedList<>();
        }
}

/**
 * Constructor given a filename containing graph information to populate with.
 * @param  String filename       [File path and extension to graph information]
 * @throws FileNotFoundException [If file does not exist at given path]
 */
public EdgeWeightedGraph(String filename) throws FileNotFoundException
{
        //create file from file name and open scanner for use with said file
        File file = new File(filename);
        Scanner scan = new Scanner(file);
        V = scan.nextInt();
        //if V is negative, throw error
        if(V < 0)
        {
                throw new IllegalArgumentException("Number of vertices in Graph must be nonnegative.");
        }

        //create adjacency vector
        adj = new LinkedList[V];

        //each vertex gets its own adjacency list, so populate
        //adj with adjacency lists
        for(int v = 0; v < V; v++)
        {
                adj[v] = new LinkedList<>();
        }

        E = scan.nextInt();
        //if E is negative, throw error
        if(E < 0)
        {
                throw new IllegalArgumentException("Number of edges in Graph must be nonnegative.");
        }

        //gobble newline
        scan.nextLine();

        //get each edge information from file
        for(int e = 0; e < E; e++)
        {
                //get full line as string from file and split at whitespace
                String[] splitString = scan.nextLine().split(" ");
                int v, w;
                double weight;
                v = Integer.parseInt(splitString[0]);
                w = Integer.parseInt(splitString[1]);
                weight = Double.parseDouble(splitString[2]);
                //validate vertices
                validateVertex(v);
                validateVertex(w);
                //add edges
                addEdge(new Edge(v, w, weight));
        }
}

/**
 * Returns number of vertices in graph
 */
public int V()
{
        return V;
}

/**
 * Returns number of edges in graph.
 */
public int E()
{
        return E;
}

/**
 * Validates vertex falls within given range of vertices.
 * @param  int v    [vertex to verify]
 */
private void validateVertex(int v)
{
        if(v < 0 || v >= V)
        {
                throw new IllegalArgumentException("Vertex: " + v + " is not between 0 and " + (V-1));
        }
}

/**
 * Adds edge information to adjacency list
 * @param  Edge edge      [Edge object to add to adjacency list]
 */
public void addEdge(Edge edge)
{
        adj[edge.getV()].addFirst(edge);
        adj[edge.getW()].addFirst(edge);
}

/**
 * Returns a single vertex's adjacency list
 * @param  int v              [Vertex to get adjacency list for]
 * @return Iterable<Integer> [return LinkedList containing adjacency information]
 */
public Iterable<Edge> adj(int v)
{
        validateVertex(v);
        return adj[v];
}

/**
 * Returns list of all edges in graph
 * @return [Iterable of all Edge objects in graph]
 */
public Iterable<Edge> edges()
{
        LinkedList<Edge> e = new LinkedList<>();
        for(int v = 0; v < V; v++)
        {
                for(Edge edge: adj(v))
                {
                        if(edge.other(v) > v)
                        {
                                e.add(edge);
                        }
                }
        }
        return e;
}
}
