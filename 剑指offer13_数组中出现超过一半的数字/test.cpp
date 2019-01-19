#include<iostream>

#include<algorithm>
#include<vector>

using namespace std;


class Solution1 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		//����
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
	//���������������������������ڣ���һ���������м��Ǹ�����
	//�����磺1��2��2��2��3����2��2��2��3��4����2��3��4��4��4�ȵȣ�

	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		// ��Ϊ�õ���sort��ʱ�临�Ӷ�O(NlogN)����������
		if (numbers.empty()) return 0;

		sort(numbers.begin(), numbers.end()); // ����ȡ�����м��Ǹ���
		int middle = numbers[numbers.size() / 2];

		int count = 0; // ���ִ���
		for (int i = 0; i<numbers.size(); ++i)
		{
			if (numbers[i] == middle) ++count;
		}

		return (count>numbers.size() / 2) ? middle : 0;
	}
};

//������ţ��
class Solution4 {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers)
	{
		if (numbers.empty()) return 0;

		// ����ÿ��Ԫ�أ�����¼����������ǰһ��Ԫ����ͬ���������1�����������1
		int result = numbers[0];
		int times = 1; // ����

		for (int i = 1; i<numbers.size(); ++i)
		{
			if (times == 0)
			{
				// ����result��ֵΪ��ǰԪ�أ����ô���Ϊ1
				result = numbers[i];
				times = 1;
			}
			else if (numbers[i] == result)
			{
				++times; // ��ͬ���1
			}
			else
			{
				--times; // ��ͬ���1                
			}
		}

		// �ж�result�Ƿ���������������ִ����������鳤�ȵ�һ��
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
	cout << "���ֳ���һ�������Ϊ��";
	cout<<s1.MoreThanHalfNum_Solution(array)<<endl;
}

void TestFunc2(){
	vector<int> array = { 1, 2, 2, 3, 2, 2, 4 };
	Solution2 s2;
	cout << "���ֳ���һ�������Ϊ��";
	cout << s2.MoreThanHalfNum_Solution(array) << endl;
}

int main(){
	TestFunc2();
	system("pause");
	return 0;
}