#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "math/Vector3.h"

TEST_CASE("vector3 operators", "[vector3]")
{
    SECTION("add, subtract, multiply") 
    {
        Vector3 v1(1.0f, 2.0f, 3.0f);
        Vector3 v2(-2.6f, 4.0f, 5.2f);
        float k = 5.0f;

        Vector3 added(1.0f - 2.6f, 2.0f + 4.0f, 3.0f + 5.2f);
        Vector3 subtracted(1.0f + 2.6f, 2.0f - 4.0f, 3.0f - 5.2f);
        Vector3 multiplied(1.0f * -2.6f, 2.0f * 4.0f, 3.0f * 5.2f);
        Vector3 divided(1.0f / -2.6f, 2.0f / 4.0f, 3.0f / 5.2f);
        Vector3 scaled(1.0f * k, 2.0f * k, 3.0f * k);
        Vector3 unscaled(1.0f / k, 2.0f / k, 3.0f / k);

        REQUIRE(Vector3::add(v1, v2) == added);
        REQUIRE(v1 + v2 == added);
        REQUIRE(v1 + v2 == v2 + v1);

        REQUIRE(Vector3::subtract(v1, v2) == subtracted);
        REQUIRE(v1 - v2 == subtracted);
        REQUIRE(v1 - v2 == -(v2 - v1));

        REQUIRE(Vector3::multiply(v1, v2) == multiplied);
        REQUIRE(v1 * v2 == multiplied);
        REQUIRE(v1 * v2 == v2 * v1);

        REQUIRE(Vector3::multiply(v1, k) == scaled);
        REQUIRE(v1 * k == scaled);
        REQUIRE(k * v1 == scaled);

        REQUIRE(Vector3::divide(v1, v2) == divided);
        REQUIRE(v1 / v2 == divided);

        REQUIRE(Vector3::divide(v1, k) == unscaled);
        REQUIRE(v1 / k == unscaled);

        REQUIRE(k * (v1 + v2) == k * v1 + k * v2);
    }

    SECTION("length, normalize")
    {
        Vector3 v1(2.3f, 4.2f, 5.5f);
        Vector3 v2(3.0f, 0.0f, 0.0f);
        Vector3 v3(-1.2f, 0.0f, -1.6f);

        REQUIRE(v1.lengthSq() == (2.3f * 2.3f + 4.2f * 4.2f + 5.5f * 5.5f));
        REQUIRE(v1.length() == sqrt(2.3f * 2.3f + 4.2f * 4.2f + 5.5f * 5.5f));

        REQUIRE(Vector3::normalize(v2) == Vector3(1.0f, 0.0f, 0.0f));
        REQUIRE(!v2 == Vector3(1.0f, 0.0f, 0.0f));
        REQUIRE(!v3 == Vector3(-0.6f, 0.0f, -0.8f));
    }

    SECTION("cross, dot") 
    {
        Vector3 v1(1.0f, 0.0f, 0.0f);
        Vector3 v2(0.0f, 1.0f, 0.0f);
        Vector3 v3(-1.0f, 0.0f, 0.0f);
        Vector3 crossed(0.0f, 0.0f, 1.0f);
        Vector3 zero(0.0f, 0.0f, 0.0f);
        float k = 3.6f;

        REQUIRE(Vector3::dot(v1, v1) == v1);
        REQUIRE(Vector3::dot(v1, v2) == zero);
        REQUIRE(Vector3::dot(v1, v3) == v3);

        REQUIRE((v1 | v1) == v1);
        REQUIRE((v1 | v2) == zero);
        REQUIRE((v1 | v3) == v3);

        REQUIRE((v1 | v2) == (v2 | v1));
        REQUIRE((v1 | (v2 + v3)) == (v1 | v2) + (v1 | v3));
        REQUIRE((k * v1 | v2) == (v1 | k * v2));
        REQUIRE((k * v1 | v2) == k * (v1 | v2));

        REQUIRE(Vector3::cross(v1, v1) == zero);
        REQUIRE(Vector3::cross(v1, v2) == crossed);
        REQUIRE(Vector3::cross(v1, v3) == -Vector3::cross(v3, v1));

        REQUIRE((v1 ^ v1) == zero);
        REQUIRE((v1 ^ v2) == crossed);
        REQUIRE((v1 ^ v3) == -(v3 ^ v1));
        REQUIRE((v1 ^ (v2 + v3)) == ((v1 ^ v2) + (v1 ^ v3)));
        REQUIRE((k * v1 ^ v2) == (v1 ^ k * v2));
        REQUIRE((k * v1 ^ v2) == k * (v1 ^ v2));

    }
}