#ifndef USER_H
#define USER_H

#include <QString>

class User
{
public:
    User();
    void setInfo(const QString& name, const QString& age, const QString& birth);
    void saveFile(const QString& filename) const; // Function to save user info to a file
    static void printFileContents(const QString& filename); // Function to print file contents

    // Getters
    QString getName() const;
    QString getAge() const;
    QString getBirth() const;

private:
    QString name;
    QString age;
    QString birth;
};

#endif // USER_H
