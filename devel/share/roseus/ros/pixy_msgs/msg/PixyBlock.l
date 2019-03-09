;; Auto-generated. Do not edit!


(when (boundp 'pixy_msgs::PixyBlock)
  (if (not (find-package "PIXY_MSGS"))
    (make-package "PIXY_MSGS"))
  (shadow 'PixyBlock (find-package "PIXY_MSGS")))
(unless (find-package "PIXY_MSGS::PIXYBLOCK")
  (make-package "PIXY_MSGS::PIXYBLOCK"))

(in-package "ROS")
;;//! \htmlinclude PixyBlock.msg.html
(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))


(intern "*NORMAL_SIGNITURE*" (find-package "PIXY_MSGS::PIXYBLOCK"))
(shadow '*NORMAL_SIGNITURE* (find-package "PIXY_MSGS::PIXYBLOCK"))
(defconstant pixy_msgs::PixyBlock::*NORMAL_SIGNITURE* 0)
(intern "*COLOR_CODE*" (find-package "PIXY_MSGS::PIXYBLOCK"))
(shadow '*COLOR_CODE* (find-package "PIXY_MSGS::PIXYBLOCK"))
(defconstant pixy_msgs::PixyBlock::*COLOR_CODE* 1)
(defclass pixy_msgs::PixyBlock
  :super ros::object
  :slots (_type _signature _roi _angle ))

(defmethod pixy_msgs::PixyBlock
  (:init
   (&key
    ((:type __type) 0)
    ((:signature __signature) 0)
    ((:roi __roi) (instance sensor_msgs::RegionOfInterest :init))
    ((:angle __angle) 0.0)
    )
   (send-super :init)
   (setq _type (round __type))
   (setq _signature (round __signature))
   (setq _roi __roi)
   (setq _angle (float __angle))
   self)
  (:type
   (&optional __type)
   (if __type (setq _type __type)) _type)
  (:signature
   (&optional __signature)
   (if __signature (setq _signature __signature)) _signature)
  (:roi
   (&rest __roi)
   (if (keywordp (car __roi))
       (send* _roi __roi)
     (progn
       (if __roi (setq _roi (car __roi)))
       _roi)))
  (:angle
   (&optional __angle)
   (if __angle (setq _angle __angle)) _angle)
  (:serialization-length
   ()
   (+
    ;; uint16 _type
    2
    ;; uint16 _signature
    2
    ;; sensor_msgs/RegionOfInterest _roi
    (send _roi :serialization-length)
    ;; float32 _angle
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _type
       (write-word _type s)
     ;; uint16 _signature
       (write-word _signature s)
     ;; sensor_msgs/RegionOfInterest _roi
       (send _roi :serialize s)
     ;; float32 _angle
       (sys::poke _angle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _type
     (setq _type (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _signature
     (setq _signature (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; sensor_msgs/RegionOfInterest _roi
     (send _roi :deserialize buf ptr-) (incf ptr- (send _roi :serialization-length))
   ;; float32 _angle
     (setq _angle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get pixy_msgs::PixyBlock :md5sum-) "65437e5a4b3ebcdfa9a72d34e33d6dad")
(setf (get pixy_msgs::PixyBlock :datatype-) "pixy_msgs/PixyBlock")
(setf (get pixy_msgs::PixyBlock :definition-)
      "# signiture types
uint16 NORMAL_SIGNITURE=0
uint16 COLOR_CODE=1

# the message.  if type==0, then angle should be ignored.
uint16 type
uint16 signature
sensor_msgs/RegionOfInterest roi
float32 angle # in radians

================================================================================
MSG: sensor_msgs/RegionOfInterest
# This message is used to specify a region of interest within an image.
#
# When used to specify the ROI setting of the camera when the image was
# taken, the height and width fields should either match the height and
# width fields for the associated image; or height = width = 0
# indicates that the full resolution image was captured.

uint32 x_offset  # Leftmost pixel of the ROI
                 # (0 if the ROI includes the left edge of the image)
uint32 y_offset  # Topmost pixel of the ROI
                 # (0 if the ROI includes the top edge of the image)
uint32 height    # Height of ROI
uint32 width     # Width of ROI

# True if a distinct rectified ROI should be calculated from the \"raw\"
# ROI in this message. Typically this should be False if the full image
# is captured (ROI not used), and True if a subwindow is captured (ROI
# used).
bool do_rectify

")



(provide :pixy_msgs/PixyBlock "65437e5a4b3ebcdfa9a72d34e33d6dad")


