#include <iostream>
#include <cstdlib>
#include "Project.h"
using namespace std;

const string problem[] = {
    "Mutiples of 3 and 5",
    "Even Fibonacci",
    "Largest Prime Factor",
    "Largest Palindrome Product",
    "Smallest Multiple",
    "Sum Square Diff",
    "1001st Prime",
    "Largest Product in a Series",
    "Special Pythagorean Triplet",
    "Summation of Primes",
    "Largest Product Grid",
    "Highly Divisible Triangular Number",
    "Large Sum",
    "Longest Collatz Sequence",
    "Diophantine Reciprocals A",
    "Power Digit Sum",
    "Number Letter Counts",
    "Maximum Path Sum 1",
    "Counting Sundays",
    "Factorial Digit Sum",
    "Name Scores",
    "First 1000 Fibonacci",
    "Truncatable Primes",
    "Exit"
};

const int NUM_PROBLEMS = 1;
const int EXIT = (NUM_PROBLEMS + 23);


using namespace std;

int main()
{
    Project proj;
    bool done = false;
    int i = 0, ch = 0;

    while (done == false) {
        system("cls");
            for (i = 0; i<(EXIT); i++) {
            cout << (i+1) << ". " << problem[i] << endl;
            }
        cout << "Choose a Problem: ";
        cin >> ch;

        switch (ch) {
            case 1:
            cout <<endl << endl;
            proj.multiples_of_3_and_5();
            break;

            case 2:
            cout << endl << endl;
            proj.even_Fibonacci();
            break;

            case 3:
            cout << endl << endl;
            proj.largest_prime_factor();
            break;

            case 4:
            cout << endl << endl;
            proj.largest_palindrome_product();
            break;

            case 5:
            cout << endl << endl;
            proj.smallest_multiple();
            break;

            case 6:
            cout << endl << endl;
            proj.sum_square_diff();
            break;

            case 7:
            cout << endl << endl;
            proj.prime_1001st();
            break;

            case 8:
            cout << endl << endl;
            proj.largest_product_in_series();
            break;

            case 9:
            cout << endl << endl;
            proj.special_pytho_triplet();
            break;

            case 10:
            cout << endl << endl;
            proj.summation_of_primes();
            break;

            case 11:
            cout << endl << endl;
            proj.largest_product_grid();
            break;

            case 12:
            cout << endl << endl;
            proj.divisible_triangular_number();
            break;

            case 13:
            cout << endl << endl;
            proj.large_sum();
            break;

            case 14:
            cout << endl << endl;
            proj.longest_collatz_sequence();
            break;

            case 15:
            cout << endl << endl;
            proj.diophantine_reciprocals_a();
            break;

            case 16:
            cout << endl << endl;
            proj.power_digit_sum();
            break;

            case 17:
            cout << endl << endl;
            proj.number_letter_counts();
            break;

            case 18:
            cout << endl << endl;
            proj.max_path_sum_one();
            break;

            case 19:
            cout << endl << endl;
            proj.counting_sundays();
            break;

            case 20:
            cout << endl << endl;
            proj.factorial_digit_sum();
            break;

            case 21:
            cout << endl << endl;
            proj.name_scores();
            break;

            case 22:
            cout << endl << endl;
            proj.first_1000_digit_fibonacci();
            break;

            case 23:
            cout << endl << endl;
            proj.truncatable_primes();
            break;

            case EXIT:
                done = true;
                break;
        }
        system ("pause");
    }


    return 0;
}
