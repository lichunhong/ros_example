// Auto-generated. Do not edit!

// (in-package chapter3_tutorials.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class SetSpeedRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.desired_speed = null;
    }
    else {
      if (initObj.hasOwnProperty('desired_speed')) {
        this.desired_speed = initObj.desired_speed
      }
      else {
        this.desired_speed = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetSpeedRequest
    // Serialize message field [desired_speed]
    bufferOffset = _serializer.float32(obj.desired_speed, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetSpeedRequest
    let len;
    let data = new SetSpeedRequest(null);
    // Deserialize message field [desired_speed]
    data.desired_speed = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a service object
    return 'chapter3_tutorials/SetSpeedRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4d5008c9d834e2c102355282755ead21';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 desired_speed
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetSpeedRequest(null);
    if (msg.desired_speed !== undefined) {
      resolved.desired_speed = msg.desired_speed;
    }
    else {
      resolved.desired_speed = 0.0
    }

    return resolved;
    }
};

class SetSpeedResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.previous_speed = null;
      this.new_speed = null;
      this.stalled = null;
    }
    else {
      if (initObj.hasOwnProperty('previous_speed')) {
        this.previous_speed = initObj.previous_speed
      }
      else {
        this.previous_speed = 0.0;
      }
      if (initObj.hasOwnProperty('new_speed')) {
        this.new_speed = initObj.new_speed
      }
      else {
        this.new_speed = 0.0;
      }
      if (initObj.hasOwnProperty('stalled')) {
        this.stalled = initObj.stalled
      }
      else {
        this.stalled = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type SetSpeedResponse
    // Serialize message field [previous_speed]
    bufferOffset = _serializer.float32(obj.previous_speed, buffer, bufferOffset);
    // Serialize message field [new_speed]
    bufferOffset = _serializer.float32(obj.new_speed, buffer, bufferOffset);
    // Serialize message field [stalled]
    bufferOffset = _serializer.bool(obj.stalled, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type SetSpeedResponse
    let len;
    let data = new SetSpeedResponse(null);
    // Deserialize message field [previous_speed]
    data.previous_speed = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [new_speed]
    data.new_speed = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [stalled]
    data.stalled = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 9;
  }

  static datatype() {
    // Returns string type for a service object
    return 'chapter3_tutorials/SetSpeedResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '45b6e4a0b69c96c06231db93d740f980';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 previous_speed
    float32 new_speed
    bool stalled
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new SetSpeedResponse(null);
    if (msg.previous_speed !== undefined) {
      resolved.previous_speed = msg.previous_speed;
    }
    else {
      resolved.previous_speed = 0.0
    }

    if (msg.new_speed !== undefined) {
      resolved.new_speed = msg.new_speed;
    }
    else {
      resolved.new_speed = 0.0
    }

    if (msg.stalled !== undefined) {
      resolved.stalled = msg.stalled;
    }
    else {
      resolved.stalled = false
    }

    return resolved;
    }
};

module.exports = {
  Request: SetSpeedRequest,
  Response: SetSpeedResponse,
  md5sum() { return '7baf09683aadda2fb755474c2726a14c'; },
  datatype() { return 'chapter3_tutorials/SetSpeed'; }
};
