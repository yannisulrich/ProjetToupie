/*
 * Cette classe est une deque de longueur fixe. Elle est utilisée pour la trace des points qu'on souhaite suivre dans la
 * visualisation 3D.
 */
#pragma once
#include <queue>
#include <gltypes.h>
#include <QVector3D>

template <size_t length>
class Trace  {
private:
    std::deque<GLuint> _points;
public:

    void push_front(const QVector3D&);
    auto pointsBegin();
    auto pointsEnd();
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
auto Trace<length>::pointsBegin() {
    return _points.begin();
}
template<size_t length>
auto Trace<length>::pointsEnd() {
    return _points.end();
}


