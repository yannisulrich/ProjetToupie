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

    virtual void dessine(const double & t, Toupie const&) const = 0;
    virtual void dessine(const double & t, Systeme const&) const = 0;

};
//le support vide sert à faire marcher l'exemple testToupie, qui date d'avant l'introduction de supports à dessin.
class SupportVide: public SupportADessin {
public:
    ~SupportVide() = default;

    //SupportADessin(const SupportADessin&) = delete;

    void dessine(Toupie const&) const override {};
    void dessine(Systeme const&) const override {};

    void dessine(const double & t, Toupie const&) const override {};
    void dessine(const double & t, Systeme const&) const override {};

};