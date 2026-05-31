func subarrayBitwiseORs(arr []int) int {
	// Tracks all unique bitwise OR results across all subarrays
	res := make(map[int]struct{})
	
	// Tracks the bitwise OR results of subarrays ending at the CURRENT element
	currentResults := make(map[int]struct{})

	for _, x := range arr {
		// Calculate new results ending at the current element 'x'
		nextResults := make(map[int]struct{})
		
		// 1. A subarray can start and end exactly at 'x'
		nextResults[x] = struct{}{}
		
		// 2. Or extend previous subarrays by performing OR with 'x'
		for prevVal := range currentResults {
			nextResults[prevVal|x] = struct{}{}
		}

		// Save everything from this step into our global results set
		for val := range nextResults {
			res[val] = struct{}{}
		}

		// Move to the next iteration
		currentResults = nextResults
	}

	return len(res)
}
