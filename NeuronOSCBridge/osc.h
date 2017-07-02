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

#define ADDRESS "127.0.0.1"
#define PORT1 7000
#define PORT2 7001

class Osc
{
public:
  Osc()
  {
    theTransmitSocket = new UdpTransmitSocket( IpEndpointName( ADDRESS, PORT1 ) );
    theTransmitSocket2 = new UdpTransmitSocket( IpEndpointName( ADDRESS, PORT2 ) );
  }
  
  ~Osc()
  {
    delete theTransmitSocket;
  }
  
  void transmit(osc::OutboundPacketStream packetToSend)
  {
    theTransmitSocket->Send( packetToSend.Data(), packetToSend.Size() );
  }
  
  void transmit2(osc::OutboundPacketStream packetToSend)
  {
    theTransmitSocket2->Send( packetToSend.Data(), packetToSend.Size() );
  }
  
private:
  UdpTransmitSocket* theTransmitSocket;
  UdpTransmitSocket* theTransmitSocket2;
};




#endif /* osc_h */
