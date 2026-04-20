func maxDistance(colors []int) int {
    ans , i , j := 0 , 0, len(colors) - 1

    for i <= j {
        if colors[i] != colors[j] {
            ans = max(ans, j - i)
        }
        j--
    }

    j , i = len(colors) - 1, 0
    
    for i <= j {
        if colors[i] != colors[j] {
            ans = max(ans, j - i)
        }
        i++
    }

    return ans

}