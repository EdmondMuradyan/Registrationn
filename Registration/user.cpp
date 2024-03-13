#include "user.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

User::User()
{
}

void User::setInfo(const QString& name, const QString& age, const QString& birth)
{
    this->name = name;
    this->age = age;
    this->birth = birth;
}

QString User::getName() const
{
    return name;
}

QString User::getAge() const
{
    return age;
}

QString User::getBirth() const
{
    return birth;
}

void User::saveFile(const QString& filename) const
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    QTextStream out(&file);
    out << "Name: " << name << "\n";
    out << "Age: " << age << "\n";
    out << "Birth: " << birth << "\n";

    file.close();
}

void User::printFileContents(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        qDebug() << line;
    }

    file.close();
}
