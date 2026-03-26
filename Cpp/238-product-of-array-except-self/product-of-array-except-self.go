func productExceptSelf(nums []int) []int {
	//   1  2  6  24
	//   24 24 12 4
	//=> 24 12  8 6

	var n = len(nums)
	pre  := make([]int, n)
	suff := make([]int, n)
	ans  := make([]int, n)

	pre[0] = nums[0]
	suff[n-1] = nums[n-1]

	for i := 1; i < n; i++ {
		pre[i] = nums[i] * pre[i-1]
	}

	for i := n - 2; i >= 0; i-- {
		suff[i] = nums[i] * suff[i+1]
	}

	for i := 1; i < n-1; i++ {
		ans[i] = pre[i-1] * suff[i+1]
	}

	ans[0] = suff[1]
	ans[n-1] = pre[n-2]

    // fmt.Println(pre)
    // fmt.Println(suff)

	return ans
}