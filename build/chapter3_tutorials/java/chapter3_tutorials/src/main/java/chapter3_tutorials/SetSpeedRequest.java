package chapter3_tutorials;

public interface SetSpeedRequest extends org.ros.internal.message.Message {
  static final java.lang.String _TYPE = "chapter3_tutorials/SetSpeedRequest";
  static final java.lang.String _DEFINITION = "float32 desired_speed\n";
  float getDesiredSpeed();
  void setDesiredSpeed(float value);
}
