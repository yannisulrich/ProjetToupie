//
// Created by Yannis on 28.03.20.
//
#pragma once

class Toupie;
class Systeme;

class SupportADessin {
public:
    virtual ~SupportADessin() = default;

    //SupportADessin(const SupportADessin&) = delete;

    virtual void dessine(Toupie const&) const = 0;
    virtual void dessine(Systeme const&) const = 0;
};
