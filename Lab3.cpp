#include "lab3.h"
#include <string>
#include <iostream>


using namespace std;
bool Arrays2DAreEqual(int arr1[4][6], int arr2[4][6])
{
	for (int rowIndex = 0; rowIndex < 4; rowIndex++) {
		for (int colIndex = 0; colIndex < 6; colIndex++) {
			if (arr1[rowIndex][colIndex] != arr2[rowIndex][colIndex])
			{
				return false;
			}
		}

	}
	return true;
}
int Length1DArray(char* arr)
{
	int len = 0;
	for (int rowIndex = 0; arr[rowIndex] != 0; rowIndex++)
	{
		len++;
	}
	return len;
}
bool Arrays1DAreEqual(char* expectedarr, char* arr2)
{


	for (int rowIndex = 0; expectedarr[rowIndex] != 0; rowIndex++)
	{
		if (expectedarr[rowIndex] != arr2[rowIndex])
		{
			return false;
		}
	}


	return true;
}
int main()
{
	float mark = 10;
	int replace = 0;
	int falldown = 0;
	int varsall = 0;
	int varsScope = 0;
	std::cout << endl << "Print Score = " << mark << endl;

	std::cout << "replacewith minus one 1 " << endl;

	//example of calling the functions
	{
		int array[4][6] = { {0,0,3,1,3,4},
						   {2,2,2,3,4,3},
						   {0,0,1,3,3,2},
						   {0,0,0,0,0,0} };
		int expectedArray[4][6] = { {0,0,3,1,3,4},
						   {-1,-1,-1,3,4,3},
						   {0,0,1,3,3,2},
						   {0,0,0,0,0,0} };
		PrintArray(array);


		int score = ReplaceWithMinusOne(array);
		if (score == 6)
		{
			cout << endl << " ReplaceWithMinusOne score correct " << endl;
			mark += 5;
			replace += 5;
		}
		else {
			cout << endl << " ReplaceWithMinusOne score wrong " << endl;
		}
		if (Arrays2DAreEqual(expectedArray, array))
		{
			cout << endl << "ReplaceWithMinusOne array correct " << endl;
			mark += 12;
			replace += 12;
		}
		else {
			cout << endl << "ReplaceWithMinusOne array wrong " << endl;
		}
	}

	cout << endl << "Score = " << mark << endl;
	cout << "replacewith minus one 2 " << endl;

	{
		int array[4][6] = { {0,0,3,1,3,4},
						   {0,0,4,3,4,2},
						   {0,0,4,3,3,1},
						   {0,0,4,1,0,2} };
		int expectedArray[4][6] = { {0,0,3,1,3,4},
						   {0,0,-1,3,4,2},
						   {0,0,-1,3,3,1},
						   {0,0,-1,1,0,2} };


		int score = ReplaceWithMinusOne(array);
		if (score == 12)
		{
			cout << endl << "replacewith minus one 2 score correct " << endl;
			mark += 4;
			replace += 4;

		}
		else {
			cout << endl << "replacewith minus one 2 score wrong " << endl;
		}
		if (Arrays2DAreEqual(expectedArray, array))
		{
			cout << endl << "replacewith minus one 2 array correct " << endl;
			mark += 9;
			replace += 9;
		}
		else {

			cout << endl << "ReplaceWithMinusOne 2 array wrong " << endl;

		}
	}
	cout << endl << "ReplaceScore = " << replace << endl;
	cout << endl << "Score = " << mark << endl;

	cout << endl << "falldown and replace 1 " << endl;
	{
		int array[4][6] = { {0,0,3,1,3,4},
						   {0,0,2,3,4,3},
						   {0,0,1,3,3,2},
						   {0,-1,-1,-1,3,5} };                                          //SHOULD 0 clusters move???
		int expectedArray[4][6] = { {0,-2,-2,-2,3,4},
									{0,0,3,1,4,3},
									{0,0,2,3,3,2},
									{0,0,1,3,3,5} };



		FallDownAndReplace(array);

		if (Arrays2DAreEqual(expectedArray, array))
		{
			cout << endl << "FallDownAndReplace correct " << endl;

			mark += 15;
			falldown += 15;
		}
		else {
			cout << endl << "FallDownAndReplace wrong " << endl;

		}

	}
	cout << endl << "Falldown Score = " << falldown << endl;
	cout << endl << "Score = " << mark << endl;
	{
		int array[4][6] = { {0,0,3,1,3,4},
						   {0,0,-1,3,4,3},
						   {0,0,-1,3,3,2},
						   {0,0,-1,0,0,0} };
		int expectedArray[4][6] = { {0,0,-2,1,3,4},
									{0,0,-2,3,4,3},
									{0,0,-2,3,3,2},
									{0,0,3,0,0,0} };

		cout << endl << "falldown and replace 2 " << endl;

		FallDownAndReplace(array);

		if (Arrays2DAreEqual(expectedArray, array))
		{
			cout << endl << "FallDownAndReplace correct " << endl;

			mark += 15;
			falldown += 15;
		}
		else {
			cout << endl << "FallDownAndReplace wrong " << endl;

		}

	}
	cout << endl << "Falldown Score = " << falldown << endl;
	cout << endl << "Score = " << mark << endl;

	{
		cout << endl << "findallvariables 1 " << endl;

		char code[1000] = "int main() \n{ \n char hello='a';\n char there=10;\n if(there<10) \n {\n int var3=4;\n int shoe=4;\n}\ n";

		char variables[1000] = "";
		char epectedVariables[1000] = "hello,there,var3,shoe";

		FindAllVariables(variables, code);
		if (Arrays1DAreEqual(epectedVariables, variables))
		{
			cout << endl << "FindAllVariables Correct" << endl;
			mark += 15;
			varsall += 15;

		}
		else
		{
			cout << endl << "FindAllVariables Wrong" << endl;

		}

		//cout << variables;
	}

	cout << endl << "FindallScore = " << varsall << endl;
	cout << endl << "Score = " << mark << endl;
	{
		cout << endl << "findallvariables in scope 1 " << endl;

		char code[1000] = "int main() \n{ \n int numElephants=10;\n int var2 =10; \n if(var1<10) \n {\n int var3=20;\n}\nwhile (var2 <0) \n {\n int var4; \n} \n int var5 =10;\n }  ";

		char variables[1000] = "";
		char epectedVariables[1000] = "numElephants,var2,var5";

		FindAllVariablesInScope(variables, code, 0);

		cout << variables;
		int lengthExpected = Length1DArray(epectedVariables);
		int lengthVars = Length1DArray(variables);
		cout << lengthExpected << " length of expected variable array";
		cout << lengthVars << " real length of variable array";

		if (lengthExpected >= lengthVars - 1 && lengthExpected <= lengthVars + 1)
		{
			cout << endl << "FindAllVariablesInScope Length correct" << endl;

			if (Arrays1DAreEqual(epectedVariables, variables))
			{
				cout << endl << "FindAllVariablesInScope Correct" << endl;

				mark += 7;
				varsScope += 7;
			}
			else
			{
				cout << endl << "FindAllVariablesInScope Wrong" << endl;

				if (Arrays1DAreEqual(epectedVariables, variables))
				{
					cout << endl << "FindAllVariablesInScope Correct" << endl;


					mark += 4;
					varsScope += 4;

				}
				else
				{
					cout << endl << "FindAllVariablesInScope Wrong" << endl;

				}

			}

		}

		cout << endl << "FindallInScopel Score = " << varsScope << endl;
		cout << endl << "Score = " << mark << endl;
		//cout << variables;

		{
			cout << endl << "findallvariables in scope 2 " << endl;

			char code[1000] = "int main()\n{\n char numElephants;\n int hello = 10;\nif (hello < 10)\n{\nchar shoe = 20;\n}\nwhile (hello < 0)\n{\nint top;\nint front = 10;\n}\nint tree = 10;\n}\n int var5 =10;\n } ";

			char variables[1000] = "";
			char epectedVariables[1000] = "numElephants,hello,top";

			FindAllVariablesInScope(variables, code, 11);
			int lengthExpected = Length1DArray(epectedVariables);
			int lengthVars = Length1DArray(variables);

			if (lengthExpected >= lengthVars - 1 && lengthExpected <= lengthVars + 1)
			{
				cout << endl << "FindAllVariablesInScope Length correct" << endl;

				if (Arrays1DAreEqual(epectedVariables, variables))
				{
					cout << endl << "FindAllVariablesInScope Correct" << endl;


					mark += 8;
					varsScope += 8;

				}
				else
				{
					cout << endl << "FindAllVariablesInScope Wrong" << endl;


				}

			}
			else {
				cout << endl << "FindAllVariablesInScope Length wrong" << endl;


				if (Arrays1DAreEqual(epectedVariables, variables))
				{
					cout << endl << "FindAllVariablesInScope Correct" << endl;

					mark += 5;
					varsScope += 5;

				}
				else
				{
					cout << endl << "FindAllVariablesInScope Wrong" << endl;


				}

			}


		}
	}

	cout << endl << "FindallInScope2 Score = " << varsScope << endl;


	cout << endl << " Score = " << mark << endl;
	cout << "Individuals Marks 10," << replace << "," << falldown << "," << varsall << "," << varsScope << " End";
	
	
	
	//Part 3 checking
	
	int dataQuestion1[10] = { 5,2,5,6,21,10 };
	DrawGraph(dataQuestion1);

	int dataQuestion2[10] = { 5,2,5,6,21,10 };
	char graphedData[100][100];
	FillGraph2dArray(dataQuestion2, graphedData);

	for (int i = 0; i < 100; i++)
	{
		for (int x = 0; x < 100; x++)
		{
			cout << graphedData[i][x];
		}
		cout << endl;
	}

}
