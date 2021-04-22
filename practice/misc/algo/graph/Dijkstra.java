import java.util.*;
import java.util.stream.Collectors;

class Vertex {
    int distance;
    String parent;
    Vertex(){
        distance = Integer.MAX_VALUE;
        parent = "";
    } 
}

public class Dijkstra implements Comparator<String> {
    Map<String, Map<String, Integer>> graph;
    Map<String, Vertex> path;

    Dijkstra(){
        graph = Map.of(
            "s", Map.of("t", 10, "y", 5),
            "t", Map.of("y", 2, "x", 1),
            "y", Map.of("t", 3, "x", 9, "z", 2),
            "x", Map.of("z", 4),
            "z", Map.of("x", 6, "s", 7)
        );
    }

    void initializeSingleSource(String s){
        path = graph.keySet().stream().collect(Collectors.toMap(
            k -> k, k -> new Vertex()
        ));
        path.get(s).distance = 0;
    }

    void relax(String u, String v, PriorityQueue<String> q){
        if(path.get(v).distance > path.get(u).distance + graph.get(u).get(v)){
            path.get(v).distance = path.get(u).distance + graph.get(u).get(v);
            path.get(v).parent = u;
            if(q.contains(v)){
                q.remove(v);
                q.add(v);
            }
        }
    }

    @Override
    public int compare(String u, String v){
        return path.get(u).distance - path.get(v).distance;
    }

    Map<String, Vertex> singleSourceShortestPath(String s){
        initializeSingleSource(s);
        PriorityQueue<String> q = new PriorityQueue<>(this);
        for(String v: graph.keySet())
            q.add(v);
        while(!q.isEmpty()){
            String u = q.poll();
            for(String v: graph.get(u).keySet())
                relax(u, v, q);
        }
        return path;
    }

    public static void main(String[] args) {
        Dijkstra d = new Dijkstra();       
        Map<String, Vertex> path = d.singleSourceShortestPath("s");
        for(Map.Entry<String, Vertex> e: path.entrySet()){
            Vertex v = e.getValue();
            System.out.println(e.getKey() + "->" + v.distance + ", " + v.parent);
        }
    }
}