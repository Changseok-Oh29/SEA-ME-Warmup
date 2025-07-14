#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include <QVector>
#include <QString>

class ContactList
{
private:
    // member variable
    QVector<Contact> contacts;

public:
    // member function
    void add(const Contact& c); // add
    bool remove(const Contact& c); // remove
    QVector<Contact> getAll() const; // 모두 반환
    QVector<Contact> searchByName(const QString& keyword) const; // search

    // remove ??

    bool saveToFile(const QString& path);
    bool loadFromFile(const QString& path);
};

#endif // CONTACTLIST_H
