#ifndef ENCRYPTER_H_
#define ENCRYPTER_H_

#include <QtCore/QString>

// https://www.cryptopp.com/wiki/DefaultEncryptorWithMAC

class Encrypter
{
public:
    Encrypter();
    ~Encrypter();
    QString encrypt(QString _key, QString _text);
    QString decrypt(QString _key, QString _text);
};

#endif  // _ENCRYPTER_H_