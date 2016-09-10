//
//  data.h
//  NeuronOSCBridge
//
//  Created by Silvere Letellier on 07/09/2016.
//  Copyright © 2016 Fede. All rights reserved.
//

#ifndef data_h
#define data_h


#define IP_MTU_SIZE 1536
char buffer[IP_MTU_SIZE];

#include "includes.h"
#include "osc.h"

Osc* theOscSocket;

const int numSensor = 21;
const SensorData theSensorData[numSensor] = {
                                              { "/Hips", 0 },
                                              { "/RightUpLeg", 1 },
                                              { "/RightLeg", 2 },
                                              { "/RightFoot", 3 },
                                              { "/LeftUpLeg", 4 },
                                              { "/LeftLeg", 5 },
                                              { "/LeftFoot", 6 },
                                              { "/Spine", 7 },
                                              { "/Spine1", 8 },
                                              { "/Spine2", 9 },
                                              { "/Spine3", 10 },
                                              { "/Neck", 11 },
                                              { "/Head", 12 },
                                              { "/RightShoulder", 13 },
                                              { "/RightArm", 14 },
                                              { "/RightForeArm", 15 },
                                              { "/RightHand", 16 },
                                              { "/LeftShoulder", 36 },
                                              { "/LeftArm", 37 },
                                              { "/LeftForeArm", 38 },
                                              { "/LeftHand", 39 }
                                            };

enum BVHData : int
{
  Displacement_X = 0,
  Displacement_Y,
  Displacement_Z,
  Rotation_Y,
  Rotation_X,
  Rotation_Z
};

const string BVHStrings[6] = { "/Dx", "/Dy", "/Dz", "/Ry", "/Rx", "/Rz" };

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
    osc::OutboundPacketStream packet( buffer, IP_MTU_SIZE );
    packet.Clear();
    packet << osc::BeginBundle();
    
    for(int i=0 ; i<numSensor; i++)
    {
      for(int j=3; j<BVHData::Rotation_Z + 1; j++)
      {
        std::string bvhName = theSensorData[i].name; bvhName.append(BVHStrings[j]);
        packet << osc::BeginMessage(bvhName.c_str()) << data[theSensorData[i].boneIndex * 6 + j] << osc::EndMessage;
      }
    }
    
    packet << osc::EndBundle;
    
    theOscSocket->transmit(packet);
  }
  
  static void calcFrameCallback( void* customedObj, SOCKET_REF sender, CalcDataHeader* header, float* data )
  {
    std::cout << "Calculation DATA" << std::endl;
  }
  
  ~DataReceiver()
  {
    if (theOscSocket) BRCloseSocket(theOscSocket);
  }
  
private:
  
};
#endif /* data_h */
