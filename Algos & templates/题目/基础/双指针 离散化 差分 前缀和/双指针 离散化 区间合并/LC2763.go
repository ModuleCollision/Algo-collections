package main

func sumImbalanceNumbers(nums []int) (ans int) {
	n := len(nums)
	right := make([]int, n+5)
	idx := make([]int, n+5)
	for i := 0; i <= n + 1; i++ {
		idx[i] = n + 1
	}
	for i := n; i >= 1; i-- {
		x := nums[i-1]
		right[i] = min(idx[x], idx[x-1])
		idx[x] = i
	}
	for i := range idx {
		idx[i] = 0
	}
	for i := 1; i <= n; i++ {
		x := nums[i-1]
		ans += (i - idx[x-1]) * (right[i] - i)
		idx[x] = i
	}
	return ans - n*(n+1)/2
}

func min(a, b int) int {
	if b < a {
		return b
	}
	return a
}