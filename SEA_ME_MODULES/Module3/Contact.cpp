#include "Contact.h"
#include <qobjectdefs.h>

Contact::Contact(const QString& n, const QString& p, const QString& e) : name(n), phone(p), email(e) {}

QString Contact::getName() const { return name; }
QString Contact::getPhone() const { return phone; }
QString Contact::getEmail() const { return email; }

void Contact::setName(const QString& n) { name = n; }
void Contact::setPhone(const QString& p) { phone = p; }
void Contact::setEmail(const QString& e) { email = e; }
