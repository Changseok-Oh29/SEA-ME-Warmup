#include "Contactlist.h"
#include <QFile>
#include <QTextStream>

void ContactList::add(const Contact& c) {
    contacts.append(c);
}

bool ContactList::remove(const Contact& c) {
    for (int i=0;i<contacts.size();i++) {
        if (contacts[i] == c) {
            contacts.removeAt(i);
            return true;
        }
    }
    return false;
}

QVector<Contact> ContactList::getAll() const {
    return contacts;
}

QVector<Contact> ContactList::searchByName(const QString& keyword) const {
    QVector<Contact> results;
    for (const auto& c : contacts) {
        if (c.getName().contains(keyword, Qt::CaseInsensitive)) {
            results.append(c);
        }
    }
    return results;
}

bool ContactList::saveToFile(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    QTextStream out(&file);
    for (const auto& c : contacts) {
        out << c.getName() << "," << c.getPhone() << "," <<c.getEmail()<<"\n";
    }
    return true;
}

bool ContactList::loadFromFile(const QString& path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
    contacts.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 3) {
            contacts.append(Contact(parts[0], parts[1], parts[2]));
        }
    }
    return true;
}
