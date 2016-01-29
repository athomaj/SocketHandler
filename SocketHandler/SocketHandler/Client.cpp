//
//  Client.cpp
//  SocketHandler
//
//  Created by Julien Athomas on 24/01/16.
//  Copyright © 2016 Julien Athomas. All rights reserved.
//

#include "Client.hpp"

Client::Client(int const fd)
{
    _socket.setFd(fd);
}

Client::~Client()
{
}

Socket&     Client::getSocket()
{
    return (_socket);
}

int     Client::getFd()
{
    return (_socket.getFd());
}
