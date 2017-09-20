#ifndef _ROS_SERVICE_AllocateSoftware_h
#define _ROS_SERVICE_AllocateSoftware_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace concert_msgs
{

static const char ALLOCATESOFTWARE[] = "concert_msgs/AllocateSoftware";

  class AllocateSoftwareRequest : public ros::Msg
  {
    public:
      const char* user;
      const char* software;
      bool allocate;

    AllocateSoftwareRequest():
      user(""),
      software(""),
      allocate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_user = strlen(this->user);
      memcpy(outbuffer + offset, &length_user, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->user, length_user);
      offset += length_user;
      uint32_t length_software = strlen(this->software);
      memcpy(outbuffer + offset, &length_software, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->software, length_software);
      offset += length_software;
      union {
        bool real;
        uint8_t base;
      } u_allocate;
      u_allocate.real = this->allocate;
      *(outbuffer + offset + 0) = (u_allocate.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->allocate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_user;
      memcpy(&length_user, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_user; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_user-1]=0;
      this->user = (char *)(inbuffer + offset-1);
      offset += length_user;
      uint32_t length_software;
      memcpy(&length_software, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_software; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_software-1]=0;
      this->software = (char *)(inbuffer + offset-1);
      offset += length_software;
      union {
        bool real;
        uint8_t base;
      } u_allocate;
      u_allocate.base = 0;
      u_allocate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->allocate = u_allocate.real;
      offset += sizeof(this->allocate);
     return offset;
    }

    const char * getType(){ return ALLOCATESOFTWARE; };
    const char * getMD5(){ return "af208c68122c8078ba82a57ef5832bc1"; };

  };

  class AllocateSoftwareResponse : public ros::Msg
  {
    public:
      bool success;
      const char* namespace;
      const char* error_message;

    AllocateSoftwareResponse():
      success(0),
      namespace(""),
      error_message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_namespace = strlen(this->namespace);
      memcpy(outbuffer + offset, &length_namespace, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->namespace, length_namespace);
      offset += length_namespace;
      uint32_t length_error_message = strlen(this->error_message);
      memcpy(outbuffer + offset, &length_error_message, sizeof(uint32_t));
      offset += 4;
      memcpy(outbuffer + offset, this->error_message, length_error_message);
      offset += length_error_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_namespace;
      memcpy(&length_namespace, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_namespace; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_namespace-1]=0;
      this->namespace = (char *)(inbuffer + offset-1);
      offset += length_namespace;
      uint32_t length_error_message;
      memcpy(&length_error_message, (inbuffer + offset), sizeof(uint32_t));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error_message-1]=0;
      this->error_message = (char *)(inbuffer + offset-1);
      offset += length_error_message;
     return offset;
    }

    const char * getType(){ return ALLOCATESOFTWARE; };
    const char * getMD5(){ return "b5aa50ad48c828f7a608b1a685545246"; };

  };

  class AllocateSoftware {
    public:
    typedef AllocateSoftwareRequest Request;
    typedef AllocateSoftwareResponse Response;
  };

}
#endif
