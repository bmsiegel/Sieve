#include "Vector.hpp"

#ifndef SIEVE_H
#define SIEVE_H

class Sieve
{
private:
  Vector<unsigned int> sieve; //Vector that holds the primes
  unsigned int start; //Starting value for prime_factorization and max value for finding primes
  void factor(int starting_loc); //Recursive function to find primes up to start
public:
  Sieve(int n = 10000); //Constructor, 10000 is default value
  unsigned int ith_prime (int ith) const; //Returns the prime at the specified index
  unsigned int number_of_primes() const; //Returns number of primes
  Vector<unsigned int> prime_factorization() const; //Returns a vector that contains the values for prime factorization
};

#endif
