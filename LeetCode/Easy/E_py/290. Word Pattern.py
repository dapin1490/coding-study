class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        words = s.split(' ')  # 단어 파싱

        if len(pattern) != len(words):  # 단어 개수와 패턴 길이 다르면 안 됨
            return False

        matchs = {}  # 패턴 사전 : 키 - 패턴, 값 - 단어
        match_reverse = {}  # 단어 사전 : 키 - 단어, 값 - 패턴

        for c, word in zip(pattern, words):  # 대응되는 패턴과 단어의 쌍 반복
            if c in matchs:  # 패턴 사전에 패턴이 존재하는데
                if matchs[c] != word:  # 단어가 다르면 안 됨
                    return False
            else:  # 없다면 추가
                matchs[c] = word

            if word in match_reverse:  # 단어 사전에 단어가 존재하는데
                if match_reverse[word] != c:  # 패턴이 다르면 안 됨
                    return False
            else:  # 없다면 추가
                match_reverse[word] = c

        return True  # 다 통과하면 됨


# pattern = "abba"
# s = "dog cat cat dogs"

# sol = Solution()
# print(sol.wordPattern(pattern, s))