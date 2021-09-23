/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

// package codetoanalyze.java.infer;

#include "string"

class DivideByZero {

public:
    DivideByZero() = default;
    int divByZeroLocal(std::string s) {
        int denominator = 0;
        int nominator = 10;
        int result = nominator / denominator;
        return result;
    }

    int divideByZeroInterProc(int denominator) {
        return 10 / denominator;
    }

    int callDivideByZeroInterProc() {
        return divideByZeroInterProc(0);
    }

    void setXToZero() {
        x = 0;
    }

    int divideByZeroWithStaticField() {
        setXToZero();
        return divideByZeroInterProc(x);
    }

    // divide by zero with static fields
private:
    int x;

};

//int main() {
//    auto* divBy0 = new DivideByZero();
//    divBy0->divByZeroLocal("stuff");
//    return 0;
//}