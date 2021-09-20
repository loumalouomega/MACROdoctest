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
#include <iostream>

// External includes

// Project includes

#ifndef __MATRIX_H__
#define __MATRIX_H__

class Matrix
{
public:
    Matrix(int rows, int cols, double value) : rows_(rows), cols_(cols)
    {
        p = new double*[rows_];
        for (int i = 0; i < rows_; ++i) {
            p[i] = new double[cols_];
        }
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                p[i][j] = value;
            }
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < rows_; ++i) {
            delete[] p[i];
        }
        delete[] p;
    }

    inline double& operator()(int x, int y) { return p[x][y]; }

    inline int& size1() {return rows_;}

    inline int& size2() {return cols_;}

private:
    int rows_, cols_;
    double **p;
};

#endif
