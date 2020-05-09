/*
 * Cette classe est une deque de longueur fixe. Elle est utilisée pour la trace des points qu'on souhaite suivre dans la
 * visualisation 3D, ainsi que pour une "trace" des Delta t pour calculer les images par secondes de l'application. Comme elle ne sert que de rapidement encapsuler
 * une deque, nous laissons la deque publique pour faciliter l'accès (pas de raison de la cacher).
 */
#pragma once
#include <queue>
#include <QVector3D>
#include <iostream>
template <size_t length>
class Trace  {
public:
    std::deque<float> _points;
    void push_front(const QVector3D&);
    void push_front(const float&);
    [[nodiscard]] size_t size() const {return _points.size();}
};

template <size_t length>
void Trace<length>::push_front(const QVector3D& point) {
    if(_points.size() == 3*length) {
        _points.pop_back();
        _points.pop_back();
        _points.pop_back();
    }
    _points.push_front(point[2]);
    _points.push_front(point[1]);
    _points.push_front(point[0]);

}

template<size_t length>
void Trace<length>::push_front(const float & value) {
    if(_points.size() == 3*length) {
        _points.pop_back();
    }
    _points.push_front(value);
}


