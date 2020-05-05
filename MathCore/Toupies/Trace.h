/*
 * Cette classe est une deque de longueur fixe. Elle est utilisée pour la trace des points qu'on souhaite suivre dans la
 * visualisation 3D.
 */
#pragma once
#include <queue>
#include <QVector3D>
#include <iostream>
template <size_t length>
class Trace  {
private:

public:
    std::deque<float> _points;
    void push_front(const QVector3D&);
    void push_front(const float&);
    [[nodiscard]] const float* pointsBegin() const;
    [[nodiscard]] const float* pointsEnd() const;
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
const float* Trace<length>::pointsBegin() const {
    return &_points.front();
}
template<size_t length>
const float* Trace<length>::pointsEnd() const {
    return &_points.back();
}

template<size_t length>
void Trace<length>::push_front(const float & value) {
    if(_points.size() == 3*length) {
        _points.pop_back();
    }
    _points.push_front(value);
}


