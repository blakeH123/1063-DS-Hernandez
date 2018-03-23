```cpp
/*
* @ProgramName: Homework - ToUpper
* @Author: Blake Hernandez
* @Description:
*  This program uses a function to uppercase all the letters in words.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 26 03 2018
*/

#include<iostream>
#include<string>

using namespace std;

/*
* @FunctionName: ToUpper
* @Description:
*    Loops through a word and capitalizes lowercase letters
* @Params:
*   string - lowercase
* @Returns:
*    string - uppercase
*/

string ToUpper(string w)
{
	for (int i = 0; i<w.length(); i++)
	{
		if ((int)w[i] >= 97 && (int)w[i] <= 123)
		{
			w[i] = w[i] - 32;
		}
	}
	return w;
}

int main()
{
	string w = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	cout << w << '\n';
	cout << ToUpper(w) << '\n';

	system("pause");
	return 0;
}
```
