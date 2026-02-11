import java.io.*;
import java.util.*;

public class Main {
	static BufferedReader br;
	static int n, m;
	@SuppressWarnings("unchecked")
	static ArrayList<Integer> e[] = new ArrayList[501];
	@SuppressWarnings("unchecked")
	static ArrayList<Integer> pe[] = new ArrayList[501];
 	
	static boolean visited[];
	
	static int nowcnt=0;
	
	static void fdfs(int idx) {
		if(visited[idx])return;
		visited[idx] = true;
		nowcnt++;
//		System.out.println(idx);
		for(int v: e[idx]) {
			fdfs(v);
		}
	}
	
	static void pdfs(int idx) {
		if(visited[idx])return;
		visited[idx] = true;
		nowcnt++;
//		System.out.println(idx);
		for(int v: pe[idx]) {
			pdfs(v);
		}
	}
	
    public static void main(String[] args) throws Exception {
    	br = new BufferedReader(new InputStreamReader(System.in));
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	for(int i=1;i<=n;i++) {
    		e[i] = new ArrayList<>();
    		pe[i] = new ArrayList<>();
    	}
    	for(int i=0;i<m;i++) {
    		st =new StringTokenizer(br.readLine());
    		int a, b;
    		a = Integer.parseInt(st.nextToken()); b = Integer.parseInt(st.nextToken());
    		e[a].add(b);
    		pe[b].add(a);
    	}
    	int cnt=0;
    	for(int i=1;i<=n;i++) {
    		visited = new boolean[n+1];
    		nowcnt = 0;
    		fdfs(i);visited[i] = false;pdfs(i);
    		if(nowcnt == n+1)cnt++;
    	}
    	System.out.println(cnt);
    }
}
