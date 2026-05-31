func sol(arr []int, d int, idx int, dp []int) int {
    ans := 0
    if dp[idx] != -1 {
        return dp[idx]
    }
    for i := 1; i <= d; i++ {
        if idx+i < len(arr) {
            if arr[idx+i] >= arr[idx] {
                break
            }
            ans = max(ans, sol(arr, d, idx+i,dp)+1)
        } else {
            break
        }
    }
    for i := 1; i<=d; i++ {
        if idx-i >= 0 {
            if arr[idx-i] >= arr[idx] {
                break
            }
            ans = max(ans, sol(arr, d, idx-i,dp)+1)
        } else {
            break
        }
    }
    dp[idx] = ans
    return dp[idx]
}

func maxJumps(arr []int, d int) int {
    ans := 0
    dp := make([]int, 1001)

    for i := 0; i < 1001; i++ {
        dp[i] = -1
    }

    for i, _ := range arr {
        ans = max(ans, sol(arr, d, i, dp)+1)
    }
    return ans
}