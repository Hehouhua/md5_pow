// crackMD5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "md5.h"
#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;
void printMD5(const string& message) {
	cout << "md5(\"" << message << "\") = "
		<< MD5(message).toStr() << endl;
}

int main(int argc,char** argv)
{
	system("color a");
	if (argc == 1) { cout << "usage:crackMD5.exe 3755b4dcef2cc600f52aa201d82f5ecc" << endl;exit(0); }
	    
	char* str=new char[12];
	int leng = strlen(argv[1]);
	time_t start, end;
	time(&start);//start=time(NULL);
	for (int i = 0;i < 200000000;i++) {
		if (i % 10000000 == 0) {
			cout << i << endl;
		}
		string res = MD5(_itoa(i, str, 10)).toStr();
		for (int j = 0;j < leng;j++) {
			if (res[j] != argv[1][j])
				break;
			if (j == leng - 1) {
				time(&end);
				cout << i << endl;
				cout << "cost: " << end - start << " seconds." << endl;
				return 0;
			}
		}
	}
	time(&end);
	cout << "Finish,no match." << endl;
	cout << "cost: " << end - start << " seconds." << endl;
	return 0;
}

