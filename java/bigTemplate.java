import java.io.*;
import java.util.*;

class Graph {

    private ArrayList<ArrayList<Integer>> adjList;
    private int vertices, edges, time;
    private boolean[] visited;
    private int[] startTime, finishTime;
    private Map<String, Integer> nodeMap; 
    private Map<Integer, String> reverseNodeMap; 

    public Graph() {
        adjList = new ArrayList<>();
        nodeMap = new HashMap<>();
        reverseNodeMap = new HashMap<>();
    }

    public void initializeGraph(int vertices) {
        this.vertices = vertices;
        adjList.clear();
        nodeMap.clear();
        reverseNodeMap.clear();
        for (int i = 0; i < vertices; i++) {
            adjList.add(new ArrayList<>());
            String nodeName = String.valueOf((char) ('a' + i));
            nodeMap.put(nodeName, i);
            reverseNodeMap.put(i, nodeName);
        }

        visited = new boolean[vertices];
        startTime = new int[vertices];
        finishTime = new int[vertices];
    }

    public void addEdge(String u, String v) {
        Integer from = nodeMap.get(u);
        Integer to = nodeMap.get(v);
        adjList.get(from).add(to);
    }

    public void readInput(String path) {
        try (BufferedReader br = new BufferedReader(new FileReader(path))) {

            String[] ve = br.readLine().split("\\s+");
            vertices = Integer.parseInt(ve[0]);
            edges = Integer.parseInt(ve[1]);

            initializeGraph(vertices);

            for (int i = 0; i < edges; i++) {
                String[] edge = br.readLine().split("\\s+");
                String u = edge[0];
                String v = edge[1];

                addEdge(u, v);
            }
        } catch (IOException ex) {
            System.err.println("Error Reading File: " + ex.getMessage());
        }
    }

    public void dfsTraversal() {
        Arrays.fill(visited, false);
        time = 0;
        System.out.println("DFS Traversal (using colors):");
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfsUtil(i);
            }
        }
        System.out.println("\nVertex\tStart\tFinish");
        for (int i = 0; i < vertices; i++) {
            System.out.println(reverseNodeMap.get(i) + "\t" + startTime[i] + "\t" + finishTime[i]);
        }
    }

    private void dfsUtil(int v) {
        visited[v] = true;
        startTime[v] = ++time;
        System.out.print(reverseNodeMap.get(v) + " ");
        for (int adj : adjList.get(v)) {
            if (!visited[adj]) {
                dfsUtil(adj);
            }
        }
        finishTime[v] = ++time;
    }

    public ArrayList<ArrayList<Integer>> getAdjList() {
        return adjList;
    }

    public int getVertices() {
        return vertices;
    }

    public String getNodeName(int index) {
        return reverseNodeMap.get(index);
    }

    public int getNodeIndex(String name) {
        return nodeMap.getOrDefault(name, -1);
    }

    public void topologicalSort() {
        Stack<Integer> stack = new Stack<>();
        boolean[] visitedTopo = new boolean[vertices];

        for (int i = 0; i < vertices; i++) {
            if (!visitedTopo[i]) {
                topologicalSortUtil(i, visitedTopo, stack);
            }
        }

        System.out.println("\nTopological Sort:");
        while (!stack.isEmpty()) {
            System.out.print(reverseNodeMap.get(stack.pop()) + " ");
        }
        System.out.println();
    }

    private void topologicalSortUtil(int v, boolean[] visitedTopo, Stack<Integer> stack) {
        visitedTopo[v] = true;
        for (int adj : adjList.get(v)) {
            if (!visitedTopo[adj]) {
                topologicalSortUtil(adj, visitedTopo, stack);
            }
        }
        stack.push(v);
    }
}

class BFS {

    private Graph graph;
    private boolean[] visited;
    private int[] distance, parent;
    private String[] colors; 
    public BFS(Graph g) {
        this.graph = g;
        int v = g.getVertices();
        visited = new boolean[v];
        distance = new int[v];
        parent = new int[v];
        Arrays.fill(parent, -1);
        colors = new String[v];
        Arrays.fill(colors, "WHITE");
    }

    public void bfsTraversal(String startNode) {
        Arrays.fill(visited, false);
        Arrays.fill(distance, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);
        Arrays.fill(colors, "WHITE");

        int s = graph.getNodeIndex(startNode);
        if (s == -1) {
            System.err.println("Start node " + startNode + " does not exist.");
            return;
        }

        bfs(s);
    }

    private void bfs(int s) {
        Queue<Integer> queue = new LinkedList<>();
        visited[s] = true;
        distance[s] = 0;
        colors[s] = "GREY";

        queue.add(s);

        System.out.println("BFS Traversal starting from " + graph.getNodeName(s) + ":");
        while (!queue.isEmpty()) {
            int v = queue.poll();
            colors[v] = "BLACK";
            System.out.print(graph.getNodeName(v) + " ");

            for (int adj : graph.getAdjList().get(v)) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    distance[adj] = distance[v] + 1;
                    parent[adj] = v;
                    colors[adj] = "GREY";
                    queue.add(adj);
                }
            }
        }
        System.out.println();
    }

    public void printDistances(String startNode) {
        int s = graph.getNodeIndex(startNode);
        if (s == -1) {
            System.err.println("Start node " + startNode + " does not exist.");
            return;
        }
        System.out.println("\nVertex\tDistance\tParent");
        for (int i = 0; i < graph.getVertices(); i++) {
            String parentName = parent[i] == -1 ? "NIL" : graph.getNodeName(parent[i]);
            String distanceStr = distance[i] == Integer.MAX_VALUE ? "INF" : String.valueOf(distance[i]);
            System.out.println(graph.getNodeName(i) + "\t" + distanceStr + "\t\t" + parentName);
        }
    }

    // Multi-Source BFS
    public void multiSourceBFS(List<String> sources) {
        Arrays.fill(visited, false);
        Arrays.fill(distance, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);
        Arrays.fill(colors, "WHITE");

        Queue<Integer> queue = new LinkedList<>();

        System.out.print("\nMulti-Source BFS Traversal starting from ");
        for (String src : sources) {
            int s = graph.getNodeIndex(src);
            if (s != -1 && !visited[s]) {
                queue.add(s);
                visited[s] = true;
                distance[s] = 0;
                parent[s] = -1;
                colors[s] = "GREY";
                System.out.print(src + " ");
            }
        }
        System.out.println(":");

        while (!queue.isEmpty()) {
            int v = queue.poll();
            colors[v] = "BLACK";
            System.out.print(graph.getNodeName(v) + " ");

            for (int adj : graph.getAdjList().get(v)) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    distance[adj] = distance[v] + 1;
                    parent[adj] = v;
                    colors[adj] = "GREY";
                    queue.add(adj);
                }
            }
        }
        System.out.println();

        System.out.println("\nVertex\tDistance\tParent");
        for (int i = 0; i < graph.getVertices(); i++) {
            String parentName = parent[i] == -1 ? "NIL" : graph.getNodeName(parent[i]);
            String distanceStr = distance[i] == Integer.MAX_VALUE ? "INF" : String.valueOf(distance[i]);
            System.out.println(graph.getNodeName(i) + "\t" + distanceStr + "\t\t" + parentName);
        }
    }
}

class SCC {
    private Graph graph;
    private Stack<Integer> stack;
    private boolean[] visited;

    public SCC(Graph g) {
        this.graph = g;
        stack = new Stack<>();
        visited = new boolean[g.getVertices()];
    }

    private ArrayList<ArrayList<Integer>> getTranspose() {
        ArrayList<ArrayList<Integer>> transpose = new ArrayList<>();
        int vertices = graph.getVertices();

        for (int i = 0; i < vertices; i++) {
            transpose.add(new ArrayList<>());
        }

        for (int i = 0; i < vertices; i++) {
            for (int j : graph.getAdjList().get(i)) {
                transpose.get(j).add(i);
            }
        }
        return transpose;
    }

    private void fillOrder(int vertex) {
        visited[vertex] = true;

        for (int adj : graph.getAdjList().get(vertex)) {
            if (!visited[adj]) {
                fillOrder(adj);
            }
        }
        stack.push(vertex);
    }

    private void dfsOnTranspose(int vertex, ArrayList<ArrayList<Integer>> transpose) {
        visited[vertex] = true;
        System.out.print(graph.getNodeName(vertex) + " ");

        for (int adj : transpose.get(vertex)) {
            if (!visited[adj]) {
                dfsOnTranspose(adj, transpose);
            }
        }
    }

    public void findSCCs() {
        Arrays.fill(visited, false);

        for (int i = 0; i < graph.getVertices(); i++) {
            if (!visited[i]) {
                fillOrder(i);
            }
        }

        ArrayList<ArrayList<Integer>> transpose = getTranspose();

        Arrays.fill(visited, false);

        System.out.println("\nStrongly Connected Components:");
        while (!stack.empty()) {
            int vertex = stack.pop();
            if (!visited[vertex]) {
                dfsOnTranspose(vertex, transpose);
                System.out.println();
            }
        }
    }
}

class TopologicalSort {
    private Graph graph;

    public TopologicalSort(Graph g) {
        this.graph = g;
    }

    public void performTopologicalSort() {
        graph.topologicalSort();
    }
}

class ShortestPath {
    private Graph graph;
    private int[] distance;
    private int[] parent;

    public ShortestPath(Graph g) {
        this.graph = g;
        int v = g.getVertices();
        distance = new int[v];
        parent = new int[v];
        Arrays.fill(parent, -1);
    }

    public void singleSourceShortestPath(String startNode) {
        Arrays.fill(distance, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);
        boolean[] visited = new boolean[graph.getVertices()];

        int s = graph.getNodeIndex(startNode);
        if (s == -1) {
            System.err.println("Start node " + startNode + " does not exist.");
            return;
        }

        Queue<Integer> queue = new LinkedList<>();
        visited[s] = true;
        distance[s] = 0;
        queue.add(s);

        System.out.println("\nSingle Source Shortest Paths from " + startNode + ":");
        while (!queue.isEmpty()) {
            int u = queue.poll();
            System.out.print(graph.getNodeName(u) + " ");

            for (int adj : graph.getAdjList().get(u)) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    distance[adj] = distance[u] + 1;
                    parent[adj] = u;
                    queue.add(adj);
                }
            }
        }
        System.out.println();

        printShortestPaths(startNode);
    }

    private void printShortestPaths(String startNode) {
        System.out.println("\nVertex\tDistance\tPath");
        for (int i = 0; i < graph.getVertices(); i++) {
            if (distance[i] == Integer.MAX_VALUE) {
                System.out.println(graph.getNodeName(i) + "\tINF\t\tNo Path");
            } else {
                System.out.print(graph.getNodeName(i) + "\t" + distance[i] + "\t\t");
                printPath(i);
                System.out.println();
            }
        }
    }

    private void printPath(int vertex) {
        if (parent[vertex] == -1) {
            System.out.print(graph.getNodeName(vertex));
            return;
        }
        printPath(parent[vertex]);
        System.out.print(" -> " + graph.getNodeName(vertex));
    }

    public void multiSourceShortestPath(List<String> sources) {
        Arrays.fill(distance, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);
        boolean[] visited = new boolean[graph.getVertices()];

        Queue<Integer> queue = new LinkedList<>();

        System.out.print("\nMulti-Source Shortest Paths starting from ");
        for (String src : sources) {
            int s = graph.getNodeIndex(src);
            if (s != -1 && !visited[s]) {
                queue.add(s);
                visited[s] = true;
                distance[s] = 0;
                parent[s] = -1;
                System.out.print(src + " ");
            }
        }
        System.out.println(":");

        while (!queue.isEmpty()) {
            int u = queue.poll();
            System.out.print(graph.getNodeName(u) + " ");

            for (int adj : graph.getAdjList().get(u)) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    distance[adj] = distance[u] + 1;
                    parent[adj] = u;
                    queue.add(adj);
                }
            }
        }
        System.out.println();

        printMultiSourceShortestPaths();
    }

    private void printMultiSourceShortestPaths() {
        System.out.println("\nVertex\tDistance\tPath");
        for (int i = 0; i < graph.getVertices(); i++) {
            if (distance[i] == Integer.MAX_VALUE) {
                System.out.println(graph.getNodeName(i) + "\tINF\t\tNo Path");
            } else {
                System.out.print(graph.getNodeName(i) + "\t" + distance[i] + "\t\t");
                printPath(i);
                System.out.println();
            }
        }
    }
}

public class bigTemplate {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the input file path: ");
        String path = sc.nextLine();

        Graph graph = new Graph();
        graph.readInput(path);

        System.out.println("\nDFS Traversal:");
        graph.dfsTraversal();

        System.out.print("\nEnter the start node for BFS (e.g., a): ");
        String bfsStart = sc.nextLine();
        BFS bfs = new BFS(graph);
        bfs.bfsTraversal(bfsStart);
        bfs.printDistances(bfsStart);

        System.out.print("\nEnter the start nodes for Multi-Source BFS separated by space (e.g., a c): ");
        String[] multiSources = sc.nextLine().split("\\s+");
        List<String> multiSourceList = Arrays.asList(multiSources);
        bfs.multiSourceBFS(multiSourceList);

        TopologicalSort topoSort = new TopologicalSort(graph);
        topoSort.performTopologicalSort();

        ShortestPath sp = new ShortestPath(graph);
        System.out.print("\nEnter the start node for Single Source Shortest Path (e.g., a): ");
        String spStart = sc.nextLine();
        sp.singleSourceShortestPath(spStart);

        System.out.print("\nEnter the start nodes for Multi-Source Shortest Path separated by space (e.g., a c): ");
        String[] multiSpSources = sc.nextLine().split("\\s+");
        List<String> multiSpSourceList = Arrays.asList(multiSpSources);
        sp.multiSourceShortestPath(multiSpSourceList);

        SCC scc = new SCC(graph);
        scc.findSCCs();

        sc.close();
    }
}
