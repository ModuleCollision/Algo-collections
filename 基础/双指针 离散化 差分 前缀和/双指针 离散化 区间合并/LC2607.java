/*一个环有长度为a, b的循环节,则该环具有长度为gcd(a,b )的循环节*/
/*贪心,将每个同余数组往平均值贪*/
class Solution {
	private int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	public long makeSubKSumEqual(int[] arr, int k) {
		int n = arr.length;
		k = gcd(k, n); long ans = 0;
		for (int i = 0; i < k; i++) {
			var b = new ArrayList<Integer>();
			for (int j = i; j < n; j += k) {
				b.add(arr[j]);
			}
			Collections.sort(b);
			int mid = b.get(b.size() / 2);
			for (var x : b) {
				ans += Math.abs(x - mid);
			}
		}
		return ans;
	}
}