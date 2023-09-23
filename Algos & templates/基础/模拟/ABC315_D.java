import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int[][] cnt1 = new int[H][30];
        int[][] cnt2 = new int[W][30];
        boolean[] r = new boolean[H];
        boolean[] c = new boolean[W];
        String[] s = new String[H];
        for (int i = 0; i < H; i++) {
            s[i] = sc.next();
            for (int j = 0; j < W; j++) {
                cnt1[i][s[i].charAt(j) - 'a']++;
                cnt2[j][s[i].charAt(j) - 'a']++;
            }
        }
        while (true) {
            ArrayList<Integer> rr = new ArrayList<>();
            ArrayList<Integer> cc = new ArrayList<>();
            for (int i = 0; i < H; i++) {
                if (r[i] == true || W == 1) continue;
                for (int j = 0; j < 26; j++) {
                    if (cnt1[i][j] == W) {
                        r[i] = true;
                        rr.add(j);
                        break;
                    }
                }
            }
            for (int i = 0; i < W; i++) {
                if (c[i] == true || H == 1) continue;
                for (int j = 0; j < 26; j++) {
                    if (cnt2[i][j] == H) {
                        c[i] = true;
                        cc.add(j);
                        break;
                    }
                }
            }
            for (int i = 0; i < W; i++) {
                for (int a : rr) {
                    cnt2[i][a]--;
                }
            }
            for (int i = 0; i < H; i++) {
                for (int a : cc) {
                    cnt1[i][a]--;
                }
            }
            H -= rr.size();
            if (rr.size() == 0 && cc.size() == 0) break;
            W -= cc.size();
        }
        System.out.println(H * W);
    }
};