//
//  IServer.h
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef IServer_h
#define IServer_h

#include <vector>
#include <iostream>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/ip.h>
#include "Socket.hpp"
#include "Function.hpp"

class IServer
{
public:
    virtual void run(int const) = 0;
    virtual void close(int const) = 0;
    virtual void closeOwnFd() = 0;
protected:
    virtual void socket() = 0;
    virtual void bind() = 0;
    virtual void listen(int const nbClient=50) = 0;
    virtual void select() = 0;
    virtual int accept() = 0;
    virtual void addClient() = 0;
    virtual void checkFds() = 0;
    virtual void resetFds() = 0;
    virtual void setFds() = 0;
};

#endif /* IServer_h */
