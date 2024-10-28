// import java.io.*;
// import java.util.*;

// class Graph {

//     private ArrayList<ArrayList<Integer>> adjList;
//     private int vertices, edges, time;
//     private boolean[] visited;
//     private int[] startTime, finishTime;

//     public Graph() {
//         adjList = new ArrayList<>();
//     }

//     public void initializeGraph(int vertices) {
//         this.vertices = vertices;
//         adjList.clear();
//         for (int i = 0; i < vertices; i++) {
//             adjList.add(new ArrayList<>());
//         }

//         visited = new boolean[vertices];
//         startTime = new int[vertices];
//         finishTime = new int[vertices];
//     }

//     public void addEdge(int u, int v) {
//         if (u < 0 || u >= this.vertices || v < 0 || v >= this.vertices) {
//             System.err.println("Invalid edge: " + u + " -> " + v);
//             return;
//         }
//         adjList.get(u).add(v);
//     }

//     public void readInput(String path) {
//         try (BufferedReader br = new BufferedReader(new FileReader(path))) {

//             String[] ve = br.readLine().split(" ");
//             vertices = Integer.parseInt(ve[0]);
//             edges = Integer.parseInt(ve[1]);

//             initializeGraph(vertices);

//             for (int i = 0; i < edges; i++) {
//                 String[] edge = br.readLine().split(" ");
//                 int u = Integer.parseInt(edge[0]);
//                 int v = Integer.parseInt(edge[1]);

//                 addEdge(u, v);
//             }
//         } catch (IOException ex) {
//             System.err.println("Error Reading File: " + ex.getMessage());
//         }
//     }

//     public void dfsTraversal() {
//         Arrays.fill(visited, false);
//         time = 0;
//         System.out.println("DFS traversal:");
//         for (int i = 0; i < vertices; i++) {
//             if (!visited[i]) {
//                 dfsUtil(i);
//             }
//         }
//         System.out.println("\nVertex\tStart\tFinish");
//         for (int i = 0; i < vertices; i++) {
//             System.out.println(i + "\t" + startTime[i] + "\t" + finishTime[i]);
//         }
//     }

//     private void dfsUtil(int v) {
//         visited[v] = true;
//         startTime[v] = ++time;
//         System.out.print(v + " ");
//         for (int adj : adjList.get(v)) {
//             if (!visited[adj]) {
//                 dfsUtil(adj);
//             }
//         }
//         finishTime[v] = ++time;
//     }

//     public int getVertices() {
//         return vertices;
//     }

//     public ArrayList<ArrayList<Integer>> getAdjList() {
//         return adjList;
//     }

// }

// class BFS {

//     private Graph graph;
//     private boolean[] visited;
//     private int[] distance, parent;

//     public BFS(Graph g) {
//         this.graph = g;
//         int v = g.getVertices();
//         visited = new boolean[v];
//         distance = new int[v];
//         parent = new int[v];
//         Arrays.fill(parent, -1);
//     }

//     public void bfsTraversal() {
//         Arrays.fill(visited, false);
//         Arrays.fill(distance, Integer.MAX_VALUE);

//         for (int s = 0; s < graph.getVertices(); s++) {
//             if (!visited[s]) {
//                 bfs(s);
//             }
//         }
//     }

//     private void bfs(int s) {
//         Queue<Integer> queue = new LinkedList<>();
//         visited[s] = true;
//         distance[s] = 0;

//         queue.add(s);

//         while (!queue.isEmpty()) {
//             int v = queue.poll();
//             System.out.print(v + " ");

//             for (int adj : graph.getAdjList().get(v)) {
//                 if (!visited[adj]) {
//                     visited[adj] = true;
//                     distance[adj] = distance[v] + 1;
//                     parent[adj] = v;
//                     queue.add(adj);
//                 }
//             }
//         }
//     }

//     public void printDistances() {
//         System.out.println("\nVertex\tDistance\tParent");
//         for (int i = 0; i < graph.getVertices(); i++) {
//             System.out.println(i + "\t" + distance[i] + "\t\t" + parent[i]);
//         }
//     }

// }

// class SCC {
//     private Graph graph;
//     private Stack<Integer> stack;
//     private boolean[] visited;

//     public SCC(Graph g) {
//         this.graph = g;
//         stack = new Stack<>();
//         visited = new boolean[g.getVertices()];
//     }

//     private ArrayList<ArrayList<Integer>> getTranspose() {
//         ArrayList<ArrayList<Integer>> transpose = new ArrayList<>();
//         int vertices = graph.getVertices();

//         for (int i = 0; i < vertices; i++) {
//             transpose.add(new ArrayList<>());
//         }

//         for (int i = 0; i < vertices; i++) {
//             for (int j : graph.getAdjList().get(i)) {
//                 transpose.get(j).add(i);
//             }
//         }
//         return transpose;
//     }

//     private void fillOrder(int vertex) {
//         visited[vertex] = true;

//         for (int adj : graph.getAdjList().get(vertex)) {
//             if (!visited[adj]) {
//                 fillOrder(adj);
//             }
//         }
//         stack.push(vertex);
//     }

//     private void dfsOnTranspose(int vertex, ArrayList<ArrayList<Integer>> transpose) {
//         visited[vertex] = true;
//         System.out.print(vertex + " ");

//         for (int adj : transpose.get(vertex)) {
//             if (!visited[adj]) {
//                 dfsOnTranspose(adj, transpose);
//             }
//         }
//     }

//     public void findSCCs() {
//         Arrays.fill(visited, false);

//         for (int i = 0; i < graph.getVertices(); i++) {
//             if (!visited[i]) {
//                 fillOrder(i);
//             }
//         }

//         ArrayList<ArrayList<Integer>> transpose = getTranspose();

//         Arrays.fill(visited, false);

//         System.out.println("Strongly Connected Components:");
//         while (!stack.empty()) {
//             int vertex = stack.pop();
//             if (!visited[vertex]) {
//                 dfsOnTranspose(vertex, transpose);
//                 System.out.println();
//             }
//         }
//     }
// }

// public class GraphAlgorithms {
//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         System.out.print("Enter the input file path: ");
//         String path = sc.nextLine();

//         Graph graph = new Graph();
//         graph.readInput(path);

//         // Perform DFS with start/finish times
//         System.out.println("\nDFS Traversal:");
//         graph.dfsTraversal();

//         // Perform BFS
//         System.out.println("\nBFS Traversal:");
//         BFS bfs = new BFS(graph);
//         bfs.bfsTraversal();
//         bfs.printDistances();

//         // Find Strongly Connected Components
//         System.out.println("\nStrongly Connected Components:");
//         SCC scc = new SCC(graph);
//         scc.findSCCs();

//         sc.close();
//     }
// }

