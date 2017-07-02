//
//  connect.hpp
//  NeuronOSCBridge
//
//  Created by Silvere Letellier on 07/09/2016.
//  Copyright © 2016 Fede. All rights reserved.
//

#ifndef connect_hpp
#define connect_hpp

#include <stdio.h>

class Socket
{
public:
  Socket(char* ip, int port)
  {
    BRRegisterSocketStatusCallback (this, statusCallback);
    
    SOCKET_REF theUDP = BRStartUDPServiceAt(port);
    
    if(theUDP)
    {
      theSocketRef = BRConnectTo(ip, port);
    }
  }
  
  ~Socket()
  {
    
  }
  
  static void statusCallback(void* customedObj, SOCKET_REF sender, SocketStatus status, char* message)
  {
    std::cout << message << std::endl;
  }
  
  bool isConnected()
  {
    return theSocketRef != NULL;
  }
  
  SOCKET_REF getSocketReference()
  {
    return theSocketRef;
  }
  
private:
  SOCKET_REF theSocketRef;
};

#endif /* connect_hpp */
