#include <cryptopp/default.h>
#include <cryptopp/filters.h>
#include <cryptopp/hex.h>

#include <string>

#include "Encrypter.h"

Encrypter::Encrypter() {}

Encrypter::~Encrypter() { delete this; }

QString Encrypter::encrypt(QString _key, QString _text)
{
    std::string encryptedText;

    CryptoPP::StringSource ss1(_text.toStdString(), true,
    new CryptoPP::DefaultEncryptorWithMAC(
        (CryptoPP::byte*)&_key[0], _key.size(),
            new CryptoPP::HexEncoder(
                new CryptoPP::StringSink(encryptedText)
            )
        )
    );

    return QString::fromStdString(encryptedText);
}

QString Encrypter::decrypt(QString _key, QString _text)
{
    std::string decryptedText;

    CryptoPP::StringSource ss2(_text.toStdString(), true,
    new CryptoPP::HexDecoder(
        new CryptoPP::DefaultDecryptorWithMAC(
            (CryptoPP::byte*)&_key[0], _key.size(),
                new CryptoPP::StringSink(decryptedText)
            )
        )
    );

    return QString::fromStdString(decryptedText);
}
