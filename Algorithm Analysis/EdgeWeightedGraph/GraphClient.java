/**
 * GraphClient
 * Paige Eckstein
 * Algorithm Analysis
 *
 * No Dependencies.
 * To test Graph.java
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
 */
import java.io.FileNotFoundException;

public class GraphClient {


//test client
public static void main(String[] args) throws FileNotFoundException
{

        EdgeWeightedGraph G = new EdgeWeightedGraph(args[0]);
        System.out.println(G.V() + " vertices, " + G.E() + " edges.");
        for(int i = 0; i < G.V(); i++)
        {
                System.out.println(i + ": " + G.adj(i).toString() + ", ");
        }
        System.out.println();

}

}
