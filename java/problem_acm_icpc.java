/*
 *You are on an n x m grid where each square on the grid has a digit on it. From a given square that has digit k
 on it, a Move consists of jumping exactly k
 squares in one of the four cardinal directions. A move cannot go beyond the edges of the grid; it does not wrap. What is the minimum number of moves required to get from the top-left corner to the bottom-right corner?

Input
Each input will consist of a single test case. Note that your program may be run multiple times on different inputs. The first line of input contains two space-separated integers m and n ( 1<= n,m<=500), indicating the size of the grid. It is guaranteed that at least one of m
 and n
 is greater than 1.
.

The next n
 lines will each consist of m
 digits, with no spaces, indicating the 
 grid. Each digit is between 0 and 9, inclusive.

The top-left corner of the grid will be the square corresponding to the first character in the first line of the test case. The bottom-right corner of the grid will be the square corresponding to the last character in the last line of the test case.

Output
Output a single integer on a line by itself representing the minimum number of moves required to get from the top-left corner of the grid to the bottom-right. If it isn’t possible, output -1.

Sample Input 1	
2 2
11
11
Sample Output 1
2
Sample Input 2	
2 2
22
22
Sample Output 2
-1
Sample Input 3	
5 4
2120
1203
3113
1120
1110
Sample Output 3 
6
 */


 import java.util.*;

class Graph {
    int verticeNo;
    int edgeNo;
    LinkedList<LinkedList<Integer>> adjacencyList;

    Graph() {
        adjacencyList = new LinkedList<>();
    }

    public void initializeGraph(int vertices, int edges) {
        this.verticeNo = vertices;
        this.edgeNo = edges;
        adjacencyList.clear();
        for (int i = 0; i < vertices; i++) {
            adjacencyList.add(new LinkedList<>());
        }
    }

    public void addEdge(int u, int v) {
        if (u < 0 || u >= this.verticeNo || v < 0 || v >= this.verticeNo) {
            // System.err.println("Invalid edge: " + u + " -> " + v);
            return;
        }
        adjacencyList.get(u).add(v);
    }

    public void displayGraph() {
        for (int i = 0; i < verticeNo; i++) {
            System.out.print("Vertex " + i + ": "); // 0-based indexing
            for (Integer neighbor : adjacencyList.get(i)) {
                System.out.print(neighbor + " ");  // 0-based indexing
            }
            System.out.println();
        }
    }
}

class BFSandDFS {
    Graph g;
    String[] color;
    int[] prev, distance;
    int inf = 1000000;
    List<Integer> discoveryOrder = new ArrayList<>();  // To store the order of discovery

    BFSandDFS(Graph graph) {
        this.g = graph;
        this.color = new String[this.g.verticeNo];
        this.prev = new int[this.g.verticeNo];
        this.distance = new int[this.g.verticeNo];
    }

    public void startBFS(int startVer) {
        discoveryOrder.clear();
        for (int i = 0; i < this.g.verticeNo; i++) {
            color[i] = "WHITE";
            prev[i] = -1;
            distance[i] = inf;
        }
        color[startVer] = "GRAY";
        distance[startVer] = 0;
        prev[startVer] = -1;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(startVer);
        discoveryOrder.add(startVer);
        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : this.g.adjacencyList.get(u)) {
                if (color[v].equals("WHITE")) {
                    color[v] = "GRAY";
                    distance[v] = distance[u] + 1;
                    prev[v] = u;
                    queue.add(v);
                    discoveryOrder.add(v);
                }
            }
            color[u] = "BLACK";
        }
    }
}

public class problem_acm_icpc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt(); // Number of columns
        int n = sc.nextInt(); // Number of rows
        sc.nextLine(); // Consume the rest of the line

        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();
            for (int j = 0; j < m; j++) {
                grid[i][j] = line.charAt(j) - '0';
            }
        }

        int totalVertices = n * m;
        Graph g = new Graph();
        g.initializeGraph(totalVertices, 0);

        // Build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int k = grid[i][j];
                if (k == 0) {
                    continue; // Cannot move from a cell with 0
                }
                int u = i * m + j; // Convert 2D index to 1D

                // Up
                if (i - k >= 0) {
                    int v = (i - k) * m + j;
                    g.addEdge(u, v);
                }
                // Down
                if (i + k < n) {
                    int v = (i + k) * m + j;
                    g.addEdge(u, v);
                }
                // Left
                if (j - k >= 0) {
                    int v = i * m + (j - k);
                    g.addEdge(u, v);
                }
                // Right
                if (j + k < m) {
                    int v = i * m + (j + k);
                    g.addEdge(u, v);
                }
            }
        }

        // Perform BFS
        BFSandDFS bfs = new BFSandDFS(g);
        int startVertex = 0; // Top-left corner
        int endVertex = totalVertices - 1; // Bottom-right corner

        bfs.startBFS(startVertex);

        if (bfs.distance[endVertex] != bfs.inf) {
            System.out.println(bfs.distance[endVertex]);
        } else {
            System.out.println("-1");
        }

        sc.close();
    }
}
