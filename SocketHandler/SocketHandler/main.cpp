//
//  main.cpp
//  SocketHandler
//
//  Created by Julien Athomas on 24/01/16.
//  Copyright © 2016 Julien Athomas. All rights reserved.
//

#include <iostream>
#include "ServerTCP.hpp"

int main(int argc, const char * argv[])
{
    AServer *serv = new ServerTCP;
    
    serv->run(4242);
    return 0;
}
