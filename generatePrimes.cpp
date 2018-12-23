#include <iostream>
#include <string>
#include <cmath>
#include <time.h>

//Debugging
#include <typeinfo>

using namespace std;

//Random Number with a range
int generateRandNum(int min, int max)
{
	int intRange = max - min + 1;
	return rand() % intRange + min;
}

//Random Number without any range
int generateRandNum()
{
	return rand();
}


//Generate Prime Numbers Recursively
int generatePrime(int lowerBound, int upperBound)
{
	int randomNum = generateRandNum(lowerBound, upperBound);
	if(randomNum < 1) return generatePrime(lowerBound, upperBound);		
	else if(randomNum == 1 || randomNum == 2 || randomNum == 3 || randomNum == 5 || randomNum == 7) return randomNum;
	else if(randomNum % 2 == 0) return generatePrime(lowerBound, upperBound);
	else if((randomNum > 3) && (randomNum % 3 == 0)) return generatePrime(lowerBound, upperBound);
	else if((randomNum > 5) && (randomNum % 5 == 0)) return generatePrime(lowerBound, upperBound);
	else if((randomNum > 7) && (randomNum % 7 == 0)) return generatePrime(lowerBound, upperBound);
	else if ((randomNum % (randomNum / 2)) == 0) return generatePrime(lowerBound, upperBound);
	else return randomNum;
}


//Main Method
int main()
{
	//Variables
	int noPrimes;
	string strRange;
	
	//Seed the random number generator
	srand(time(0));
	
	//Ask, no of primes and Range ==if range is 0 or null, generate my own range
	cout << "How many prime numbers do you wanna generate? ";
	//Read
	cin >> noPrimes;
	
	cout << "What is your range of numbers to generate? Start with the lowerbound(min) space, then upperbound(max). ";	
	//Read
	getchar();	//Clean the stream
	getline(cin, strRange, '\n');
	
	string delimiter = " ";	//Delimiter
	const size_t pos = 0;         //Intial Position
	int intRanges[2];		//Array to store minimum and max
	int counter = 0;			//Counter
	
	
    	unsigned int intLower, intUpper;
    	const size_t del = strRange.find(' ');  	//Delimiter position
	
    	if (std::string::npos != del)
    	{
        	intLower = atoi(strRange.substr(0, del).c_str());
        	intUpper = atoi(strRange.substr(del + 1).c_str());
   	}
	
	//Generate primes into array
	int primes[noPrimes];
	
	for(int i =0; i < noPrimes; i++)
	{
		primes[i] = generatePrime(intLower, intUpper);
		cout << primes[i] << endl;
	}
	
	//Exit
	return 0;
}
