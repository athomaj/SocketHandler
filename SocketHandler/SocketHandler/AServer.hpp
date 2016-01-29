//
//  AServer.hpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef AServer_hpp
#define AServer_hpp

#include "IServer.h"
#include "Client.hpp"

class AServer : public IServer
{
public:
    AServer();
    virtual void run(int const);
    virtual void close(int const);
    virtual void closeOwnFd();
protected:
    virtual void socket();
    virtual void bind();
    virtual void listen(int const nbClient=50);
    virtual void select();
    virtual int accept();
    virtual void addClient();
    virtual void checkFds() = 0;
    virtual void resetFds();
    virtual void setFds() = 0;
protected:
    Socket                  _fd;
    struct protoent       *_pe;
    struct sockaddr_in    _sIn;
    fd_set                fdRead;
    fd_set                fdWrite;
    int                   _protoType;
    int                   _sockType;
    int                   maxFd;
    std::vector<Client *>     clients;
};


#endif /* AServer_hpp */
