//
// Created by Yannis on 26.05.20.
//

#include <iostream>
#include <QDebug>
#include "XMLReader.h"
using namespace std;
void XMLReader::readFile() {
    QString name;
    QString string;
    double value;
    if (reader->readNextStartElement()) {
        if(reader->name() != "root") return;
    }
    if (reader->readNextStartElement()) {
        if (reader->name() == "strparameters") {
            while(reader->readNextStartElement()) {
                name = reader->name().toString();
                reader->readNext();
                string = reader->text().toString();
                readOutString.insert_or_assign(name, string);
                reader->skipCurrentElement();
            }
        }
    }
    if (reader->readNextStartElement()) {
        if (reader->name() == "numparameters") {
            while(reader->readNextStartElement()) {
                name = reader->name().toString();
                reader->readNext();
                value = reader->text().toDouble();
                readOutNumeric.insert_or_assign(name, value);
                reader->skipCurrentElement();
            }
        }
    }
}

double XMLReader::readValue(const QString & key) {
    try {return readOutNumeric.at(key);}
    catch(std::out_of_range& outOfRange) {
        std::cerr << "XML: value not available" << std::endl;
        return 0;
    }
}

QString XMLReader::readString(const QString & key) {
    try {return readOutString.at(key);}
    catch(std::out_of_range& outOfRange) {
        std::cerr << "XML: value " << key.toUtf8().data() <<  " not available" << std::endl;
        return "";
    }
}
