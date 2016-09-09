//
//  data.h
//  NeuronOSCBridge
//
//  Created by Silvere Letellier on 07/09/2016.
//  Copyright © 2016 Fede. All rights reserved.
//

#ifndef data_h
#define data_h

#include "includes.h"
#include "osc.h"

Osc* theOscSocket;

class DataReceiver
{
public:
  DataReceiver()
  {
    theOscSocket = new Osc();
    BRRegisterFrameDataCallback(this, frameCallback);
    BRRegisterCalculationDataCallback(this, calcFrameCallback);
  }
  
  static void frameCallback(void* customedObj, SOCKET_REF sender, BvhDataHeader* header, float* data)
  {
    
//    float lHand = data[39 * 6 + 3];
//    float lForArm = data[38 * 6 + 3];
    float lArm = data[37 * 6 + 4];
    theOscSocket->transmit("/leftHand", lArm);
  }
  
  static void calcFrameCallback( void* customedObj, SOCKET_REF sender, CalcDataHeader* header, float* data )
  {
    float Position_X = 39 * 16 + 0;
    std::cout << "Left hand:" << Position_X << std::endl;
  }
  
  ~DataReceiver()
  {
    
  }
  
private:
  
};
#endif /* data_h */
