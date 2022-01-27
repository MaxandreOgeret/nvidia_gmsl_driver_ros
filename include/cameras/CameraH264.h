// Created by Maxandre Ogeret.
// (c) 2022 University of Tartu - Autonomous Driving Lab.

#ifndef SEKONIX_CAMERA_UT_CAMERAH264_H
#define SEKONIX_CAMERA_UT_CAMERAH264_H

#include <memory>

#include "encoders/DriveWorksH264Serializer.h"
#include "cameras/CameraBase.h"

#include <dw/sensors/SensorSerializer.h>

class CameraH264 : public CameraBase
{
public:
  /**
   * @brief Constructor, initializes encoder and h264 image publisher.
   * @throws SekonixFatalException
   * @param driveworksApiWrapper
   * @param config
   * @param interface
   * @param link
   * @param nodehandle
   */
  CameraH264(DriveworksApiWrapper* driveworksApiWrapper, const YAML::Node& config, std::string interface,
             std::string link, ros::NodeHandle* nodehandle);

  /**
   * @brief Calls poll, encode. Doesn't call publish as it is part of the encoder's callback.
   */
  void run_pipeline() override;

  /**
   * @brief Polls camera for frame, extracts image and timestamp.
   * @throws SekonixFatalException
   * @throws SekonixMinorException
   */
  void poll() override;

  /**
   * @brief Pushes polled data to the encoder. The encoder will then call it's own callback.
   * @throws SekonixFatalException
   */
  void encode() override;

  inline static const std::string ENCODER_TYPE_ = "h264";

private:
  ros::Publisher pub_h264_;
  std::unique_ptr<DriveWorksH264Serializer> encoder_;

  int bitrate_;
  serializer_user_data_t_ serializerUserData_{};
};

#endif  // SEKONIX_CAMERA_UT_CAMERAH264_H
