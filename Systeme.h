//
// Created by Yannis on 28.03.20.
//

#pragma once

#include "MathCore.h"
#include <memory>
#include <initializer_list>
#include <iostream>
class Systeme {
private:
std::vector<Toupie* > toupies;
public:
    Systeme(const Systeme&) = delete;
    Systeme & operator=(const Systeme&) = delete;
    Systeme(const std::initializer_list<Toupie* >& toupies_): toupies(toupies_) {}

    //void addToupie(Toupie &);
    [[nodiscard]] std::vector<Toupie * > getToupies() const;
    friend std::ostream& operator<<(std::ostream& out, const Systeme & systeme);

};

