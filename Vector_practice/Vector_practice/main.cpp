//只出现一次的数
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int i = 0;
		int ret = nums[0];
		for (i = 1; i<nums.size(); i++)
		{
			ret ^= nums[i];
		}
		return ret;
	}
};

//电话号码的组合
class Solution {
	string leetmap[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
	void combine(const string& digits, size_t i, const string& str, vector<string>&strs)
	{
		if (digits.size() == i)
		{
			strs.push_back(str);
			return;
		}
		string letters = leetmap[digits[i] - '0'];
		for (size_t j = 0; j<letters.size(); j++)
		{
			combine(digits, i + 1, str + letters[j], strs);
		}

	}

	vector<string> letterCombinations(string digits) {
		vector<string> strs;
		if (digits.empty())
		{
			return strs;
		}
		size_t i = 0;
		string str;
		combine(digits, i, str, strs);
		return strs;
	}
};