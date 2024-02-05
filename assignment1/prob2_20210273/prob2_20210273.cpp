#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void selection_sort(int* arr1, string* arr2, int size);
void swap(int arr1[], string arr2[], int min_idx, int i);

int main()
{   
    //input.txt의 자료 줄 수를 세기 위한 코드
    ifstream line_count("input.txt");

    if(!line_count.is_open())
    {
        cout << "could not open the file " << endl;
        cout << "program terminating" << endl;
        exit(EXIT_FAILURE);
    }

    int count = 0;  //자료 줄 수 저장 변수
    string test;        //getline에서 줄 단위로 받아오기 위한 변수, 의미는 없음

    while(!(line_count.eof()))
    {
        getline(line_count, test);
        count++;
    }

    line_count.close();

    //자료 정렬을 위해 data를 불러오는 코드
    ifstream indata("input.txt");

    if(!indata.is_open())
    {
        cout << "could not open the file " << endl;
        cout << "program terminating" << endl;
        exit(EXIT_FAILURE);
    }

    //자료 개수를 바탕으로 동적할당
    int *years = new int[count];
    string *places = new string[count];

    for(int i = 0; i < count; i++)
        indata >> years[i] >> places[i];

    selection_sort(years, places, count);  //years와 places를 기준으로 각각 sort & 순서 맞추기
    
    ofstream outdata("output.txt");

    for(int i = 0; i < count; i++)
        outdata << years[i] << " " << places[i] << endl;

    delete[] years;
    delete[] places;
    
    indata.close();
    outdata.close();

    return 0;
}

void selection_sort(int* arr1, string* arr2, int size)
{
    int min_idx = 0;
    int temp;
    string temp2;

    //selection sort of arr1
    for(int i = 0; i < size-1; i++)
    {
        min_idx = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr1[j] < arr1[min_idx])
                min_idx = j;
        }

        if(i != min_idx)
            swap(arr1, arr2, min_idx, i);
    }
    
    //selection sort of arr2
    for(int i = 0; i < size-1; i++)
    {
        min_idx = i;
        for(int j = i+1; j < size; j++)
        {
            if(arr2[j] < arr2[min_idx] && arr1[j] <= arr1[min_idx])
                min_idx = j;
        }

        if(i != min_idx)
            swap(arr1, arr2, min_idx, i);
    }
}

void swap(int arr1[], string arr2[], int min_idx, int i)
{
    int temp;
    string temp2;

    temp = arr1[min_idx];
    arr1[min_idx] = arr1[i];
    arr1[i] = temp;

    temp2 = arr2[min_idx];
    arr2[min_idx] = arr2[i];
    arr2[i] = temp2;
}