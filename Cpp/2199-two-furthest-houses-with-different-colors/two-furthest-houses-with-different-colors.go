func maxDistance(colors []int) int {
    ans := 0
    for i := 0; i < len(colors); i++ {
        for j := i + 1; j < len(colors); j++ {
            if colors[i] != colors[j] {
                if j-i > ans {
                    ans = j - i
                }
            }
        }
    }
    return ans
}