;; Auto-generated. Do not edit!


(when (boundp 'chapter3_tutorials::SetSpeed)
  (if (not (find-package "CHAPTER3_TUTORIALS"))
    (make-package "CHAPTER3_TUTORIALS"))
  (shadow 'SetSpeed (find-package "CHAPTER3_TUTORIALS")))
(unless (find-package "CHAPTER3_TUTORIALS::SETSPEED")
  (make-package "CHAPTER3_TUTORIALS::SETSPEED"))
(unless (find-package "CHAPTER3_TUTORIALS::SETSPEEDREQUEST")
  (make-package "CHAPTER3_TUTORIALS::SETSPEEDREQUEST"))
(unless (find-package "CHAPTER3_TUTORIALS::SETSPEEDRESPONSE")
  (make-package "CHAPTER3_TUTORIALS::SETSPEEDRESPONSE"))

(in-package "ROS")





(defclass chapter3_tutorials::SetSpeedRequest
  :super ros::object
  :slots (_desired_speed ))

(defmethod chapter3_tutorials::SetSpeedRequest
  (:init
   (&key
    ((:desired_speed __desired_speed) 0.0)
    )
   (send-super :init)
   (setq _desired_speed (float __desired_speed))
   self)
  (:desired_speed
   (&optional __desired_speed)
   (if __desired_speed (setq _desired_speed __desired_speed)) _desired_speed)
  (:serialization-length
   ()
   (+
    ;; float32 _desired_speed
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _desired_speed
       (sys::poke _desired_speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _desired_speed
     (setq _desired_speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(defclass chapter3_tutorials::SetSpeedResponse
  :super ros::object
  :slots (_previous_speed _new_speed _stalled ))

(defmethod chapter3_tutorials::SetSpeedResponse
  (:init
   (&key
    ((:previous_speed __previous_speed) 0.0)
    ((:new_speed __new_speed) 0.0)
    ((:stalled __stalled) nil)
    )
   (send-super :init)
   (setq _previous_speed (float __previous_speed))
   (setq _new_speed (float __new_speed))
   (setq _stalled __stalled)
   self)
  (:previous_speed
   (&optional __previous_speed)
   (if __previous_speed (setq _previous_speed __previous_speed)) _previous_speed)
  (:new_speed
   (&optional __new_speed)
   (if __new_speed (setq _new_speed __new_speed)) _new_speed)
  (:stalled
   (&optional __stalled)
   (if __stalled (setq _stalled __stalled)) _stalled)
  (:serialization-length
   ()
   (+
    ;; float32 _previous_speed
    4
    ;; float32 _new_speed
    4
    ;; bool _stalled
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _previous_speed
       (sys::poke _previous_speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _new_speed
       (sys::poke _new_speed (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _stalled
       (if _stalled (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _previous_speed
     (setq _previous_speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _new_speed
     (setq _new_speed (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _stalled
     (setq _stalled (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass chapter3_tutorials::SetSpeed
  :super ros::object
  :slots ())

(setf (get chapter3_tutorials::SetSpeed :md5sum-) "7baf09683aadda2fb755474c2726a14c")
(setf (get chapter3_tutorials::SetSpeed :datatype-) "chapter3_tutorials/SetSpeed")
(setf (get chapter3_tutorials::SetSpeed :request) chapter3_tutorials::SetSpeedRequest)
(setf (get chapter3_tutorials::SetSpeed :response) chapter3_tutorials::SetSpeedResponse)

(defmethod chapter3_tutorials::SetSpeedRequest
  (:response () (instance chapter3_tutorials::SetSpeedResponse :init)))

(setf (get chapter3_tutorials::SetSpeedRequest :md5sum-) "7baf09683aadda2fb755474c2726a14c")
(setf (get chapter3_tutorials::SetSpeedRequest :datatype-) "chapter3_tutorials/SetSpeedRequest")
(setf (get chapter3_tutorials::SetSpeedRequest :definition-)
      "float32 desired_speed
---
float32 previous_speed
float32 new_speed
bool stalled

")

(setf (get chapter3_tutorials::SetSpeedResponse :md5sum-) "7baf09683aadda2fb755474c2726a14c")
(setf (get chapter3_tutorials::SetSpeedResponse :datatype-) "chapter3_tutorials/SetSpeedResponse")
(setf (get chapter3_tutorials::SetSpeedResponse :definition-)
      "float32 desired_speed
---
float32 previous_speed
float32 new_speed
bool stalled

")



(provide :chapter3_tutorials/SetSpeed "7baf09683aadda2fb755474c2726a14c")


