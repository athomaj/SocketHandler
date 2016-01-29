//
//  ServerTCP.cpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#include "ServerTCP.hpp"

ServerTCP::ServerTCP() :
    AServer()
{
}

void ServerTCP::checkFds()
{
    for (unsigned int i=0; i< clients.size(); ++i)
    {
        if (FD_ISSET(clients[i]->getFd(), &fdRead))
        {
        }
        if (FD_ISSET(clients[i]->getFd(), &fdWrite))
        {
        }
    }
    if (FD_ISSET(_fd.getFd(), &fdRead))
        addClient();
}

void ServerTCP::setFds()
{
}