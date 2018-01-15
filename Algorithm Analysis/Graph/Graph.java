/**
 * Graph class
 * Paige Eckstein
 * Algorithm Analysis
 *
 * No Dependencies.
 * To be tested with GraphClient.java
 *
 * Graph class represents an undirected graph. It holds information
 * on the graph's vertices and edges.
 * Also contains a LinkedList called adj that contains
 * the graph's adjacency list information.
 *
 * To be used with file containing graph information in the format:
 * V x
 * E x
 * ATL HOUS 0 1
 * etc.
 * to represent airline connections.
 *
 * Or in format:
 * x1
 * x2
 * y1 y2
 * etc.
 * to represent graph information, where x1 is number of Vertices
 * x2 is number of edges, and y1 y2 is the connection information
 *
 * Output:
 * x vertices, y edges.
 * vertex: [adjacency list]
 *
 * vertex of maximum degree = x
 * Average degree = y
 * Self loops = z
 *
 * Example use:
 * java GraphClient testFile.txt
 *
 */
import java.util.LinkedList;
import java.util.Scanner;

import java.io.File;
import java.io.FileNotFoundException;

class Graph
{
//Vertices
private int V;
//Edges
private int E;
//Adjacency List
LinkedList<Integer> adj[];

/**
 * Constructor to create empty Graph
 * @param  int V       [Number of vertices in Graph]
 */
public Graph(int V)
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
public Graph(String filename) throws FileNotFoundException
{
        //create file from file name and open scanner for use with said file
        File file = new File(filename);
        Scanner scan = new Scanner(file);
        String[] vLine = scan.nextLine().split("\\s");

        //if first line in input is V x, where x is the number of vertices
        //split to get just x
        //then set this.V = x
        if(vLine[0].equals("V"))
        {
                this.V = Integer.parseInt(vLine[1]);
        }
        //if first line in input is x,
        //then set this.V = x
        else
        {
                this.V = Integer.parseInt(vLine[0]);
        }
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

        String[] eLine = scan.nextLine().split("\\s");
        //if next line in input is E x, where x is the number of edges
        //split to get just x
        //then set this.E = x
        if(eLine[0].equals("E"))
        {
                this.E = Integer.parseInt(eLine[1]);
        }
        //if next line in input x2, where x2 is the number of edges
        else
        {
                this.E = Integer.parseInt(eLine[0]);
        }
        //if E is negative, throw error
        if(E < 0)
        {
                throw new IllegalArgumentException("Number of edges in Graph must be nonnegative.");
        }

        //get each edge information from file
        for(int e = 0; e < E; e++)
        {
                //get full line as string from file and split at whitespace
                String[] temp = scan.nextLine().split("\\s");
                //edge information are last two numbers, so grab from
                //split string and convert to integers

                int v, w;
                //if file has format:
                // ATL HOU 0 1
                // Where first two strings represent airports
                // and last two integers represent edge information
                if(eLine[0].equals("E"))
                {
                        v = Integer.parseInt(temp[2]);
                        w = Integer.parseInt(temp[3]);
                }
                //if file has format:
                // y1 y2
                // where y1 and y2 are connection information as integers
                else
                {
                        v = Integer.parseInt(temp[0]);
                        w = Integer.parseInt(temp[1]);
                }
                //validate vertices
                validateVertex(v);
                validateVertex(w);
                //add edges
                addEdge(v, w);
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
 * @param  int v       [Vertex to connect]
 * @param  int w       [Vertex to connect]
 */
public void addEdge(int v, int w)
{
        //valide both vertices before continuing
        validateVertex(v);
        validateVertex(w);

        //because graph is undirected, add each vertex to the other's
        //adjacency list
        adj[v].addFirst(w);
        adj[w].addFirst(v);
}

/**
 * Returns a single vertex's adjacency list
 * @param  int v              [Vertex to get adjacency list for]
 * @return Iterable<Integer> [return LinkedList containing adjacency information]
 */
public Iterable<Integer> adj(int v)
{
        validateVertex(v);
        return adj[v];
}

/**
 * Returns degree of a given vertex
 * @param  int v        [Vertex to get degree of]
 * @return int          [Degree of given vertex]
 */
public int degree(int v)
{
        validateVertex(v);
        //size of adjacency list = degree of vertex
        return adj[v].size();
}
}
