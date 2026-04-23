func distanceSum(arr []int, ans []int64) {
    n := len(arr)
    pre, suff := make([]int, n+2), make([]int, n+2)

    for i:= 1; i <= n; i++ {
        pre[i] += pre[i-1] + arr[i-1]
    }
    for i:= n; i >= 1; i--{
        suff[i] += suff[i+1] + arr[i-1]
    }

    for i:= 1; i <= n; i++ {
        rightDistance := suff[i+1] - ((arr[i-1]) * (n - i))
        leftDistance  := (arr[i-1] * (i-1)) - pre[i-1]

        ans[arr[i-1]] = int64(rightDistance + leftDistance)
        
        // fmt.Println("sums " , pre[i] , suff[i])
        // fmt.Println(rightDistance , leftDistance)
    }

}


func distance(nums []int) []int64 {
   n := len(nums)

   ans := make([]int64,n)
   mp := make(map[int][]int)

   for i:= 0; i < n; i++{
    mp[nums[i]] = append(mp[nums[i]],i)
   }

   for _,val := range mp{
    distanceSum(val,ans)
   }

   return ans
}