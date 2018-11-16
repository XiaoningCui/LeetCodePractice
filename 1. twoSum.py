
'''
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''

def twoSum(self, nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    temp_dict = {}
    for i in range(0, len(nums)):
        complement = target - nums[i]
        # 查找complement在不在字典的keys（存nums中的值）中
        if(complement in temp_dict.keys()):
            # 在就返回字典中complement这个key对应的value（存nums中的值对应的索引）
            return [temp_dict[complement], i]
        else:
            # 不在就把nums当前的值和对应索引放入字典的key和value中
            temp_dict[nums[i]] = i
    
nums = [3, 5, 39, 59, 988, 3845]
target = 1047
rlist = []
print(twoSum(rlist, nums, target))



