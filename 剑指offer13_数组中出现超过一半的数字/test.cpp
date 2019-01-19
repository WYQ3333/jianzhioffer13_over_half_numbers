#include<iostream>

#include<algorithm>
#include<vector>

using namespace std;


class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		//排序
		sort(numbers.begin(), numbers.end());
		int i = 0;
		int j = 0;
		int count = 0;
		for (i = 0; i < numbers.size(); ++i){
			j = i + 1;
			if (j < numbers.size() && numbers[i] == numbers[j]){
				++j;
				++count;
				if (count >= numbers.size() / 2){
					return numbers[i];
				}
				else{
					++j;
					i = j;
					count = 0;
				}
			}	
		}
	}
};

void TestFunc1(){
	vector<int> array = { 1, 2, 2, 3, 2, 2, 4 };
	Solution s1;
	cout << "出现超过一半的数字为：";
	cout<<s1.MoreThanHalfNum_Solution(array)<<endl;

}

int main(){
	TestFunc1();
	system("pause");
	return 0;
}