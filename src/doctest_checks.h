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
#include <cstring>
#include <iostream>
#include <limits>
#include <cmath> // std::abs for double

// External includes
#if DOCTEST_MPI
#include <mpi.h>
#endif
#include "doctest/doctest/doctest.h"

// Project includes

#if !defined(DOCTEST_CHECKS_H_INCLUDED )
#define  DOCTEST_CHECKS_H_INCLUDED

#define ADD_DOCTEST_TEST int main(int argc, char** argv) \
{                                                        \
    doctest::Context context;                            \
    context.setOption("order-by", "name");               \
    context.applyCommandLine(argc, argv);                \
    context.setOption("no-breaks", true);                \
    int res = context.run();                             \
    if(context.shouldExit()) {                           \
        return res;                                      \
    }                                                    \
    int client_stuff_return_code = 0;                    \
    return res + client_stuff_return_code;               \
}

#define ADD_DOCTEST_TEST_MPI int main(int argc, char** argv) \
{                                                            \
    MPI_Init(&argc, &argv);                                  \
    doctest::Context context;                                \
    context.setOption("order-by", "name");                   \
    context.applyCommandLine(argc, argv);                    \
    context.setOption("no-breaks", true);                    \
    int res = context.run();                                 \
    if(context.shouldExit()) {                               \
        return res;                                          \
    }                                                        \
    int client_stuff_return_code = 0;                        \
    MPI_Finalize();                                          \
    return res + client_stuff_return_code;                   \
}

#define ADD_DOCTEST_TEST_PETSC int main(int argc, char** argv) \
{                                                              \
    PetscInitialize(&argc, &argv, PETSC_NULL, PETSC_NULL );    \
    doctest::Context context;                                  \
    context.setOption("order-by", "name");                     \
    context.applyCommandLine(argc, argv);                      \
    context.setOption("no-breaks", true);                      \
    int res = context.run();                                   \
    if(context.shouldExit()) {                                 \
        return res;                                            \
    }                                                          \
    int client_stuff_return_code = 0;                          \
    PetscFinalize();                                           \
    return res + client_stuff_return_code;                     \
}

#define COMMON_MESSAGE_CHECK "Check failed in file" << __FILE__ << " in line " << __LINE__

#define DOCTEST_CHECK_IS_TRUE(IsTrue) if(!(IsTrue)) std::cout << COMMON_MESSAGE_CHECK << " because " << #IsTrue << " is not true" << std::endl; CHECK(IsTrue);
#define DOCTEST_CHECK_IS_FALSE(IsFalse) if(IsFalse) std::cout << COMMON_MESSAGE_CHECK << " because " << #IsFalse << " is not false" << std::endl; CHECK(!IsFalse);

#define DOCTEST_CHECK_EQUAL(a,b) if(!((a) == (b))) std::cout << COMMON_MESSAGE_CHECK << " because " << #a << " is not equal to " << #b << std::endl; CHECK(a == b);
#define DOCTEST_CHECK_NOT_EQUAL(a,b) if((a) == (b)) std::cout << COMMON_MESSAGE_CHECK << " because " << #a << " is equal to " << #b << std::endl; CHECK(a != b);

#define DOCTEST_CHECK_STRING_EQUAL(a,b) if(a.compare(b) != 0) std::cout << COMMON_MESSAGE_CHECK << " because \"" << a << "\" is not equal to \"" << b << "\"" << std::endl; CHECK(a.compare(b) == 0);
#define DOCTEST_CHECK_STRING_NOT_EQUAL(a,b) if(a.compare(b) == 0) std::cout << COMMON_MESSAGE_CHECK << " because \"" << a << "\" is equal to \"" << b << "\"" << std::endl; CHECK(a.compare(b) != 0);

#define DOCTEST_CHECK_C_STRING_EQUAL(a,b) if((strcmp(a,b) != 0)) std::cout << COMMON_MESSAGE_CHECK << " because \"" << a << "\" is not equal to \"" << b << "\"" << std::endl; CHECK((strcmp(a,b) == 0));
#define DOCTEST_CHECK_C_STRING_NOT_EQUAL(a,b) if((strcmp(a,b) == 0)) std::cout << COMMON_MESSAGE_CHECK << " because \"" << a << "\" is equal to \"" << b << "\"" << std::endl; CHECK((strcmp(a,b) != 0));

#define DOCTEST_CHECK_LESS(a,b) if(!(a < b)) std::cout << COMMON_MESSAGE_CHECK << " because " << #a << " is greater than or equal to " << #b << std::endl; CHECK(a < b);
#define DOCTEST_CHECK_LESS_EQUAL(a,b) if(a > b) std::cout << COMMON_MESSAGE_CHECK << " because " << #a << " is greater than " << #b << std::endl; CHECK(a <= b);

#define DOCTEST_CHECK_GREATER(a,b) if(!(a > b)) std::cout << COMMON_MESSAGE_CHECK << " because " << #a << " is less than or equal to " << #b << std::endl; CHECK(a > b);
#define DOCTEST_CHECK_GREATER_EQUAL(a,b) if(a < b) std::cout << COMMON_MESSAGE_CHECK << " because " << #a << " is less than " << #b << std::endl; CHECK(a >= b);

#define DOCTEST_CHECK_STRING_CONTAIN_SUB_STRING(TheString, SubString) if (TheString.find(SubString) == std::string::npos ) \
std::cout << "The string \"" << SubString << "\" was not found in the given string" << std::endl; CHECK(TheString.find(SubString) != std::string::npos);

#define DOCTEST_CHECK_NEAR(a,b, tolerance) if(std::abs(a - b) > tolerance) std::cout << COMMON_MESSAGE_CHECK << " because " << #a << " = " << a << \
" is not near to " << #b << " = " << b << " within the tolerance " << tolerance << std::endl; CHECK(std::abs(a - b) <= tolerance);
#define DOCTEST_CHECK_RELATIVE_NEAR(a,b, tolerance) if(std::abs(b) > std::numeric_limits<double>::epsilon()) { if(std::abs((a - b)/b) > tolerance) { std::cout << "Check failed because " << #a << " = " << a << \
" is not near to " << #b << " = " << b << " within the relative tolerance " << tolerance << std::endl;} else {DOCTEST_CHECK_NEAR(a,b,tolerance);};} else { CHECK(std::abs(b) <= std::numeric_limits<double>::epsilon());}
#define DOCTEST_CHECK_DOUBLE_EQUAL(a,b) DOCTEST_CHECK_NEAR(a,b,std::numeric_limits<double>::epsilon())

#define DOCTEST_CHECK_VECTOR_NEAR(a, b, tolerance) {                                           \
if(a.size() != b.size()) {                                                                     \
std::cout << COMMON_MESSAGE_CHECK << " because vector arguments do not have the same size:"    \
<< std::endl                                                                                   \
<< "First argument has size " << a.size() << ", "                                              \
<< "second argument has size " << b.size() << "." << std::endl;                                \
}                                                                                              \
CHECK(a.size() == b.size());                                                                   \
for (std::size_t i = 0; i < a.size(); i++) {                                                   \
   if( std::abs(a[i] - b[i]) > tolerance ) {                                                   \
      std::cout << "Check failed because vector " << #a << " is not near to vector " << #b     \
      << "\nMismatch found in component " << i << ":" << std::endl                             \
      << a[i] << " not near " << b[i]                                                          \
      << " within tolerance " << tolerance << "." << std::endl;                                \
    }                                                                                          \
    CHECK(std::abs(a[i] - b[i]) <= tolerance);                                                 \
  }                                                                                            \
}
#define DOCTEST_CHECK_VECTOR_RELATIVE_NEAR(a, b, tolerance) {                                  \
if(a.size() != b.size()) {                                                                     \
std::cout << COMMON_MESSAGE_CHECK << " because vector arguments do not have the same size:"    \
<< std::endl                                                                                   \
<< "First argument has size " << a.size() << ", "                                              \
<< "second argument has size " << b.size() << "." << std::endl;                                \
}                                                                                              \
CHECK(a.size() == b.size());                                                                   \
for (std::size_t i = 0; i < a.size(); i++) {                                                   \
    if (std::abs(b[i]) > std::numeric_limits<double>::epsilon()) {                             \
       if( std::abs((a[i] - b[i])/b[i]) > tolerance ) {                                        \
          std::cout << "Check failed because vector " << #a << " is not near to vector " << #b \
          << "\nMismatch found in component " << i << ":\n"                                    \
          << a[i] << " not near " << b[i]                                                      \
          << " within relative tolerance " << tolerance << "." << std::endl;                   \
       }                                                                                       \
      CHECK(std::abs((a[i] - b[i])/b[i]) <= tolerance);                                        \
    } else {                                                                                   \
       if( std::abs(a[i] - b[i]) > tolerance ) {                                               \
          std::cout << "Check failed because vector " << #a << " is not near to vector " << #b \
          << "\nMismatch found in component " << i << ":\n"                                    \
          << a[i] << " not near " << b[i]                                                      \
          << " within tolerance " << tolerance << "." << std::endl;                            \
      }                                                                                        \
      CHECK(std::abs(a[i] - b[i]) <= tolerance);                                               \
    }                                                                                          \
  }                                                                                            \
}
#define DOCTEST_CHECK_VECTOR_EQUAL(a, b) DOCTEST_CHECK_VECTOR_NEAR(a,b,std::numeric_limits<double>::epsilon())

#define DOCTEST_CHECK_MATRIX_NEAR(a, b, tolerance) {                                                    \
if(!(a.size1() == b.size1()) && (a.size2() == b.size2())) {                                             \
    std::cout << COMMON_MESSAGE_CHECK << " because matrix arguments do not have the same dimensions:"   \
    << "\nFirst argument has dimensions (" << a.size1() << "," << a.size2() << "), "                    \
    << "second argument has dimensions (" << b.size1() << "," << b.size2() << ")." << std::endl;        \
}                                                                                                       \
CHECK(((a.size1() == b.size1()) && (a.size2() == b.size2())));                                          \
for (std::size_t i = 0; i < a.size1(); i++) {                                                           \
    for (std::size_t j = 0; j < a.size2(); j++) {                                                       \
       if ( std::abs(a(i,j) - b(i,j)) > tolerance ) {                                                   \
           std::cout << "Check failed because matrix " << #a << " is not near to matrix " << #b         \
           << "Mismatch found in component (" << i << "," << j << "): \n"                               \
           << a(i,j) << " not near " << b(i,j)                                                          \
           << " within tolerance " << tolerance << "." << std::endl;                                    \
      }                                                                                                 \
      CHECK(std::abs(a(i,j) - b(i,j)) <= tolerance);                                                    \
    }                                                                                                   \
  }                                                                                                     \
}
#define DOCTEST_CHECK_MATRIX_RELATIVE_NEAR(a, b, tolerance) {                                           \
if(!(a.size1() == b.size1()) && (a.size2() == b.size2())) {                                             \
    std::cout << COMMON_MESSAGE_CHECK << " because matrix arguments do not have the same dimensions:\n" \
    << "First argument has dimensions (" << a.size1() << "," << a.size2() << "), "                      \
    << "second argument has dimensions (" << b.size1() << "," << b.size2() << ")." << std::endl;        \
}                                                                                                       \
CHECK(((a.size1() == b.size1()) && (a.size2() == b.size2())));                                          \
for (std::size_t i = 0; i < a.size1(); i++) {                                                           \
    for (std::size_t j = 0; j < a.size2(); j++) {                                                       \
        if (std::abs(b(i,j)) > std::numeric_limits<double>::epsilon()) {                                \
           if( std::abs((a(i,j) - b(i,j))/b(i,j)) > tolerance ) {                                       \
               std::cout << "Check failed because matrix " << #a << " is not near to matrix " << #b     \
               << "Mismatch found in component (" << i << "," << j << "): \n"                           \
               << a(i,j) << " not near " << b(i,j)                                                      \
               << " within relative tolerance " << tolerance << "." << std::endl;                       \
           }                                                                                            \
           CHECK(std::abs((a(i,j) - b(i,j))/b(i,j)) <= tolerance);                                      \
        } else {                                                                                        \
           if ( std::abs(a(i,j) - b(i,j)) > tolerance ) {                                               \
               std::cout << "Check failed because matrix " << #a << " is not near to matrix " << #b     \
               << "Mismatch found in component (" << i << "," << j << "): \n"                           \
               << a(i,j) << " not near " << b(i,j)                                                      \
               << " within tolerance " << tolerance << "." << std::endl;                                \
           }                                                                                            \
          CHECK(std::abs(a(i,j) - b(i,j)) <= tolerance);                                                \
        }                                                                                               \
      }                                                                                                 \
    }                                                                                                   \
}
#define DOCTEST_CHECK_MATRIX_EQUAL(a, b) DOCTEST_CHECK_MATRIX_NEAR(a,b,std::numeric_limits<double>::epsilon())

#endif
