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
    Systeme(Toupie & toupies_) {
        toupies.push_back(&toupies_);
    }
    //void addToupie(Toupie &);
    [[nodiscard]] std::vector<std::unique_ptr<Toupie> > getToupies() const;
    friend std::ostream& operator<<(std::ostream& out, const Systeme & systeme);

};

