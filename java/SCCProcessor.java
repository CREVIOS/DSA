import java.io.*;
import java.util.*;

class Graph {
    private Map<String, List<String>> adjList;
    private Set<String> nodes;

    public Graph() {
        adjList = new HashMap<>();
        nodes = new HashSet<>();
    }

    public void addNode(String node) {
        nodes.add(node);
        adjList.putIfAbsent(node, new ArrayList<>());
    }

    public void addEdge(String from, String to) {
        if (!nodes.contains(from) || !nodes.contains(to)) {
            System.err.println("Invalid edge: " + from + " -> " + to);
            return;
        }
        adjList.get(from).add(to);
    }

    public static Graph readGraphFromFile(String filePath) {
        Graph graph = new Graph();
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;
            line = br.readLine();
            if (line == null) {
                throw new IOException("Invalid file format: Missing number of nodes.");
            }
            int numNodes = Integer.parseInt(line.trim());


            line = br.readLine();
            if (line == null) {
                throw new IOException("Invalid file format: Missing node names.");
            }
            String[] nodeNames = line.trim().split("\\s+");
            if (nodeNames.length != numNodes) {
                throw new IOException("Number of node names does not match the specified count.");
            }
            for (String node : nodeNames) {
                graph.addNode(node);
            }
            line = br.readLine();
            if (line == null) {
                throw new IOException("Invalid file format: Missing number of edges.");
            }
            int numEdges = Integer.parseInt(line.trim());

            for (int i = 0; i < numEdges; i++) {
                line = br.readLine();
                if (line == null) {
                    throw new IOException("Invalid file format: Missing edge definitions.");
                }
                String[] parts = line.trim().split("\\s+");
                if (parts.length != 2) {
                    throw new IOException("Invalid edge format: " + line);
                }
                graph.addEdge(parts[0], parts[1]);
            }
        } catch (IOException ex) {
            System.err.println("Error reading file '" + filePath + "': " + ex.getMessage());
            return null;
        }
        return graph;
    }


    public boolean hasCycle() {
        Set<String> whiteSet = new HashSet<>(nodes); 
        Set<String> graySet = new HashSet<>(); 
        Set<String> blackSet = new HashSet<>(); 

        while (!whiteSet.isEmpty()) {
            String current = whiteSet.iterator().next();
            if (dfsCycleDetect(current, whiteSet, graySet, blackSet)) {
                return true;
            }
        }
        return false;
    }

    private boolean dfsCycleDetect(String node, Set<String> whiteSet, Set<String> graySet, Set<String> blackSet) {
        moveNode(node, whiteSet, graySet);
        for (String neighbor : adjList.getOrDefault(node, new ArrayList<>())) {
            if (blackSet.contains(neighbor)) {
                continue;
            }
            if (graySet.contains(neighbor)) {
                return true; 
            }
            if (dfsCycleDetect(neighbor, whiteSet, graySet, blackSet)) {
                return true;
            }
        }
        moveNode(node, graySet, blackSet);
        return false;
    }

    private void moveNode(String node, Set<String> sourceSet, Set<String> destinationSet) {
        sourceSet.remove(node);
        destinationSet.add(node);
    }

    public List<String> topologicalSort() {
        Stack<String> stack = new Stack<>();
        Set<String> visited = new HashSet<>();

        for (String node : nodes) {
            if (!visited.contains(node)) {
                topologicalSortUtil(node, visited, stack);
            }
        }

        List<String> topoOrder = new ArrayList<>();
        while (!stack.isEmpty()) {
            topoOrder.add(stack.pop());
        }
        return topoOrder;
    }

    private void topologicalSortUtil(String node, Set<String> visited, Stack<String> stack) {
        visited.add(node);
        for (String neighbor : adjList.getOrDefault(node, new ArrayList<>())) {
            if (!visited.contains(neighbor)) {
                topologicalSortUtil(neighbor, visited, stack);
            }
        }
        stack.push(node);
    }

    public void display() {
        for (String node : nodes) {
            System.out.print(node + " -> ");
            for (String neighbor : adjList.get(node)) {
                System.out.print(neighbor + " ");
            }
            System.out.println();
        }
    }
}

public class SCCProcessor {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of SCCs: ");
        int numSCCs = 0;
        try {
            numSCCs = Integer.parseInt(scanner.nextLine().trim());
            if (numSCCs <= 0) {
                System.err.println("Number of SCCs must be positive.");
                scanner.close();
                return;
            }
        } catch (NumberFormatException ex) {
            System.err.println("Invalid number format.");
            scanner.close();
            return;
        }

        List<String> sccFiles = new ArrayList<>();
        for (int i = 1; i <= numSCCs; i++) {
            System.out.print("Enter the file path for SCC " + i + ": ");
            String filePath = scanner.nextLine().trim();
            sccFiles.add(filePath);
        }

        for (int i = 0; i < numSCCs; i++) {
            String filePath = sccFiles.get(i);
            System.out.println("\nProcessing SCC " + (i + 1) + " from file: " + filePath);
            Graph graph = Graph.readGraphFromFile(filePath);
            if (graph == null) {
                System.err.println("Skipping SCC " + (i + 1) + " due to errors.");
                continue;
            }

            // Optional: Display the graph
            // System.out.println("Graph:");
            // graph.display();

            boolean hasCycle = graph.hasCycle();
            if (hasCycle) {
                System.out.println("SCC " + (i + 1) + " contains a cycle.");
            } else {
                System.out.println("SCC " + (i + 1) + " is acyclic.");
                List<String> topoOrder = graph.topologicalSort();
                System.out.println("Topological Sort of SCC " + (i + 1) + ": " + String.join(" -> ", topoOrder));
            }
        }

        scanner.close();
    }
}



/*

// read the scc component from file a.txt b.txt ...., first will take the number of scc, then will read the scc's , then will check it there is cycle, their topological sort for individial scc
 
// a.txt
3
a b c
2
a b
b c

// b.txt

3
x y z
3
x y
y z
z x



// c.txt


1
m
0




// sample interaction

Enter the number of SCCs: 3
Enter the file path for SCC 1: a.txt
Enter the file path for SCC 2: b.txt
Enter the file path for SCC 3: c.txt

Processing SCC 1 from file: a.txt
SCC 1 is acyclic.
Topological Sort of SCC 1: a -> b -> c

Processing SCC 2 from file: b.txt
SCC 2 contains a cycle.

Processing SCC 3 from file: c.txt
SCC 3 is acyclic.
Topological Sort of SCC 3: m


 */