@echo off

set /p Times=Enter how many times you want to compare: 

@REM cd Comparator

cd Judger

g++ ../stds.cpp -o stds
g++ ../test.cpp -o test
g++ ../data.cpp -o data
g++ judge.cpp -o checker

type nul > ../result.txt

for /l %%t in (1, 1, %Times%) do (
	echo | set /p = Test case %%t:  
	echo | set /p = Test case %%t:  >> ../result.txt

	type nul > data.out
	type nul > stds.out
	type nul > test.out



	data %%t > data.out

	type data.out | stds > stds.out
	type data.out | test > test.out

	checker && checker >> ../result.txt

	echo -------------------------------------
	echo ------------------------------------- >> ../result.txt
)


set /p Times=Press Enter to continue: 

@echo on