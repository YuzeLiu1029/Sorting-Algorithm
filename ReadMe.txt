Hi, Thanks for reading this file.
I used C++ to do this assignment and compile on linprog.
There are 3 .cpp files in this folder.They are:
insertSort.cpp
mergeSort.cpp
countingSort.cpp

And I used this comaand to do makefile:
g++ -std=c++11 -Wall -pedantic -o insertSort.x insertSort.cpp
so there are 3 .x files:
insertSort.x
mergeSort.x
countingSort.x

When you need to run the program, you can use the following command on linprog:

./insertSort.x<int_10_10

int_10_10 is the test data file name, I just used the data that professor provided for us. You csn replace the file name.When I test my program, I just put the data file and the .x file in the sam folder in linprog and run the folloeing code.

./insertSort.x<int_10_10
./mergeSort.x<int_100_10
./countingSort.x<int_1000_10

In the .tar file, I have also included a small data file named int_10_10
incase you just want to test quickly.

Thanks for your time.

I am from Mechanical Engineering, I am not sure what is the easiest way for you to test our programm. This is how we submit assignemnt in another course Data Structure. So I guess that may be convinent for you.I am sorry if this makes you grading work harder.
