/**
 * Graph class
 * Paige Eckstein
 * Algorithm Analysis
 *
 * Dependencies: Graph.java
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
import java.io.FileNotFoundException;

public class GraphClient {

// degree of v
public static int degree(Graph G, int v) {

        int degree = 0;
        for (Integer w : G.adj(v)) degree++;
        return degree;

}

// maximum degree
public static int maxDegree(Graph G) {

        int max = 0;
        for (int v = 0; v < G.V(); v++)
                if (degree(G, v) > max)
                        max = degree(G, v);
        return max;

}

//average degree
//A measure of how many edges are in set E compared to number of vertices in set V
public static int averageDegree(Graph G)
{
        return 2 * G.E() / G.V();
}

//counts number of self loops in Graph
public static int selfLoops(Graph G)
{
        int loops = 0;
        for(int v = 0; v < G.V(); v++)
        {
                for(int w : G.adj(v))
                {
                        if(v == w)
                        {
                                loops++;
                        }
                }
        }
        return loops;
}


//test client
public static void main(String[] args) throws FileNotFoundException
{

        Graph G = new Graph(args[0]);
        System.out.println(G.V() + " vertices, " + G.E() + " edges.");
        for(int i = 0; i < G.V(); i++)
        {
                System.out.println(i + ": " + G.adj(i));
        }
        System.out.println();
        System.out.println("vertex of maximum degree = " + maxDegree(G));
        System.out.println("Average degree: " + averageDegree(G));
        System.out.println("Self Loops: " + selfLoops(G));

}

}
