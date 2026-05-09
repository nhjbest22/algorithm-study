# @param {Integer[]} nums1
# @param {Integer} m
# @param {Integer[]} nums2
# @param {Integer} n
# @return {Void} Do not return anything, modify nums1 in-place instead.
def merge(nums1, m, nums2, n)
    l = 0
    r = 0

    result = []

    while l < m && r < n do
        if nums1[l] <= nums2[r]
            result << nums1[l]
            l += 1
            next
        end

        result << nums2[r]
        r += 1
        next
    end

    while l < m do
        result << nums1[l]   
        l += 1
    end

    while r < n do
        result << nums2[r]
        r += 1
    end

    result.each.with_index do |num, index|
        nums1[index] = result[index]
    end

end