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
    TEST_CASE("DOCTEST_CHECK_DOUBLE_EQUAL")
    {
        const double value = 1.0;
        DOCTEST_CHECK_DOUBLE_EQUAL(value, 1.0);
    }
}

ADD_DOCTEST_TEST
