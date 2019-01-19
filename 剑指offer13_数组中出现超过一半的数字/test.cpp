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