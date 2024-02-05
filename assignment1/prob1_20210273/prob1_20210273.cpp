#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>

float calculator(char, float, float);       //input data를 바탕으로 계산하는 함수

using namespace std;

int main()
{
    FILE *indata, *outdata;

    float num1, num2;      //input data 저장
    float cal;      //계산 결과 저장
    char oper;      //연산자 저장

    indata = fopen("input.txt", "r");
    outdata = fopen("output.txt", "w");
    
    if(!indata)
    {
        printf("could not open the file\n");
        printf("program terminating\n");
        exit(EXIT_FAILURE);
    }

    while(!feof(indata))
    {
        fscanf(indata, "%c %f %f ", &oper, &num1, &num2);   //파일에서 숫자 읽어오기
        cal = calculator(oper, num1, num2);
        fprintf(outdata, "%.3f\n", cal);        //계산한 결과 output 출력
    }

    fclose(indata);
    fclose(outdata);

    return 0;
}


float calculator(char oper, float num1, float num2)
{
    if(oper == '+')
        return num1 + num2;
    else if(oper == '-')
        return num1 - num2;
    else if(oper == '*')
        return num1 * num2;
    else if(oper == '/')
        return num1 / num2;
    else
        return 0;
}