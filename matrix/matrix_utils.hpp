/**
 * @file matrix_utils.hpp
 *
 * @date Oct 26, 2016
 *
 * @author Michal Kielan
 *
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#ifndef MATRIX_UTILS_HPP_
#define MATRIX_UTILS_HPP_

#include "matrix_eye.hpp"

namespace mlib
{


/**
 * @brief Check if the matrix A is identity
 *
 * @param [in] Matrix A with nxn size
 *
 * @return true - if A matrix is identity
 *         false - if A matrix is not identity
 */
template<typename T, std::size_t n>
bool isIdentity(const Matrix<T, n, n>& A)
{
  const auto identity {eye<unsigned int, n>()};
  const auto uiA {static_cast<Matrix<unsigned int, n, n>>(A)};
  return (uiA == identity);
}


/**
 * @ Compare two matrices with the same size, specific error
 * @param [in] Matrix A ixj
 * @param [in] Matrix B ixj
 * @param [in] error
 *
 * return true if compare, otherwise false
 */
template<typename T, std::size_t row, std::size_t col>
bool compare(const Matrix<T, row, col>& A, const Matrix<T, row, col>& B, const float epsilon)
{
  for(std::size_t i = 0; i < row; i++)
  {
    for(std::size_t j = 0; j < col; j++)
    {
      if(std::abs(A[i][j] - B[i][j]) > epsilon)
      {
        return false;
      }
    }
  }
  return true;
}


} /* namespace mlib */


#endif /* MATRIX_UTILS_HPP_ */
