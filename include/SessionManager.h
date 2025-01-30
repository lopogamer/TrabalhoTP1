#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include "Dominios.h"

class SessionManager {
private:
    static SessionManager* instance;
    Codigo codigo;
    SessionManager() = default;
    ~SessionManager() = default;
    SessionManager(const SessionManager&) = delete;
    SessionManager& operator=(const SessionManager&) = delete;
public:
    static SessionManager* getInstance() {
        static SessionManager localInstance;
        instance = &localInstance;
        return instance;
    }

    void setCodigo(const Codigo& novoCodigo) {
        codigo = novoCodigo;
    }

    Codigo getCodigo() const {
        return codigo;
    }

    void clear() {
        codigo.SetCodigo("000000");
    }
};
inline SessionManager* SessionManager::instance = nullptr;
#endif // SESSIONMANAGER_H