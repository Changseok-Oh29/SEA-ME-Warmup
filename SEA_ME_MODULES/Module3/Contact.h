#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact {
private:
    // member variables
    QString name;
    QString phone;
    QString email;

public:
    Contact(const QString& name = "", const QString& phone = "", const QString& email = "");
    // access variables
    QString getName() const;
    QString getPhone() const;
    QString getEmail() const;
    // modify variables
    void setName(const QString& name);
    void setPhone(const QString& phone);
    void setEmail(const QString& email);

    bool operator==(const Contact& other) const {
        return name.trimmed() == other.name.trimmed() && phone.trimmed() == other.phone.trimmed() && email.trimmed() == other.email.trimmed();
    }
};

#endif // CONTACT_H
