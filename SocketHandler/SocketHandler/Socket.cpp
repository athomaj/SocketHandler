//
//  Socket.cpp
//  SocketHandler
//
//  Created by Julien Athomas on 24/01/16.
//  Copyright © 2016 Julien Athomas. All rights reserved.
//

#include "Socket.hpp"

Socket::Socket()
{
}

Socket::~Socket()
{
}

void Socket::emit(std::string const& key, std::string const& value)
{
    
}

void Socket::end(std::string const& key)
{
}

void Socket::exec(std::string const& key, Client* client)
{
    auto command = events.find(key);
    if (command != events.end())
        command->second();
    else
        std::cerr << "Handler with name: " << key << " does not exist." << std::endl;
}

int& Socket::getFd()
{
    return _fd;
}

void Socket::setFd(const int fd)
{
    _fd = fd;
}