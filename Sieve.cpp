//Sieve: A program that uses a Vector to conduct the Sieve of Eratosthenes to find primes up to a user
//specified value

//Programmer: Brady Siegel

//I didn't cheat (I neither gave or recieved unauthorized assistance on this project)

#include "Sieve.hpp"
//Constructor: Checks if n is less than 0, and then fills sieve vector with values from 2 to start, and finds the primes using factor
Sieve::Sieve(int n)
{
  if (n < 0)
  {
    start = 10000;
  }
  else
  {
    start = n;
  }
  for (unsigned int c = 2; c <= start; c++)
  {
    sieve.insert(c);
  }
  factor(0);
  // sieve.output(std::cout);
}
//Recursive function that finds primes up to a certain value. Loops through sieve with the first value in the vector and removes all multiples, then calls
//factor again
void Sieve::factor(int starting_loc)
{
  if (starting_loc <= sieve.get_count())
  {
    for (int c = starting_loc; c < sieve.get_count(); c++)
    {
      if (sieve.return_from(c) % sieve.return_from(starting_loc) == 0 && sieve.return_from(c) != sieve.return_from(starting_loc))
      {
        sieve.remove_from(c);
      }
    }
    starting_loc++;
    factor(starting_loc);
  }
}
//Returns the ith prime (index of the vector). If ith is out of range, the function returns 0
unsigned int Sieve::ith_prime (int ith) const
{
  if (ith < 0 || ith > number_of_primes() - 1)
  {
    return 0;
  }
  return sieve.return_from(ith);
}
//Returns number of primes (length of sieve)
unsigned int Sieve::number_of_primes() const
{
  return sieve.get_count();
}
//Iteratively factors start into primes. for each prime in the sieve, the function divides the value as many times as possible
//and adds the prime to the array each time it divides evenly
Vector<unsigned int> Sieve::prime_factorization() const
{
  int num = start;
  Vector<unsigned int> factorization;
  for (int c = 0; c < sieve.get_count(); c++)
  {
    while (num % sieve.return_from(c) == 0)
    {
      factorization.insert(sieve.return_from(c));
      num /= sieve.return_from(c);
    }
  }
  return factorization;
}
