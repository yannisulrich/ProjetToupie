#pragma once
#include <QXmlStreamReader>
#include <unordered_map>
#include <QtCore/QFile>

class XMLReader {
public:
    explicit XMLReader(QFile* file): file(file) { reader = new QXmlStreamReader(file);}
    void readFile();
    double readValue(const QString&);
    QString readString(const QString&);
private:
    QFile* file;
    QXmlStreamReader* reader;

    std::unordered_map<QString, double> readOutNumeric;
    std::unordered_map<QString, QString> readOutString;

};



