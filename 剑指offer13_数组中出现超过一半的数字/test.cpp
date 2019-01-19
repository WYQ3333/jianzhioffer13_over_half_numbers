#include<iostream>

#include<algorithm>
#include<vector>

using namespace std;


class Solution1 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		//排序
		if (numbers.size() == 1){
			return numbers[0];
		}
		sort(numbers.begin(), numbers.end());
		int i = 0;
		int j = 0;
		int count = 0;
		for (i = 0; i < numbers.size(); ++i){
			j = i + 1;
			while(j < numbers.size() && numbers[i] == numbers[j]){
				if (j < numbers.size() && (j - i) >= numbers.size() / 2){
					return numbers[i];
				}
				++j;
			}
		}
		return 0;
	}
};

class Solution2 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int length = numbers.size();
		if (length == 0)
			return 0;
		sort(numbers.begin(), numbers.end());
		int max_num = 0;
		int num = 0;
		int val = numbers[0];
		for (int i = 0; i < length; i++) {
			if (val == numbers[i]) {
				num++;
			}
			else {
				max_num = num > max_num ? num : max_num;
				if (max_num > length / 2)
					return val;
				val = numbers[i];
				num = 1;
			}
		}
		max_num = num > max_num ? num : max_num;
		if (max_num > length / 2)
			return val;
		else
			return 0;
	}
};

class Solution3 {
public:
	//数组排序后，如果符合条件的数存在，则一定是数组中间那个数。
	//（比如：1，2，2，2，3；或2，2，2，3，4；或2，3，4，4，4等等）

	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		// 因为用到了sort，时间复杂度O(NlogN)，并非最优
		if (numbers.empty()) return 0;

		sort(numbers.begin(), numbers.end()); // 排序，取数组中间那个数
		int middle = numbers[numbers.size() / 2];

		int count = 0; // 出现次数
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		}

		return (count>numbers.size() / 2) ? middle : 0;
	}
};

//方法四牛逼
class Solution4 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) return 0;

		// 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
		int result = numbers[0];
		int times = 1; // 次数

		for (int i = 1; i<numbers.size(); ++i)
		{
			if (times == 0)
			{
				// 更新result的值为当前元素，并置次数为1
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result)
			{
				++times; // 相同则加1
			}
			else
			{
				--times; // 不同则减1                
			}
		}

		// 判断result是否符合条件，即出现次数大于数组长度的一半
		times = 0;
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == result) ++times;
		}

		return (times > numbers.size() / 2) ? result : 0;
	}
};

void TestFunc1(){
	vector<int> array = { 1, 2, 2, 3, 2, 2, 4 };
	Solution1 s1;
	cout << "出现超过一半的数字为：";
	cout<<s1.MoreThanHalfNum_Solution(array)<<endl;
}

void TestFunc2(){
	vector<int> array = { 1, 2, 2, 3, 2, 2, 4 };
	Solution2 s2;
	cout << "出现超过一半的数字为：";
	cout << s2.MoreThanHalfNum_Solution(array) << endl;
}

int main(){
	TestFunc2();
	system("pause");
	return 0;
}