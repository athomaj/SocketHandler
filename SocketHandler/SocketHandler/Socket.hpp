//
//  Socket.hpp
//  SocketHandler
//
//  Created by Julien Athomas on 24/01/16.
//  Copyright © 2016 Julien Athomas. All rights reserved.
//

#ifndef Socket_hpp
#define Socket_hpp

#include <iostream>
#include <map>
#include <algorithm>
#include <boost/function.hpp>
#include <boost/bind.hpp>

typedef boost::function<void (void)> FuncPtr;

class Client;
class Socket;

class Socket
{
public:
    Socket();
    ~Socket();
    template <typename... Args>
    void on(std::string const& key, Args... params)
    {
        events[key] = boost::bind(params...);
    }
    void emit(std::string const& key, std::string const& value);
    void end(std::string const& key);
    void exec(std::string const& key, Client*);
    int& getFd();
    void setFd(int const);
private:
    int     _fd;
    std::map<std::string, FuncPtr> events;
};

#include "Client.hpp"


#endif /* Socket_hpp */
