//
//  osc.h
//  NeuronOSCBridge
//
//  Created by Silvere Letellier on 09/09/2016.
//  Copyright © 2016 Fede. All rights reserved.
//

#ifndef osc_h
#define osc_h

#include "osc/OscOutboundPacketStream.h"
#include "osc/OscReceivedElements.h"
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"

#define ADDRESS "192.168.178.56"
#define PORT 7000

#define OUTPUT_BUFFER_SIZE 1024

#define IP_MTU_SIZE 1536
char buffer[IP_MTU_SIZE];

class Osc
{
public:
  Osc()
  {
    theTransmitSocket = new UdpTransmitSocket( IpEndpointName( ADDRESS, PORT ) );
  }
  
  ~Osc()
  {
  }
  
  void transmit(std::string messageName, float messageValue)
  {
    osc::OutboundPacketStream p( buffer, IP_MTU_SIZE );
    p.Clear();
    p << osc::BeginMessage(messageName.c_str())
    << true << 23 << messageValue << "hello" << osc::EndMessage;

    theTransmitSocket->Send( p.Data(), p.Size() );
  }
  
private:
  UdpTransmitSocket* theTransmitSocket;
};




#endif /* osc_h */
