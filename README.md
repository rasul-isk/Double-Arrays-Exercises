# Double-Arrays-Exercises
In this repository I am solving few tasks in C++ to demonstrate how double arrays work.

# Part 1   

1) int ReplaceWithMinusOne(int array[4][6])

The level is stored as an array of integers starting off with values 1 to 4 for. 0’s are not included.

Starting from 0,0 in the array test each column in the first row, then the second row , going from left to right until the end of the array is reached

Find One cluster of 3 or more identical items connected horizontally or vertically. Check for a horizontal line first and then a vertical line for each array position in turn.

Score the cluster by adding up the values (1 to 4) in the cluster.
Replace that cluster with ‘-1’s and returns a score

Example:<br/>

Before<br/>
{ {0,0,3,1,3,4},<br/>
  {0,0,2,3,4,3},<br/>
  {0,0,1,3,3,2},<br/>
  {0,0,2,2,2,2} };<br/>

After:<br/>
{ {0,0,3,1,3,4},<br/>
  {0,0,2,3,4,3},<br/>
  {0,0,1,3,3,2},<br/>
  {0,0,-1,-1,-1,-1} };<br/>

Score would be 8
Return 8.

2) void PrintArray(int array[4][6])  

Print the array in rows and columns. Only function you use cout.

3) FallDownAndReplace(int array[4][6]) 

‘Remove’ the -1’s in the array and the items above fall into their position. All items above fall into the ‘empty’ position below them.

New  items are added to the top of the array with values of -2 and will not be part of the next cluster. 

Example:

Before<br/>
{ {0,0,3,3,4,3},<br/>
  {0,0,-1,3,4,3},<br/>
  {0,0,-1,3,3,2},<br/>
  {0,0,-1,2,3,3} };<br/>

After<br/>
{{0,0,-2,3,4,3},<br/>
 {0,0,-2,3,4,3},<br/>
 {0,0,-2,3,3,2},<br/>
 {0,0,3,2,3,3} };<br/>



# Part 2 :  Parse C++ Code.

1) void FindAllVariables(char variables[], char code[]) 

Write a function that takes 2 array of chars as parameters. The function fills the variable array to contain a comma separated list of the variable names that are declared in the code in the string. Only variables of type “int” and “char” need  be included. Only one variable is declared per line. 
Both variables array and code array have a max on 1000 chars.
Note strings are terminated by a 0.

For example 

char code[1000] = “int main() \n{ \n int var1=10;\n int var2 =10;\n if(var1<10) \n {\n int var3=20;\n} \n}\ n”;
char newline = ‘\n’;
char variables[1000] ;
FindAllVariables(variables ,code);
-Variables now contains “var1,var2,var3”

2) void FindVariablesInScope(char variables[], char code[], int lineNumber) 

Find variables in scope after a particular line number.  The code won’t contain “for” loops. Only variables of type “int” and “char” need be included. Only one variable is declared per line. The only function declaration in the code is “int main()”. 
