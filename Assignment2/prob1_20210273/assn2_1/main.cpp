#include <iostream>
#include "Vector.h"
#define num 33

using namespace std;

void print_vec(const Vector& vec)
{
	cout << "----------------------------------------" << endl;
	cout << "Print (Data size, Allocation size)" << endl;
	cout << "(" << vec.size() << ", " << vec.capacity() << ")\n\n";
	cout << "Print Data" << endl;
	for (auto it = begin(vec); it != end(vec); ++it) cout << *it << "\t";
	cout << endl;
}

int main()
{
	cout << "========================================" << endl;
	cout << "1. init vector" << endl;
	float tmp[] = { 3.2, 2.5, 2.11 };
	Vector vec1;
	Vector vec2(sizeof(tmp) / sizeof(*tmp), tmp);
	Vector vec3(vec2);
	print_vec(vec1);
	print_vec(vec2);
	print_vec(vec3);
	cout << endl;

	cout << "========================================" << endl;
	cout << "2. push_back" << endl;
	float push = 3.763;
	vec1.push_back(push);
	vec2.push_back(push);

	print_vec(vec1);
	print_vec(vec2);
	cout << endl;
	
	cout << "========================================" << endl;
	cout << "3. insert" << endl;
	float insrt = -5.8775;
	vec1.insert(vec1.begin(), insrt);
	float insrt_arr[] = { 3.2105, 2.51, -3.70, 3.14 };
	vec1.insert(vec1.begin(), insrt_arr, insrt_arr + sizeof(insrt_arr) / sizeof(*insrt_arr));
	print_vec(vec1);
	cout << endl;
	
	
	cout << "========================================" << endl;
	cout << "4. pop_back" << endl;
	vec1.pop_back();
	print_vec(vec1);
	cout << endl;

	cout << "========================================" << endl;
	cout << "5. erase" << endl;
	vec1.erase(vec1.begin() + 3);
	print_vec(vec1);
	cout << endl;


	cout << "========================================" << endl;
	cout << "6. resize" << endl;
	vec1.resize(3);
	print_vec(vec1);
	cout << endl;

	//cout << "========================================" << endl;
	//cout << "6. resize" << endl;
	//vec1.resize(8);
	//print_vec(vec1);
	//cout << endl;

	cout << "========================================" << endl;
	cout << "7. operator []" << endl;
	for (int i = 0; i < 3; i++)
		cout << vec1[i] << "\t";
	cout << endl;

	cout << "========================================" << endl;
	cout << "8. operator =" << endl;
	Vector vec5;
	vec5 = vec1;
	print_vec(vec1);
	print_vec(vec5);
	cout << endl;

	cout << "========================================" << endl;
	cout << "9. clear" << endl;
	vec1.clear();
	print_vec(vec1);
	cout << endl;

	cout << "========================================" << endl;
	cout << "10. allocate and insert" << endl;
	float pi[num] = { 0, };
	for (int i = 0; i < num; i++)
		pi[i] = 3.14;
	vec1.allocate(int(num * 1.5));

	vec1.insert(vec1.begin(), pi, pi + num);
	print_vec(vec1);
	cout << endl;


	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "========================================" << endl;
	cout << "For find error" << endl;
	vec1 = vec5;
	print_vec(vec1);
	print_vec(vec5);
	cout << "========================================" << endl;
	cout << "6. resize" << endl;
	vec1.resize(8);
	print_vec(vec1);
	cout << endl;

	cout << endl;

	return 0;
}