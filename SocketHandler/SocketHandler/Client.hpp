//
//  Client.hpp
//  SocketHandler
//
//  Created by Julien Athomas on 24/01/16.
//  Copyright © 2016 Julien Athomas. All rights reserved.
//

#ifndef Client_hpp
#define Client_hpp

#include "Socket.hpp"

class Client
{
public:
    Client(int const fd);
    ~Client();
    Socket&     getSocket();
    int         getFd();
private:
    Socket  _socket;
};

#endif /* Client_hpp */
