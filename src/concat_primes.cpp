/** 
    @mainpage Concat Primes

    @author Marlee Krause and Austin Miller

    Homework-2-concat_primes, this program deals with concatenating primes
    onto a string and then prints out a slice of 5 prime numbers.
*/

/** \file concat_primes.cpp
    \brief Concatenates primes onto string and prints 5
    
    This program generates prime numbers through the get_concatenated_primes()
    function and then adds those primes to the end of the concat_primes string
    this string is then returned as a substring with length 1000
    This returned string is then used in the get_slice_of_5() function,
    in this function the user inputted index is used to return a string of length
    5 from that index.

    That string is then used in main for output/testing
    
    Requires: C++11
*/


#include<iostream>
#include<string>
#include <assert.h>


/** \brief Returns a string of concatenated primes
   
   This function generates prime numbers and adds them to the end of a string
   it then takes that string and returns a substring of the length 1000 starting
   from zero.
    @return concat_primes.substr(0, 1000)
*/
std::string get_concatenated_primes()
{

    std::string concat_primes = "";
    //Complete this function
    
    //current number
    int currNum = 2;

    //max value
    int k = 2000;
    
    while(currNum <= k){

        //flag isPrime variable, true if isPrime
        bool isPrime =true;

        //iterates through all numbers up to half of currNum
        for(int i = 2; i <= (currNum/2); i++){
            
            //if current number is divisible by any number up to hald
            //flag is now false and number is not prime
            //then breaks the loop
            if(currNum % i == 0){
                isPrime = false;
                break;
            }

        }

        //if the number is prime, add it to the end of concat_primes string
        if(isPrime == true)
            concat_primes = concat_primes + std::to_string(currNum);
            //concat_primes.append(std::to_string(currNum));

        //incrementing currNum
        currNum++;
    }

    //returning substring of length 1000
    return concat_primes.substr(0, 1000);
}

/** \brief Returns a string of concatenated primes specifed by n
   
   This function uses the prime numbers produced in the 
   get_concatenated_primes() function and prints out 5
   characters of the primes whose starting point is determined by
   the users input of n in main().
    @return ret
*/

std::string get_slice_of_5(const std::string & primes, const int index)
{

    std::string ret = "";
    
    //sets ret to a substring from index with a length of 5
    ret = primes.substr(index,5);
    
    return ret;
}

/** \brief tests the program, prompts users for n, and prints out the slice of 5 primes 
   
 This function tests the program when there are two or more arguments.
 If the arguments are less than two, then this function will prompt 
 the user to input the value of the integer n, and then print out the 
 slice of five concatenated primes determined by the functions 
 get_concatenated_primes(), and get_slice_of_5().
    @return 0
*/

int main(int argc, char *argv[]){
    using namespace std;
    int n;
    string concat_primes;
    if (argc >= 2){
        concat_primes = get_concatenated_primes();
        assert(get_slice_of_5(concat_primes, 3) == "71113");
        cout<<"Unit Test 1 passed\n";
        assert(get_slice_of_5(concat_primes, 6) == "13171");
        cout<<"Unit Test 2 passed\n";
        assert(get_slice_of_5(concat_primes, 10) == "19232");
        cout<<"Unit Test 3 passed\n";
        assert(get_slice_of_5(concat_primes, 120) == "92332");
        cout<<"Unit Test 4 passed\n";
        assert(get_slice_of_5(concat_primes, 998) == "91");
        cout<<"Unit Test 5 passed\n";
        
    } else{
        cout<< "Please input n: ";
        while(std::cin >> n)
        {
            concat_primes = get_concatenated_primes();
            std::cout << get_slice_of_5(concat_primes, n) << std::endl;
            cout<< "Please input n: ";
        }
    }
    return 0;
}
