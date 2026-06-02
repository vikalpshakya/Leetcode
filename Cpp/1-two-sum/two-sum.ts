function twoSum(nums: number[], target: number): number[] {
    let ans : number[] = [];

    for(var i = 0; i < nums.length; i++) {
        for(var j = i + 1; j < nums.length; j++) {
            if(nums[i] + nums[j] == target) {
                ans.push(i,j);
            }
        }
    }

    return ans;

};