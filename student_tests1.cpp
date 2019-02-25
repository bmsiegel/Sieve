#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Vector.hpp"

TEST_CASE("contains, insert_at")
{
  Vector<int> v;
  for (int c = 0; c < 1000; c++)
  {
    REQUIRE(v.insert(c));
  }
  REQUIRE(v.contains(367));
  REQUIRE(v.insert_at(346, 555));
  REQUIRE(v.insert_at(10, 0));
  REQUIRE(v.return_from(556) == 346);
}
TEST_CASE("contains, insert_at for bad values, make_hole")
{
  Vector<int> v;
  for (int c = 0; c < 10; c++)
  {
    REQUIRE(v.insert(c));
  }
  REQUIRE(v.contains(4));
  REQUIRE(v.get_count() == 10);
  REQUIRE(v.insert_at(346, 10));
  REQUIRE(v.get_count() == 11);
  REQUIRE(v.insert_at(45, -1));
  REQUIRE(v.get_count() == 12);
  REQUIRE(v.return_from(0) == 45);
  REQUIRE(v.return_from(11) == 346);
}
TEST_CASE("Tests insert")
{
  Vector<int> v;
  v.insert(1);
  REQUIRE(v.contains(1));
}
TEST_CASE("Test return_from and remove_from if there's nothing there")
{
  Vector<int> v;
  REQUIRE(v.return_from(0) == 0);
  REQUIRE(v.remove_from(0) == 0);
}
TEST_CASE("Tests remove_from and cover_up")
{
  Vector<int> v;
  for (int c = 0; c < 80; c++)
  {
    v.insert(c);
  }
  REQUIRE(v.get_count() == 80);
  REQUIRE(v.remove_from(10) == 10);
  REQUIRE(v.get_count() == 79);
  REQUIRE(v.return_from(10) == 11);
  REQUIRE(v.remove_from(0) == 0);
  REQUIRE(v.get_count() == 78);
  REQUIRE(v.remove_from(76) == 78);
  REQUIRE(v.get_count() == 77);
}
TEST_CASE("copy constructor")
{
  Vector<int> v;
  for (int c = 0; c < 1000; c++)
  {
    v.insert(c);
  }
  Vector<int> q = v;
  for (int c = 0; c < v.get_count(); c++)
  {
    REQUIRE(v.return_from(c) == q.return_from(c));
  }
}
TEST_CASE("assignment operator")
{
  Vector<int> v;
  for (int c = 0; c < 10; c++)
  {
    v.insert(c);
  }
  Vector<int> q;
  for (int c = 75; c < 100; c++)
  {
    q.insert(c);
  }
  v = q;
  REQUIRE(v.return_from(4) == q.return_from(4));
  REQUIRE(v.get_count() == q.get_count());
}
void countValues(Vector<int> v)
{
  int count = v.get_count();
}
TEST_CASE("Memory Stuff")
{
  Vector<int> v;
  for (int c = 0; c < 100; c++)
  {
    v.insert(c);
  }
  {
    Vector<int> q = v;
    countValues(q);
  }
}
