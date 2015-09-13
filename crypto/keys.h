#ifndef KEYS_H
#define KEYS_H

#include <string>
#include <list>
#include <utility>

class Keys
{
public:
    static std::list<std::pair<std::string, std::string> > getPublicKeys();
    static std::list<std::pair<std::string, std::string> > getSecretKeys();

protected:
    static std::list<std::pair<std::string, std::string> > getKeys(int gpgme_type);

private:
    Keys() {}
};

#endif // KEYS_H
