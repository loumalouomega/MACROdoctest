//  __  __    _    ____ ____   ___        _            _            _
// |  \/  |  / \  / ___|  _ \ / _ \    __| | ___   ___| |_ ___  ___| |_
// | |\/| | / _ \| |   | |_) | | | |  / _` |/ _ \ / __| __/ _ \/ __| __|
// | |  | |/ ___ \ |___|  _ <| |_| | | (_| | (_) | (__| ||  __/\__ \ |_
// |_|  |_/_/   \_\____|_| \_\\___/   \__,_|\___/ \___|\__\___||___/\__|
//
//  License:		 MIT License (LICENSE in root folder)
//
//  Main authors:    Vicente Mataix Ferrandiz
//

// System includes

// External includes
#include "doctest_checks.h"

// Project includes

TEST_SUITE("DoctestChecks")
{
    TEST_CASE("DOCTEST_CHECK_IS_TRUE")
    {
        const bool value = true;
        DOCTEST_CHECK_IS_TRUE(value);
    }

    TEST_CASE("DOCTEST_CHECK_IS_FALSE")
    {
        const bool value = false;
        DOCTEST_CHECK_IS_FALSE(value);
    }

    TEST_CASE("DOCTEST_CHECK_EQUAL")
    {
        const bool value = true;
        DOCTEST_CHECK_EQUAL(value, true);
    }

    TEST_CASE("DOCTEST_CHECK_NOT_EQUAL")
    {
        const bool value = true;
        DOCTEST_CHECK_NOT_EQUAL(value, false);
    }

    TEST_CASE("DOCTEST_CHECK_STRING_EQUAL")
    {
        const std::string value = "test";
        DOCTEST_CHECK_STRING_EQUAL(value, "test");
    }

    TEST_CASE("DOCTEST_CHECK_STRING_NOT_EQUAL")
    {
        const std::string value = "test";
        DOCTEST_CHECK_STRING_NOT_EQUAL(value, "no_test");
    }

    TEST_CASE("DOCTEST_CHECK_C_STRING_EQUAL")
    {
        const std::string value = "test";
        DOCTEST_CHECK_C_STRING_EQUAL(value.c_str(), "test");
    }

    TEST_CASE("DOCTEST_CHECK_C_STRING_NOT_EQUAL")
    {
        const std::string value = "test";
        DOCTEST_CHECK_C_STRING_NOT_EQUAL(value.c_str(), "no_test");
    }

    TEST_CASE("DOCTEST_CHECK_LESS")
    {
        const double value = 1.0;
        DOCTEST_CHECK_LESS(value, 1.01);
    }

    TEST_CASE("DOCTEST_CHECK_LESS_EQUAL")
    {
        const double value = 1.0;
        DOCTEST_CHECK_LESS_EQUAL(value, 1.01);
        DOCTEST_CHECK_LESS_EQUAL(value, 1.0);
    }

    TEST_CASE("DOCTEST_CHECK_GREATER")
    {
        const double value = 1.0;
        DOCTEST_CHECK_GREATER(value, 0.99);
    }

    TEST_CASE("DOCTEST_CHECK_GREATER_EQUAL")
    {
        const double value = 1.0;
        DOCTEST_CHECK_GREATER_EQUAL(value, 0.99);
        DOCTEST_CHECK_GREATER_EQUAL(value, 1.0);
    }

    TEST_CASE("DOCTEST_CHECK_STRING_CONTAIN_SUB_STRING")
    {
        const std::string value = "sub_test";
        DOCTEST_CHECK_STRING_CONTAIN_SUB_STRING(value, "test");
    }

    TEST_CASE("DOCTEST_CHECK_NEAR")
    {
        const double value = 1.0;
        DOCTEST_CHECK_NEAR(value, 0.991, 1.0e-2);
    }

    TEST_CASE("DOCTEST_CHECK_RELATIVE_NEAR")
    {
        const double value = 1.0;
        DOCTEST_CHECK_RELATIVE_NEAR(value, 1.009, 1.0e-2);
    }

    TEST_CASE("DOCTEST_CHECK_DOUBLE_EQUAL")
    {
        const double value = 1.0;
        DOCTEST_CHECK_DOUBLE_EQUAL(value, 1.0);
    }
}

ADD_DOCTEST_TEST
