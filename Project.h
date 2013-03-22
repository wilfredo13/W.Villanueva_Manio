#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include <vector>
using namespace std;
typedef vector<vector<int> > Array;


class Project
{
    public:
        Project();
        virtual ~Project();

        bool checkPalindrome(int);
        bool checkPrime(unsigned int);
        int findSol(unsigned long long n);
        int divisor_count (long unsigned long x);
        int MaxPath(Array const& baseMatrix);
        int StringConvert(string const& str);
        void FileRead(string const& fileName, Array& list);
        void carryNum(vector<int> & vect);
        void factorial(vector<int> & vect, int num);
        bool strCmp(string x, string y);
        int getScore(string s);
        int getTotalScore(vector<string> names);

        void multiples_of_3_and_5();
        void even_Fibonacci();
        void largest_prime_factor();
        void largest_palindrome_product();
        void smallest_multiple();
        void sum_square_diff();
        void prime_1001st();
        void largest_product_in_series();
        void special_pytho_triplet();
        void summation_of_primes();
        void largest_product_grid();
        void divisible_triangular_number();
        void large_sum();
        void longest_collatz_sequence();
        void diophantine_reciprocals_a();
        void power_digit_sum();
        void number_letter_counts();
        void max_path_sum_one();
        void counting_sundays();
        void factorial_digit_sum();
        void name_scores();
        void first_1000_digit_fibonacci();
        void truncatable_primes();

    protected:
    private:

};

#endif // PROJECT_H
