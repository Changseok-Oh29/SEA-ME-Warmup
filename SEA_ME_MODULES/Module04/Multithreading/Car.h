#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QString>

class Car : public QObject {
    Q_OBJECT

private:
    int position;
    int speed;
    int direction;
    QString name;

public:
    explicit Car(QObject *parent = nullptr);

    int getPosition() const;
    int getSpeed() const;
    int getDirection() const;
    QString getName() const;

    void setPosition(int pos);
    void setSpeed(int sp);
    void setDirection(int dir);
    void setName(const QString &nme);

    void move();

signals:
    void positionChanged(int newPosition);
};

#endif // CAR_H
