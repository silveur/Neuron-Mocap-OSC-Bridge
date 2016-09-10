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

#define ADDRESS "192.168.178.27"
#define PORT 7000

#define OUTPUT_BUFFER_SIZE 1024

class Osc
{
public:
  Osc()
  {
    theTransmitSocket = new UdpTransmitSocket( IpEndpointName( ADDRESS, PORT ) );
    BRStartUDPServiceAt(7001);
  }
  
  ~Osc()
  {
  }
  
  void transmit(osc::OutboundPacketStream packetToSend)
  {
    theTransmitSocket->Send( packetToSend.Data(), packetToSend.Size() );
  }
  
private:
  UdpTransmitSocket* theTransmitSocket;
};




#endif /* osc_h */
