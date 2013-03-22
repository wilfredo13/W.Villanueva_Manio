#include "Project.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <math.h>
#include <string>
#include <sstream>
#define RANGE 1000000
#define MAXIM_SOL 1000

using namespace std;
typedef vector<vector<int> > Array;

Project::Project()
{
    //ctor
}

Project::~Project()
{
    //dtor
}

//palindrome checker
bool Project::checkPalindrome(int num) {
    int n = num;
    int rev = 0;
    int digit = 0;
    while (num > 0)
    {
          digit = num % 10;
          rev = rev * 10 + digit;
          num = num / 10;
    }
    if (n == rev) {
        return true;
    }
    else {return false;}
}

// checking for prime numbers
bool Project::checkPrime(unsigned int num) {

	if (num <= 1) return (false);
        unsigned int upper = sqrt (num) + 1;
	for (unsigned int lower = 2; lower < upper; lower++) {
		if (num % lower == 0)
        return (false);
	}
	return (true);
}

int Project::divisor_count (long unsigned long x)
{
	unsigned int divisor = 0;

	for (int i = 1; i <= sqrt(double(x)); i++)
	{
		if ((x % i) == 0) divisor += 2;
	}

	return (divisor);
}

// Convert from string to integer
int Project::StringConvert(string const& str)
{
	int num = 0;
	istringstream iss(str);
	iss >> num;
	return num;
}

typedef unsigned long long Long;
int findSol(unsigned long long n);

int Project::findSol(unsigned long long n) {

    Long diff;
    long double y;
    Long x;
    Long maxiM = (2*n);
    register int solutions = 0;

    for(x = n+1; x<=maxiM; x++) {
        diff = x-n;
        y = (x*n)/(long double)diff;

            if((Long)y == y) {
                solutions++;
            }
    }
    return solutions;
}


void Project::FileRead(string const& fileName, Array& list)
{
	ifstream f(fileName.c_str());
	if (!f.bad())
	{
		while (!f.eof())
		{
			string data;
			getline(f, data);

			vector<int> line;
			istringstream istr(data);
			while (!istr.eof())
			{
				// Read element from string
				string item;
				istr >> item;
				line.push_back(StringConvert(item));
			}
			list.push_back(line);
		}
	}
	f.close();
}

// Copy for save base matrix
int Project::MaxPath(Array const& baseMatrix)
{
	Array list(baseMatrix);
	for (int i = 0; i < list.size() - 1; ++i)
	{
		for (int j = 0; j < list[i].size(); ++j)
		{
			if (list[i][j] + baseMatrix[i + 1][j] > list[i + 1][j])
			{
				list[i + 1][j] = list[i][j] + baseMatrix[i + 1][j];
			}
			if (list[i][j] + baseMatrix[i + 1][j + 1]> list[i + 1][j + 1])
			{
				list[i + 1][j + 1] = list[i][j] + baseMatrix[i + 1][j + 1];
			}
		}
	}

	vector<int> sortedLine = list.back();
	sort(sortedLine.begin(), sortedLine.end());

	return sortedLine.back();
}

void Project::carryNum(vector<int> & vect)
{
    int carry = 0;
    for(int i = 0; i < vect.size(); i++)
    {
        if(9 < vect[i])
        {
           if((i+1) == vect.size())
           {
              vect.push_back(vect[i]/10);
              vect[i] = vect[i]%10;
           }

           else
           {
               carry   = vect[i]/10;
               vect[i] = vect[i]%10;
               vect[i+1] += carry;
           }
        }
    }
}

void Project::factorial(vector<int> & vect, int num)
{
    for (int j = 0; j < vect.size(); j++)
    {
        vect[j] = vect[j] * num;
    }
    carryNum(vect);
}

int Project::getScore(string s) {
    int score = 0;
    for(unsigned int i = 0; i < s.length(); i++)
        score += (((int) s.at(i)) - 64);
    return score;
}


int Project::getTotalScore(vector<string> names) {
    int total = 0;
    for(unsigned int i = 0; i < names.size(); i++)
        total += (getScore(names[i]) * (i+1));
    return total;
}
/*
==================================================================================
==================================================================================
        Programs from 1 - 400 the above are functions used in the programs
==================================================================================
==================================================================================
*/

//1
void Project::multiples_of_3_and_5(){

    int max = 1000;
    int sum = 0;
    int sumt = 0;
    for (int i = 0; i<max; i++) {
        if (i%3 == 0 || i%5==0){
            sum = sum + i;
            }
        }
        sumt = sum;
        cout << "The sum of multiple of 3 and 5 (from 1 - 1000) is: " << sumt << endl << endl;
}

//2
void Project::even_Fibonacci(){

    int sum = 0;
    int evensum = 2;
    int x=1, y=2;
    int max = 4000000;

    while ((x+y)<max){
        sum = x+y;
        x=y;
        y=sum;
        if(sum%2==0){
            evensum+=sum;
        }
    }
    cout << "The sum of all even valued terms(less than 4M) is : " << evensum << endl;
}

//3
void Project::largest_prime_factor(){

    int x=2, temp=0;
    long long n=600851475143;

    while(x<7000){
        if(checkPrime(x)){
            if(n%x==0){
               if(x>temp)
               temp=x;
                }
            }
    x++;
    }
    cout << "The largest prime factor of the number 600851475143 is: ";
    cout << temp << endl;
}

//4
void Project::largest_palindrome_product(){

    int firstNum = 100;
    int secondNum = 100;
    int pdrome = 0;
    int largestPal = 0;
    bool pPdrome;

    for (int n = 0; n < 900; n++) {
        for (int i = 0; i < 900; i++) {
            pdrome = (firstNum+i) * (secondNum+n);
            pPdrome = checkPalindrome(pdrome);
                if (pPdrome && (pdrome > largestPal)) {
                largestPal = pdrome;
                }
            pdrome = (firstNum+n) * (secondNum+i);
            pPdrome = checkPalindrome(pdrome);
                if (pPdrome && (pdrome > largestPal)) {
                largestPal = pdrome;
                }
        }
    }
    cout << "The Largest Palindrome is : ";
    cout << largestPal <<endl;

}

//5
void Project::smallest_multiple(){

    int div;
    int n = 0;

    cout << "Loading..." << endl;
    do {
        n++;
        for(div = 1; div <=20; div++) {
            if (!(n%div == 0))break;
        }
    }
    while(div<=20);

    cout << "The smallest positive number that is evenly divisible by all of the numbers from 1 to 20 is: ";
    cout << n << endl;
}

//6
void Project::sum_square_diff(){

    int sumOfsqr = 0, sqrOfsum = 0, temp = 0;

    for (int n = 0; n<=100; ++n){
        temp = (temp + n);
        sumOfsqr = sumOfsqr + (n*n);
        sqrOfsum = (temp*temp);
    }
    cout << "The difference between the sum of the squares and the square of the sum (first 100 natural num) is: ";
    cout << (sqrOfsum - sumOfsqr) << endl;

}

//7
void Project::prime_1001st(){

    bool notPrime[RANGE];
    int primeIndex=0;

    for (int i = 2; i < RANGE; i++){
        if (notPrime[i]) continue;

        for (int j = i * 2; j < RANGE; j += i)
        {
            notPrime[j] = true;
        }

        primeIndex++;

        if (primeIndex == 10001)
        {
            cout << "The 1000th prime is " << i << endl;
            break;
        }

    }
}

//8
void Project::largest_product_in_series(){

    int prodOne = 0;
    int n = 0;
    int a = 0, b = 0, c = 0, d = 0, e = 0;
    int min = 48;
    int prodTwo = 0;

    string numberSet = "73167176531330624919225119674426574742355349194934"
                        "96983520312774506326239578318016984801869478851843"
                        "85861560789112949495459501737958331952853208805511"
                        "12540698747158523863050715693290963295227443043557"
                        "66896648950445244523161731856403098711121722383113"
                        "62229893423380308135336276614282806444486645238749"
                        "30358907296290491560440772390713810515859307960866"
                        "70172427121883998797908792274921901699720888093776"
                        "65727333001053367881220235421809751254540594752243"
                        "52584907711670556013604839586446706324415722155397"
                        "53697817977846174064955149290862569321978468622482"
                        "83972241375657056057490261407972968652414535100474"
                        "82166370484403199890008895243450658541227588666881"
                        "16427171479924442928230863465674813919123162824586"
                        "17866458359124566529476545682848912883142607690042"
                        "24219022671055626321111109370544217506941658960408"
                        "07198403850962455444362981230987879927244284909188"
                        "84580156166097919133875499200524063689912560717606"
                        "05886116467109405077541002256983155200055935729725"
                        "71636269561882670428252483600823257530420752963450";
        while(n < 995 ) {

            a=numberSet[n];
            a=a-min;
            b=numberSet[n+1];
            b=b-min;
            c=numberSet[n+2];
            c=c-min;
            d=numberSet[n+3];
            d=d-min;
            e=numberSet[n+4];
            e=e-min;
            prodTwo =a*b*c*d*e;

            if(prodTwo > prodOne) {
            prodOne = prodTwo;
            }
        n++;
        }
    cout << endl << "The largest product in a series is: ";
    cout << prodOne << endl;

}

//9
void Project::special_pytho_triplet(){

    int a = 0, b = 0, c = 0, m = 0, n = 0, k = 0;
    int sum = 0;
    int product = 0;


    for (n = 2; n < 1000; n++)
    {
        for (m = n + 1; m < 1000; m++)
        {
            sum = 0;

            a = (m*m - n*n);
            b = (2*m*n);
            c = (m*m + n*n);

            sum = a + b + c;

            if(1000 % sum == 0)
            {
                k = 1000 / sum;
                a *= k;
                b *= k;
                c *= k;

                goto answer;
            }
        }
    }

    answer:
      product = a * b * c;

    cout << "Product abc: " << product << endl;
}

//10
void Project::summation_of_primes(){

	unsigned long long sum = 0;
    unsigned int num = 0;

    cout << "Loading..." << "\n";
	for (num = 2; num < 2000000; num++)
	{
		if (checkPrime (num))
			sum += num;
	}
	cout << "Sum of primes: " << sum << endl;
}

//11
void Project::largest_product_grid(){

    int grid[20][20] =
    {
    {8, 02, 22, 97, 38, 15, 00, 40, 00, 75, 04, 05, 07, 78, 52, 12, 50, 77, 91, 8},
    {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 04, 56, 62, 00},
    {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 03, 49, 13, 36, 65},
    {52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56, 01, 32, 56, 71, 37, 02, 36, 91},
    {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
    {24, 47, 32, 60, 99, 03, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
    {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
    {67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
    {24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
    {21, 36, 23, 9, 75, 00, 76, 44, 20, 45, 35, 14, 00, 61, 33, 97, 34, 31, 33, 95},
    {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14, 9, 53, 56, 92},
    {16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54, 24, 36, 29, 85, 57},
    {86, 56, 00, 48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
    {19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 04, 89, 55, 40},
    {04, 52, 8, 83, 97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
    {88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
    {04, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
    {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 04, 36, 16},
    {20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 05, 54},
    {01, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 01, 89, 19, 67, 48}
    };

    int largestProduct = 0;

    for(int i = 0; i < 20; i++) {

        for(int j = 0; j < 20; j++) {

            int horiz = 0, verti = 0, diagDR = 0, diagUR = 0;

            if( j >= 3 ){
                horiz = (grid[i][j-3]) * (grid[i][j-2]) * (grid[i][j-1]) * (grid[i][j]);
            }

            if( i >= 3 ){
                verti = (grid[i-3][j]) * (grid[i-2][j]) * (grid[i-1][j]) * (grid[i][j]);
            }

            if( i >= 3 && j >= 3 ) {
                diagDR = (grid[i-3][j-3]) * (grid[i-2][j-2]) * (grid[i-1][j-1]) * (grid[i][j]);
                diagUR = (grid[i-3][j]) * (grid[i-2][j-1]) * (grid[i-1][j-2]) * (grid[i][j-3]);
            }

        if( horiz > largestProduct ) largestProduct = horiz;
        if( verti > largestProduct ) largestProduct = verti;
        if( diagDR > largestProduct ) largestProduct = diagDR;
        if( diagUR > largestProduct ) largestProduct = diagUR;
        }
    }
    cout << "The Largest Product in the 20x20 grid is: " << largestProduct << endl;

}

//12
void Project::divisible_triangular_number(){


    cout << "Loading..." << endl << endl;
    for (unsigned int n = 2015 ;; n++)
	{
		long unsigned long triangle_num = (n * (n + 1)) / 2;

		unsigned int divisors = divisor_count(triangle_num);
		if (divisors > 500)
		{
			cout << "Highly Divisible Triangular Number: " << triangle_num << endl;
			break;
		}
	}


}

//13
void Project::large_sum(){

    long long int sum = 0;
    long long int num[100] = {0};
    string line;
    int x = 1;

    ifstream hugeFile("50digits.txt");
    while (hugeFile.good()){
        getline (hugeFile, line);
        stringstream(line) >> sum;
        num[x] = sum;
        x++;
    }
    hugeFile.close();

    for(int i = 0; i < 100; i++){
	sum = sum + num[i]	;
    }

    char tenDigits[20];
    sprintf(tenDigits, "%llu", sum);
    tenDigits[10] = 0;
    cout << "The first ten Digits: " << tenDigits<< endl;
}

//14
void Project::longest_collatz_sequence(){

    unsigned int answer = 0;
    unsigned int longChain = 0;
    unsigned int termCount = 0;

    for (unsigned int n = 2; n < 1000000; n++)
    {
        termCount = 0;

        for (unsigned int currentNum = n; currentNum > 1; ++termCount)
        {
            currentNum = ((currentNum % 2) == 0) ? (currentNum / 2):((currentNum * 3) + 1);
        }

        if (termCount > longChain)
        {
            longChain = termCount;
            answer = n;
        }
    }

    cout << "Number: " << answer << endl;

}

//15
void Project::diophantine_reciprocals_a(){

   int solutions = 0;
    Long n = (2*3*5*7*11*13);
    Long x = (2*3*5*7*11*13);

    while(solutions <= MAXIM_SOL) {
        solutions = findSol(n);
          n+=x;
    }
    cout << "Diophantine Reciprocals A: ";
    cout << (n - x) << endl;
}

//16
void Project::power_digit_sum(){

    vector <int> numberPieces;
    numberPieces.push_back(1);

	for (int n = 1; n <= 1000; n++)
	{
		int carry = 0;
		for (vector<int>::iterator iter = numberPieces.begin(); iter != numberPieces.end(); iter++)
		{
			*iter = *iter * 2 + carry;

			if (*iter > 9 && (iter+1) != numberPieces.end())
			{
				*iter -= 10;
				carry = 1;
			}

			else if (*iter > 9 && (iter+1) == numberPieces.end())
			{
				*iter -= 10;
				numberPieces.push_back(1);
				break;
			}

			else if (*iter <= 9)
				carry = 0;
		}
	}

	int sum = 0;

	for (vector<int>::iterator iter = numberPieces.begin(); iter != numberPieces.end(); iter++)
		sum += *iter;

	cout << "Sum of the digits of 2^1000 is: " << sum << endl;

}

//17
void Project::number_letter_counts(){

    int sum = 0;

    // Letters of of one, two, three, four, ... nine in ones place
	sum = sum + 9*10*(3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4);
	// Letters of ten, twenty, ... ninety
	sum = sum + 10*3 + 100*(6 + 6 + 5 + 5 + 5 + 7 + 6 + 6);
    // Letters of one, two, three, ..., nine in hundreds place
	sum = sum + 100*(3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4);
	// Letters of eleven, twelve...
	sum = sum + 10*(6 + 6 + 8 + 8 + 7 + 7 + 9 + 8 + 8);

	// Number of hundreds hundreds
	sum = sum + 900*7;

	// Letters of and
	sum = sum + (900 - 9)*3;
	// Letters of one thousand
	sum = sum + 11;

	cout << "The Number of Letters used is: " << sum << endl;

}

//18
void Project::max_path_sum_one(){

    Array matrix;
	FileRead("input.txt", matrix);
	cout << "Maximum Path Sum 1: " << MaxPath(matrix) << endl;

}

//19
void Project::counting_sundays(){

    int dayInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sunday = 0;
	int ctr = 0;
	int day = 0;
	int month = 0;
	int year = 1901;

	while(year < 2001)  {
		//Leap years
		if(year % 4 == 0) {
			dayInMonth[1] = 29;
		}
		else
			dayInMonth[1] = 28;

		month = 0;

		while(month < 12) {
			day = 0;
			while(day < dayInMonth[month]) {
                if(day == 0 && ctr % 7 == 5) {
					sunday++;
				}
				++ctr;
				++day;
			}
			++month;
		}
		++year;
	}
	cout << "The Number of Sunday's that fell on the first month of the 20th century: " << sunday << endl;

}

//20
void Project::factorial_digit_sum(){

    int digit_sum = 0;
    vector<int> vector_one;
    int one_hundred = 100;

    vector_one.push_back(one_hundred);

    for(int i = 2; i < one_hundred; i++)
    {
        factorial(vector_one, i);
    }

    cout << "Sum of 100!: ";

    for(int i = 0; i < vector_one.size(); i++)
    {
        digit_sum += vector_one[i];
    }
    cout << "Factorial Digit Sum: " << digit_sum << endl;

}

//21
void Project::name_scores(){

    vector<string> names;
    ifstream mgaPangalan("names.txt");

    char charName;
    string currName = "";

    //get names from file
    if(mgaPangalan.is_open()) {
        while(!mgaPangalan.eof()) {
            charName = mgaPangalan.get();

            if(isalpha(charName))
                currName.push_back(charName);
            else {
                if(!currName.empty()) {//store finished name
                    names.push_back(currName);
                    currName.clear();
                }
            }
        }
    }
    mgaPangalan.close();
    sort(names.begin(), names.end());

    //count up name scores
    cout << "The Total Scores is: " << getTotalScore(names) << endl;
}


int nthTerm=3;
float term1=1;
float term2=1;
float term3=term1+term2;
float numDigit1=0;
float numDigit2=0;
float numDigit3=0;

void TrickTerm(){
    term1=term2;
    term2=term3;
    numDigit1=numDigit2;
    numDigit2=numDigit3;
    if(numDigit1==numDigit2)
        term3 = term1 + term2;
    else if(numDigit2 > numDigit1)
        term3=(term1/10) + term2;
    while(term3>10){
        term3=term3/10;
        numDigit3++;
    }
    nthTerm++;
}

void Project::first_1000_digit_fibonacci(){

    while(numDigit3+1 < 1000)
    TrickTerm();
    cout << "The 1000 digit Fibonacci: " << nthTerm << endl;
}

int numDigits(int n) {
    int digits = 0;
    if(n < 0)
        n = -n;
    while(n > 0) {
        digits++;
        n /= 10;
    }
    return digits;
}


void Project::truncatable_primes(){

    cout << "Loading... " << endl;
    int firstDig = 0;
    int lastDig = 0;
    int num = 0;
    int total = 0;
    bool prime;
    for(int i = 8; i < 999999; i++) {
        prime = false;
        lastDig = i % 10;
        if(lastDig == 2 || lastDig == 3 || lastDig == 5 || lastDig == 7) {
            for(num = i; num > 0; num /= 10)
                firstDig = num;
            if(firstDig == 2 || firstDig == 3 || firstDig == 5 || firstDig == 7) {
                prime = true;
                //check left to right
                for(num = i; num > 0; num %= (int)pow(10, numDigits(num) - 1)) {
                    if(!checkPrime(num))
                        prime = false;
                }
                if(prime == true) {
                    //check right to left
                    for(num = i; num > 0; num /= 10) {
                        if(!checkPrime(num))
                            prime = false;
                    }
                }
            }
        }
        if(prime)
            total += i;
    }
    cout << "Truncatable Primes: " << total << endl;

}
