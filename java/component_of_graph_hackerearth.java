import java.io.*;
import java.util.*;

class Graph {

    private ArrayList<ArrayList<Integer>> adjList;
    private ArrayList<ArrayList<Integer>> reverseAdjList;
    private int vertices;
    private int[] nodeValues;
    private boolean[] included;

    public Graph(int vertices) {
        this.vertices = vertices;
        adjList = new ArrayList<>();
        reverseAdjList = new ArrayList<>();
        for (int i = 0; i <= vertices; i++) {
            adjList.add(new ArrayList<>());
            reverseAdjList.add(new ArrayList<>());
        }
    }

    public void setNodeValues(int[] nodeValues) {
        this.nodeValues = nodeValues;
    }

    public void setIncluded(boolean[] included) {
        this.included = included;
    }

    public void addEdge(int u, int v) {
        adjList.get(u).add(v);
        reverseAdjList.get(v).add(u);
    }

    public ArrayList<ArrayList<Integer>> getAdjList() {
        return adjList;
    }

    public ArrayList<ArrayList<Integer>> getReverseAdjList() {
        return reverseAdjList;
    }

    public int getVertices() {
        return vertices;
    }

    public boolean[] getIncluded() {
        return included;
    }

    public void resetAdjList() {
        for (int i = 0; i <= vertices; i++) {
            adjList.get(i).clear();
            reverseAdjList.get(i).clear();
        }
    }
}

class SCC {
    private Graph graph;
    private Stack<Integer> stack;
    private boolean[] visited;
    private List<Integer> currentSCC;
    private int sccMaxSize;

    public SCC(Graph g) {
        this.graph = g;
        int vertices = g.getVertices();
        stack = new Stack<>();
        visited = new boolean[vertices + 1];
        currentSCC = new ArrayList<>();
        sccMaxSize = 0;
    }

    public int getSccMaxSize() {
        return sccMaxSize;
    }

    public void resetVisited() {
        Arrays.fill(visited, false);
        stack.clear();
    }

    public void findSCCs() {
        boolean[] included = graph.getIncluded();
        Arrays.fill(visited, false);

        for (int i = 1; i <= graph.getVertices(); i++) {
            if (included[i] && !visited[i]) {
                fillOrderIterative(i);
            }
        }

        Arrays.fill(visited, false);

        while (!stack.isEmpty()) {
            int v = stack.pop();
            if (!visited[v]) {
                currentSCC.clear();
                dfsOnTransposeIterative(v);
                if (currentSCC.size() > sccMaxSize) {
                    sccMaxSize = currentSCC.size();
                }
            }
        }
    }

    private void fillOrderIterative(int startVertex) {
        Stack<Integer> dfsStack = new Stack<>();
        dfsStack.push(startVertex);

        while (!dfsStack.isEmpty()) {
            int vertex = dfsStack.peek();
            if (!visited[vertex]) {
                visited[vertex] = true;
            }
            boolean hasUnvisitedChild = false;
            for (int adj : graph.getAdjList().get(vertex)) {
                if (graph.getIncluded()[adj] && !visited[adj]) {
                    dfsStack.push(adj);
                    hasUnvisitedChild = true;
                    break;
                }
            }
            if (!hasUnvisitedChild) {
                dfsStack.pop();
                stack.push(vertex);
            }
        }
    }

    private void dfsOnTransposeIterative(int startVertex) {
        Stack<Integer> dfsStack = new Stack<>();
        dfsStack.push(startVertex);

        while (!dfsStack.isEmpty()) {
            int vertex = dfsStack.pop();
            if (!visited[vertex]) {
                visited[vertex] = true;
                currentSCC.add(vertex);
                for (int adj : graph.getReverseAdjList().get(vertex)) {
                    if (graph.getIncluded()[adj] && !visited[adj]) {
                        dfsStack.push(adj);
                    }
                }
            }
        }
    }
}

public class component_of_graph_hackerearth {
    public static void main(String[] args) throws IOException {
        // Read input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nmk = br.readLine().split("\\s+");
        int N = Integer.parseInt(nmk[0]);
        int M = Integer.parseInt(nmk[1]);
        int K = Integer.parseInt(nmk[2]);

        int[] nodeValues = new int[N + 1];
        String[] values = br.readLine().split("\\s+");
        Set<Integer> uniqueValuesSet = new HashSet<>();
        for (int i = 1; i <= N; i++) {
            nodeValues[i] = Integer.parseInt(values[i - 1]);
            uniqueValuesSet.add(nodeValues[i]);
        }

        // Read edges
        int[][] edges = new int[M][2];
        for (int i = 0; i < M; i++) {
            String[] uv = br.readLine().split("\\s+");
            int u = Integer.parseInt(uv[0]);
            int v = Integer.parseInt(uv[1]);
            edges[i][0] = u;
            edges[i][1] = v;
        }

        // Collect unique node values and sort them
        List<Integer> uniqueValuesList = new ArrayList<>(uniqueValuesSet);
        Collections.sort(uniqueValuesList);

        // Binary search over the unique node values
        int left = 0;
        int right = uniqueValuesList.size() - 1;
        int answer = uniqueValuesList.get(0);

        while (left <= right) {
            int mid = (left + right) / 2;
            int X = uniqueValuesList.get(mid);

            // Build subgraph
            boolean[] included = new boolean[N + 1];
            for (int i = 1; i <= N; i++) {
                if (nodeValues[i] >= X) {
                    included[i] = true;
                }
            }

            Graph graph = new Graph(N);
            graph.setNodeValues(nodeValues);
            graph.setIncluded(included);

            // Add edges to the graph
            for (int i = 0; i < M; i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                if (included[u] && included[v]) {
                    graph.addEdge(u, v);
                }
            }

            // Run SCC algorithm
            SCC scc = new SCC(graph);
            scc.findSCCs();
            int maxSCCSize = scc.getSccMaxSize();

            if (maxSCCSize >= K) {
                // Current X is valid, try higher X
                answer = X;
                left = mid + 1;
            } else {
                // Current X is invalid, try lower X
                right = mid - 1;
            }
        }

        System.out.println(answer);
    }
}
