def isvalid(A):
    # for i in A.split():
    #     print i
    return sum([1 for i in A.split('.') if int(i) > 255 or (i[0] == '0' and len(i) > 1)])


class Solution:
    # @param A : string
    # @return a list of strings
    def restoreIpAddresses(self, A):
        k = len(A)
        ans = []
        for i in range(1, k):
            for j in range(i + 1, k):
                for l in range(j + 1, k):
                    ip = A[:i] + '.' + A[i:j] + '.' + A[j:l] + '.' + A[l:]
                    # print ip
                    if isvalid(ip) == 0:
                        ans.append(ip)
        return ans


print Solution().restoreIpAddresses("25151151")
