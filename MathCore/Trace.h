/*
 * Cette classe est une deque de longueur fixe. 
 * Elle est finalement utilisée uniquement pour les Delta t pour calculer les images par secondes de l'application. 
 * Elle ne sert en principe que de rapidement encapsuler une deque.
 */
#pragma once
#include <queue>
#include <QVector3D>
#include <iostream>
#include <numeric>
template <size_t length>
class Trace  {
public:

    void push_front(const QVector3D&);
    void push_front(const float&);
    [[nodiscard]] size_t size() const {return _points.size();}
    [[nodiscard]] std::deque<float> points() const {return _points;}
    [[nodiscard]] float sum() {return std::accumulate(_points.begin(), _points.end(), 0.0f);};
private:
    std::deque<float> _points;
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


