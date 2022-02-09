//Assignment No:	Lab 3
//Student Name:		Rasul Iskandarov
//Student Number:	C00246498
//Date:				24/11/2021

#pragma once
#include <iostream>
using namespace std;
int ReplaceWithMinusOne(int array[4][6])
{
	int raw = 4;
	int column = 6;
	int count = 0; 
	int element = 0;
	int tempIndex = 0;
	int score = 0;
																										
	if (column >= 3)	
	{
		for (int rawIndex = 0; rawIndex < raw; rawIndex++)
		{
			for (int columnIndex = 0; columnIndex < column; columnIndex++)
			{
				if (array[rawIndex][columnIndex] > 0 && array[rawIndex][columnIndex] < 5)
				{
					count = 0;
					element = array[rawIndex][columnIndex];
					tempIndex = columnIndex;

					while (tempIndex < column)
					{
						if (array[rawIndex][tempIndex] == element)
						{
							count++;
							tempIndex++;
						}
						else
						{
							break;
						}
					}

					if (count >= 3)
					{
						while (columnIndex < column && count > 0)
						{
							score += array[rawIndex][columnIndex];
							array[rawIndex][columnIndex] = -1;
							columnIndex++;
							count--;
						}
					}
				}
			}
		}
	}

	if (raw >= 3)	
	{
		for (int rawIndex = 0; rawIndex < raw; rawIndex++) 
		{
			for (int columnIndex = 0; columnIndex < column; columnIndex++)
			{
				if (array[rawIndex][columnIndex] > 0 && array[rawIndex][columnIndex] < 5)
				{
					count = 0;
					element = array[rawIndex][columnIndex];
					tempIndex = rawIndex;
					while (tempIndex < raw)
					{
						if (array[tempIndex][columnIndex] == element)
						{
							count++;
							tempIndex++;
						}
						else
						{
							break;
						}
					}

					if (count >= 3)
					{
						tempIndex = rawIndex;
						while (tempIndex < raw && count > 0)
						{
							score += array[tempIndex][columnIndex];
							array[tempIndex][columnIndex] = -1;
							tempIndex++;
							count--;
						}

					}
				}
			}
		}
	}
	return score;
}


void FallDownAndReplace(int array[4][6])
{
	int change = 4; 
	int raw = 4;
	int column = 6;


	while (change > 0) 
	{
		change--;
		for (int rawIndex = 0; rawIndex < raw; rawIndex++)
		{
			for (int columnIndex = 0; columnIndex < column; columnIndex++)
			{
				if (array[rawIndex][columnIndex] != 0 && rawIndex != raw - 1)
				{
					if (array[rawIndex + 1][columnIndex] == -1 && array[rawIndex][columnIndex] != 0 && array[rawIndex][columnIndex] != -1)
					{
						array[rawIndex + 1][columnIndex] = array[rawIndex][columnIndex];
						array[rawIndex][columnIndex] = -1;
						change++;
					}
				}
			}
		}

	}

	for (int rawIndex = 0; rawIndex < raw; rawIndex++) 
	{
		for (int columnIndex = 0; columnIndex < column; columnIndex++)
		{
			if (array[rawIndex][columnIndex] == -1)
			{ 
				array[rawIndex][columnIndex] = -2;
			}
		}
	}



}	

void PrintArray(int array[4][6])
{	
	int raw = 4;
	int col = 6;
	
	std::cout << "Printing array: " << std::endl << std::endl;

	for (int rawIndex = 0; rawIndex < raw; rawIndex++)
	{
		for (int columnIndex = 0; columnIndex < col; columnIndex++)
		{
			if (array[rawIndex][columnIndex] >= 0) 
			{
				std::cout << "  " << array[rawIndex][columnIndex];
			}
			else
			{
				std::cout << " " << array[rawIndex][columnIndex];
			}
		}

		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl;
}

void FindAllVariables(char variables[1000], char code[1000])
{
	int charIndex = 0;
	int variablesIndex = 0;

	char type[4] = "";
	char name[32] = "";
	int nameIndex = 0;
	int tempIndex = 0;



	while (charIndex < 994) 
	{
		if (code[charIndex] == '\0') { break; }

		while (code[charIndex] == ' ') { charIndex++; }


		type[0] = code[charIndex];
		type[1] = code[charIndex+1];
		type[2] = code[charIndex+2];

		if (type[0] == 'c' && type[1] == 'h' && type[2] == 'a' && code[charIndex + 3] == 'r' && code[charIndex + 4] == ' ')
		{
			type[3] = 'r';
			charIndex += 4;
		}
		if (type[0] == 'i' && type[1] == 'n' && type[2] == 't' && code[charIndex + 3] == ' ')
		{
			type[3] = ' ';
			charIndex += 3;
		}

		if ((type[0] == 'i' && type[1] == 'n' && type[2] == 't' && code[charIndex] == ' ') || (type[0] == 'c' && type[1] == 'h' && type[2] == 'a' && type[3] == 'r'))
		{
			while(code[charIndex] == ' ') { charIndex++; } //avoid all spaces

			tempIndex = nameIndex;

			while (true)
			{
				if (code[charIndex] == '(' || code[charIndex] == ')')
				{
					charIndex++;
					nameIndex = tempIndex;
					break;
				}
				if (code[charIndex] != ' ' && code[charIndex] != '=' && code[charIndex] != ';')
				{
					name[nameIndex] = code[charIndex];
					charIndex++;
					nameIndex++;
					continue;
				}
				if(code[charIndex] == ' ' || code[charIndex] == '=' || code[charIndex] == ';')
				{
					for (int index = 0; index < nameIndex; index++, variablesIndex++) {
						variables[variablesIndex] += name[index];
					}
					variables[variablesIndex] += ',';

					nameIndex = 0;
					variablesIndex++;
					charIndex++;
					
					break;
				}
			}
		}
		else
		{
			charIndex++;
		}
	}

	if (variablesIndex != 0) //delete last comma
	{
		variables[variablesIndex - 1] = '\0';
	}
	cout << "Result is " << variables;
}

void FindAllVariablesInScope(char variables[1000], char code[1000], int lineNumber)
{
	int charIndex = 0;
	int variablesIndex = 0;
	int nameIndex = 0;
	int tempIndex = 0;
	int lineCount = 1;

	char type[4] = "";
	char name[32] = "";


	while (charIndex < 994) 
	{
		if (code[charIndex] == '\0') { break; }

		while (code[charIndex] == ' ') { charIndex++; } 


		type[0] = code[charIndex];
		type[1] = code[charIndex + 1];
		type[2] = code[charIndex + 2];

		if (type[0] == 'c' && type[1] == 'h' && type[2] == 'a' && code[charIndex + 3] == 'r' && code[charIndex + 4] == ' ')
		{
			type[3] = 'r';
			charIndex += 4;
		}
		if (type[0] == 'i' && type[1] == 'n' && type[2] == 't' && code[charIndex + 3] == ' ')
		{
			type[3] = ' ';
			charIndex += 3;
		}
		
		if (type[0] == '\n')
		{
			charIndex++;
			lineCount++;
		}

		if (lineCount >= lineNumber && ( (type[0] == 'i' && type[1] == 'n' && type[2] == 't' && code[charIndex] == ' ') || (type[0] == 'c' && type[1] == 'h' && type[2] == 'a' && type[3] == 'r')) )
		{
			while (code[charIndex] == ' ') { charIndex++; } 

			tempIndex = nameIndex;

			while (true)
			{
				if (code[charIndex] == '(' || code[charIndex] == ')')
				{
					charIndex++;
					nameIndex = tempIndex;
					break;
				}
				if (code[charIndex] != ' ' && code[charIndex] != '=' && code[charIndex] != ';')
				{
					name[nameIndex] = code[charIndex];
					charIndex++;
					nameIndex++;
					continue;
				}
				if (code[charIndex] == ' ' || code[charIndex] == '=' || code[charIndex] == ';')
				{
					for (int index = 0; index < nameIndex; index++, variablesIndex++) {
						variables[variablesIndex] += name[index];
					}
					variables[variablesIndex] += ',';

					nameIndex = 0;
					variablesIndex++;
					charIndex++;

					break;
				}
			}
		}
		else
		{
			charIndex++;
		}
	}

	if (variablesIndex != 0)
	{
		variables[variablesIndex - 1] = '\0';
	}
	cout << "Result is " << variables;
}