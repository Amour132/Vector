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

//杨辉三角形
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> vv;
		vv.resize(numRows);
		int i = 0;
		for (i = 1; i <= numRows; i++)
		{
			vv[i - 1].resize(i, 0);
			vv[i - 1][0] = 1;
			vv[i - 1][i - 1] = 1;
		}
		for (size_t j = 0; j<vv.size(); j++)
		{
			for (size_t k = 0; k<vv[j].size(); k++)
			{
				if (vv[j][k] == 0)
				{
					vv[j][k] = vv[j - 1][k] + vv[j - 1][k - 1];
				}
			}
		}
		return vv;
	}
};

//删除排序数组中的重复项

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
		{
			return 0;
		}
		int i = 0;
		for (int j = 1; j < nums.size(); j++)
		{
			if (nums[i] != nums[j])
			{
				i++;
				nums[i] = nums[j];
			}
		}
		return i + 1;
	}
};

//137. 只出现一次的数字 II

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int ret = 0;
		for (int i = 0; i<32; i++)
		{
			int bitnums = 0;
			int bit = 1 << i;
			for (int num : nums)
			{
				if ((num&bit) != 0)
				{
					bitnums++;
				}
			}
			if (bitnums % 3 != 0)
			{
				ret |= bit;
			}
		}
		return ret;
	}
};

//只出现一次的数组| | |
class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> num(2);
		int ret = nums[0];
		for (size_t i = 1; i<nums.size(); i++)
		{
			ret ^= nums[i];//两个数异或的结果
		}
		int pos = 0;
		for (size_t j = 0; j<32; j++)
		{
			if ((ret&(1 << j)) != 0)
			{
				pos = j;
				break;
			}
		}
		int num1 = 0;
		for (int num : nums)
		{
			if ((num&(1 << pos)) != 0)
			{
				num1 ^= num;
			}
		}
		num[0] = num1;
		num[1] = ret^num1;
		return num;
	}
};

//数组中出现次数超过一半的数
//1
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int ret = numbers[0];
		int count = 1;
		for (int i = 0; i<numbers.size(); i++)
		{
			if (count == 0)
			{
				ret = numbers[i];
			}
			else if (ret == numbers[i])
			{
				count++;
			}
			else
			{
				count--;
			}
		}
		int count2 = 0;
		for (int j = 0; j<numbers.size(); j++)
		{
			if (ret == numbers[j])
			{
				count2++;
			}
		}
		if (count2 >(numbers.size() / 2))
		{
			return ret;
		}
		return 0;

	}
};
//2
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int count = 0;
		int ret = numbers[numbers.size() / 2];
		for (int i = 0; i<numbers.size(); i++)
		{
			if (ret == numbers[i])
			{
				count++;
			}
		}
		if (count>(numbers.size() / 2))
		{
			return ret;
		}
		return 0;
	}
};

//连续子数组的最大和
class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty())
		{
			return 0;
		}
		int sum_max = array[0];
		int sum = array[0];
		for (int i = 1; i<array.size(); i++)
		{
			if (sum<0)
			{
				sum = array[i];
			}
			else
			{
				sum += array[i];
			}
			if (sum > sum_max)
			{
				sum_max = sum;
			}
		}
		return sum_max;
	}
};