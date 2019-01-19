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
			while(j < numbers.size() && numbers[i] == numbers[j]){
				if (j < numbers.size() && (j - i) >= numbers.size() / 2){
					return numbers[i];
				}
				++j;
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