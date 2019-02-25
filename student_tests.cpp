#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Sieve.hpp"

TEST_CASE("Tests Constructor, Factor, and ith_prime")
{
  Sieve s(10);
  REQUIRE(s.ith_prime(0) == 2);
  REQUIRE(s.ith_prime(1) == 3);
  REQUIRE(s.ith_prime(2) == 5);
  REQUIRE(s.ith_prime(3) == 7);
  Sieve a(-1);
  REQUIRE(a.ith_prime(1228) == 9973);
  REQUIRE(a.ith_prime(-1) == 0);
  REQUIRE(a.ith_prime(10000) == 0);
}
TEST_CASE("Tests number_of_primes")
{
  Sieve s(10);
  REQUIRE(s.number_of_primes() == 4);
  REQUIRE(s.ith_prime(s.number_of_primes() - 1) == 7);
}
TEST_CASE("Tests prime_factorization")
{
  Sieve s(10);
  Vector<unsigned int> v = s.prime_factorization();
  v.output(std::cout);
  Vector<unsigned int> test;
  test.insert(2);
  test.insert(5);
  for (int c = 0; c < v.get_count(); c++)
  {
    REQUIRE(v.return_from(c) == test.return_from(c));
  }
}
// TEST_CASE()
// {
//
// }
// TEST_CASE()
// {
//
// }
