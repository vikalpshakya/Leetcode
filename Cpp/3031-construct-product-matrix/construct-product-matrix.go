func constructProductMatrix(grid [][]int) [][]int {
    const mod = 12345
    var n = len(grid)
    var m = len(grid[0])

    ans := make([][]int , n)
    for i := 0; i < n; i++{
        ans[i] = make([]int, m)
    }
    
    var preMul int = 1
    for i := 0; i < n; i++ {
        for j := 0; j < m; j++ {
            ans[i][j] = preMul % mod
            preMul = ((preMul % mod) * (grid[i][j] % mod) ) % mod;
        }
    }

    var suffMul int = 1
    for i := n-1; i >= 0; i-- {
        for j:= m-1; j >= 0; j-- {
            ans[i][j] = ((ans[i][j] % mod) * (suffMul % mod)) % mod;
            suffMul = ((suffMul % mod) * (grid[i][j]%mod) )% mod;
        }
    }

    return ans
}