import java.io.*;
import java.util.*;


public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static BufferedWriter bw;
	
	static void nl() throws IOException {
		st = new StringTokenizer(br.readLine());
	}
	static int p() throws Exception{
		return Integer.parseInt(st.nextToken());
	}
	
	static int n, m;
	
    public static void main(String[] args) throws Exception{
    	br = new BufferedReader(new InputStreamReader(System.in));
    	bw = new BufferedWriter(new OutputStreamWriter(System.out));
    	nl();
    	n=p();m=p();
    	int last[] = new int[m];
    	nl();
    	for(int i=0;i<m;i++) {
    		if(i==0)last[0] = p();
    		else last[i] = last[i-1]+p();
    	}
    	for(int i=0;i<n-1;i++) {
    		nl();
    		int temp[] = new int[m];
    		int templ[] = new int[m];
    		int tempr[] = new int[m];
    		for(int j=0;j<m;j++) {
    			temp[j] = p();
    			if(j==0)templ[j] = last[j]+temp[j];
    			else templ[j] = Math.max(last[j], templ[j-1])+temp[j];
    		}
    		for(int j=m-1;j>=0;j--) {
    			if(j==m-1)tempr[j] = last[j]+temp[j];
    			else tempr[j] = Math.max(last[j], tempr[j+1])+temp[j];
    		}
    		for(int j=0;j<m;j++) {
    			temp[j] = Math.max(templ[j], tempr[j]);
    		}
    		last = temp;
    	}
    	System.out.println(last[m-1]);
    }
}
