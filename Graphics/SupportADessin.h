//
// Created by Yannis on 28.03.20.
//
#pragma once

class Toupie;
class Systeme;

class SupportADessin {
public:
    virtual ~SupportADessin() {}

    //SupportADessin(const SupportADessin&) = delete;

    virtual void dessine(Toupie const&) = 0;

    virtual void dessine(Systeme const&) = 0;
    //virtual void dessine(Systeme const&) = 0;
};


