// import java.util.*;


// class Pair<U, V> {
//     private final U first;
//     private final V second;

//     public Pair(U first, V second){
//         this.first = first;
//         this.second = second;
//     }

//     public U getFirst() { return first; }
//     public V getSecond() { return second; }

//     @Override
//     public String toString() {
//         return "(" + first + ", " + second + ")";
//     }
// }


// class Graph {

//     int n, m;
//     ArrayList<ArrayList<Pair<Integer,Integer>>> adj, rev_adj;
//     Stack<Integer> stack;
//     boolean[] vis;
//     int num_component;
//     ArrayList<ArrayList<Integer>> components;

//     Graph() {
//         adj = new ArrayList<>();
//         rev_adj = new ArrayList<>();
//         components = new ArrayList<>();
//         num_component = 0; // Initialize num_component
//     }

//     private void initializeGraph(int n) {
//         adj.clear();
//         rev_adj.clear();
//         components.clear(); // Clear components to avoid duplication
//         for (int i = 0; i < n; i++) {
//             adj.add(new ArrayList<>());
//             rev_adj.add(new ArrayList<>());
//             components.add(new ArrayList<>());
//         }
//         vis = new boolean[n];
//         Arrays.fill(vis, false);
//         stack = new Stack<>();
//     }

//     public void readInput() {
//         Scanner sc = new Scanner(System.in);
//         n = sc.nextInt();
//         m = sc.nextInt();
//         initializeGraph(n);
//         for(int i = 0; i < m; i++){
//             int u, v, w;
//             u = sc.nextInt();
//             v = sc.nextInt();
//             w = sc.nextInt(); // Assuming weight is provided
//             adj.get(u).add(new Pair<>(v, w));
//             rev_adj.get(v).add(new Pair<>(u, w)); // Reverse edge
//         }
//         sc.close(); // It's good practice to close the scanner
//     }

//     void dfs1(int s){
//         vis[s] = true;
//         for(Pair<Integer, Integer> edge : adj.get(s)){
//             int neighbor = edge.getFirst();
//             if(!vis[neighbor]){
//                 dfs1(neighbor);
//             }
//         }
//         stack.push(s);
//     }

//     void dfs2(int s){
//         System.out.print(s + " ");
//         components.get(num_component).add(s);
//         vis[s] = true;
//         for(Pair<Integer, Integer> edge : rev_adj.get(s)){
//             int neighbor = edge.getFirst();
//             if(!vis[neighbor]){
//                 dfs2(neighbor);
//             }
//         }
//     }

//     public void kosaraju_algo(){
//         for(int i = 0; i < n; i++){
//             if(!vis[i]){
//                 dfs1(i);
//             }
//         }
//         Arrays.fill(vis, false); // Reset visited array

//         while(!stack.isEmpty()){
//             int v = stack.pop();
//             if(!vis[v]){
//                 System.out.println("Component " + num_component + ":");
//                 dfs2(v);
//                 System.out.println();
//                 num_component++;
//             }
//         }

//         // Optionally, print all components
//         /*
//         for(int i = 0; i < components.size(); i++) {
//             System.out.println("Component " + i + ": " + components.get(i));
//         }
//         */
//     }
// }

// public class some_magic {
//     public static void main(String[] args) { // Corrected main method signature
//         Graph g = new Graph(); // Renamed to follow Java conventions
//         g.readInput();
//         g.kosaraju_algo();
//     }
// }
