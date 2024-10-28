public import java.io.*;
import java.util.*;

class Brick {
    int id;
    int x1, y1, x2, y2;

    public Brick(int id, int x1, int y1, int x2, int y2) {
        this.id = id;
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }
}

class DSU {
    int[] parent;

    public DSU(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public void union(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            parent[fx] = fy;
        }
    }
}

public class lego {
    public static void main(String[] args) throws IOException {
        // For faster input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        List<Brick> bricks = new ArrayList<>(N);

        Map<Integer, List<Brick>> bottomsAtY = new HashMap<>();
        Map<Integer, List<Brick>> topsAtY = new HashMap<>();

        DSU dsu = new DSU(N);

        for (int i = 0; i < N; i++) {
            String[] tokens = br.readLine().split(" ");
            int x1 = Integer.parseInt(tokens[0]);
            int y1 = Integer.parseInt(tokens[1]);
            int x2 = Integer.parseInt(tokens[2]);
            int y2 = Integer.parseInt(tokens[3]);

            Brick brick = new Brick(i, x1, y1, x2, y2);
            bricks.add(brick);

            // Add brick to the list of bricks with bottoms at y1
            bottomsAtY.computeIfAbsent(y1, k -> new ArrayList<>()).add(brick);
            // Add brick to the list of bricks with tops at y2
            topsAtY.computeIfAbsent(y2, k -> new ArrayList<>()).add(brick);
        }

        // Collect all unique y-coordinates where events happen
        Set<Integer> yCoords = new HashSet<>();
        yCoords.addAll(bottomsAtY.keySet());
        yCoords.addAll(topsAtY.keySet());

        for (Integer y : yCoords) {
            List<Brick> bottoms = bottomsAtY.getOrDefault(y, new ArrayList<>());
            List<Brick> tops = topsAtY.getOrDefault(y, new ArrayList<>());

            if (bottoms.isEmpty() || tops.isEmpty())
                continue;

            // Sort both lists by x1 coordinate
            bottoms.sort(Comparator.comparingInt(b -> b.x1));
            tops.sort(Comparator.comparingInt(b -> b.x1));

            int i = 0, j = 0;
            while (i < bottoms.size() && j < tops.size()) {
                Brick bottomBrick = bottoms.get(i);
                Brick topBrick = tops.get(j);

                // Check if the x-intervals overlap
                if (bottomBrick.x2 <= topBrick.x1) {
                    i++;
                } else if (topBrick.x2 <= bottomBrick.x1) {
                    j++;
                } else {
                    // Overlap exists, so union the bricks
                    dsu.union(bottomBrick.id, topBrick.id);
                    // Move pointers
                    if (bottomBrick.x2 < topBrick.x2) {
                        i++;
                    } else {
                        j++;
                    }
                }
            }
        }

        // Count the number of unique parents to find the number of connected components
        Set<Integer> components = new HashSet<>();
        for (int i = 0; i < N; i++) {
            components.add(dsu.find(i));
        }

        // Output the number of separate pieces
        System.out.println(components.size());
    }
}
 {
    
}
