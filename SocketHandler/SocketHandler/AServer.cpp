//
//  AServer.cpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "AServer.hpp"

AServer::AServer() :
    _sockType(SOCK_STREAM), _protoType(IPPROTO_IP)
{
}

void AServer::close(int const fd)
{
    ::close(fd);
}


void AServer::run(int const port)
{
    _sIn.sin_family = AF_INET;
    _sIn.sin_port = htons(port);
    _sIn.sin_addr.s_addr = INADDR_ANY;

    socket();
    bind();
    listen();
    while (42)
    {
        resetFds();
        setFds();
        select();
        checkFds();
    }
}

void AServer::socket()
{
    if ((_fd.getFd() = ::socket(AF_INET, _sockType, _protoType)) == -1)
    {
        
        perror("socket()");
        throw ("server socket init failed\n");
    }
    int enable = 1;
    if (setsockopt(_fd.getFd(), SOL_SOCKET, SO_REUSEADDR, reinterpret_cast<char *>(&enable), sizeof(int)) < 0)
        perror("setsockopt()");
    maxFd = _fd.getFd();
}

void AServer::bind()
{
    if (::bind(_fd.getFd(), (const struct sockaddr *)(&_sIn), sizeof(_sIn)) == -1)
    {
        close(_fd.getFd());
        throw ("bind failed\n");
    }
}

void AServer::closeOwnFd()
{
    close(_fd.getFd());
}

void AServer::select()
{
    struct timeval timeout;
    
    timeout.tv_sec = 0;
    timeout.tv_usec = 100;
    if (::select(maxFd + 1, &fdRead, &fdWrite, NULL, &timeout) == -1)
    {
        perror("select()");
        throw (std::runtime_error("select failed\n"));
    }
}

void AServer::resetFds()
{
    FD_ZERO(&fdRead);
    FD_ZERO(&fdWrite);
}

void AServer::listen(int const nbClient)
{
    if (::listen(_fd.getFd(), nbClient) == -1)
    {
        close(_fd.getFd());
        throw ("listen failed\n");
    }
}

int AServer::accept()
{
    int                   fdC;
    
	if ((fdC = ::accept(_fd.getFd(), NULL,
                        NULL)) == -1)
    {
        close(_fd.getFd());
        throw ("Accept failed");
    }
    return (fdC);
}

void AServer::addClient()
{
    int newFd;
    Client* newClient;
    
    if ((newFd = accept()) != -1)
    {
        maxFd = newFd > maxFd ? newFd : maxFd;
        newClient = new Client(newFd);
        clients.push_back(newClient);
        
        _fd.exec("connection", newClient);
        //adding new client here
    }
}

