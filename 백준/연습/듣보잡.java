import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class 듣보잡 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int m = Integer.parseInt(inputs[1]);

        Set<String> noListenMap = new HashSet<>();
        Set<String> noSeeMap = new HashSet<>();

        for (int i=0; i<n; ++i) {
            String noListen = br.readLine();
            noListenMap.add(noListen);
        }

        for (int i=0; i<m; ++i) {
            String noSee = br.readLine();
            noSeeMap.add(noSee);
        }

        List<String> noListenNoSeeList = noListenMap.stream()
                .filter(noSeeMap::contains)
                .sorted()
                .collect(Collectors.toList());

        bw.write(noListenNoSeeList.size() + "\n");
        noListenNoSeeList.forEach(s -> {
            try {
                bw.write(s + "\n");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        });

        bw.close();
    }
}
