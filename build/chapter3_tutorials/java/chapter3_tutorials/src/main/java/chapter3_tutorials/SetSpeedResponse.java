package chapter3_tutorials;

public interface SetSpeedResponse extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "chapter3_tutorials/SetSpeedResponse";
  static final java.lang.String _DEFINITION = "float32 previous_speed\nfloat32 new_speed\nbool stalled";
  float getPreviousSpeed();
  void setPreviousSpeed(float value);
  float getNewSpeed();
  void setNewSpeed(float value);
  boolean getStalled();
  void setStalled(boolean value);
}
