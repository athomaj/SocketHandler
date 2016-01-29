//
//  ServerTCP.hpp
//  ServerRType
//
//  Created by Julien Athomas on 06/12/2015.
//  Copyright © 2015 Julien Athomas. All rights reserved.
//

#ifndef ServerTCP_hpp
#define ServerTCP_hpp

#include "AServer.hpp"

class ServerTCP : public AServer
{
public:
    ServerTCP();
private:
    virtual void checkFds();
    virtual void setFds();
};

#endif /* ServerTCP_hpp */
