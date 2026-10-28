#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "geometry.h"

TEST_CASE("Проверка функции фильтрации параметров для алгоритма Евклида", "[al]")
{
    REQUIRE(al(2, 1) == false);
    REQUIRE(al(4, 2) == false);
    REQUIRE(al(1, 1) == false);
    REQUIRE(al(2, 0) == false);
    REQUIRE(al(1, 0) == false);
}