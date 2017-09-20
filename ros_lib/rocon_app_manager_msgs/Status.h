#ifndef _ROS_rocon_app_manager_msgs_Status_h
#define _ROS_rocon_app_manager_msgs_Status_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "rocon_app_manager_msgs/Rapp.h"

namespace rocon_app_manager_msgs
{

  class Status : public ros::Msg
  {
    public:
      const char* application_namespace;
      const char* remote_controller;
      const char* rapp_status;
      rocon_app_manager_msgs::Rapp rapp;
      enum { RAPP_STOPPED = stopped };
      enum { RAPP_RUNNING = running };

    Status():
      application_namespace(""),
      remote_controller(""),
      rapp_status(""),
      rapp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_application_namespace = strlen(this->application_namespace);
      memcpy(outbuffer + offset, &length_application_namespace, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->application_namespace, length_application_namespace);
      offset += length_application_namespace;
      uint32_t length_remote_controller = strlen(this->remote_controller);
      memcpy(outbuffer + offset, &length_remote_controller, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->remote_controller, length_remote_controller);
      offset += length_remote_controller;
      uint32_t length_rapp_status = strlen(this->rapp_status);
      memcpy(outbuffer + offset, &length_rapp_status, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->rapp_status, length_rapp_status);
      offset += length_rapp_status;
      offset += this->rapp.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_application_namespace;
      memcpy(&length_application_namespace, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_application_namespace; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_application_namespace-1]=0;
      this->application_namespace = (char *)(inbuffer + offset-1);
      offset += length_application_namespace;
      uint32_t length_remote_controller;
      memcpy(&length_remote_controller, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_remote_controller; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_remote_controller-1]=0;
      this->remote_controller = (char *)(inbuffer + offset-1);
      offset += length_remote_controller;
      uint32_t length_rapp_status;
      memcpy(&length_rapp_status, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_rapp_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_rapp_status-1]=0;
      this->rapp_status = (char *)(inbuffer + offset-1);
      offset += length_rapp_status;
      offset += this->rapp.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "rocon_app_manager_msgs/Status"; };
    const char * getMD5(){ return "c829e85f6007b45375568abd83177e0e"; };

  };

}
#endif