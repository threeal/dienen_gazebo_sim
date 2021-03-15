// Copyright (c) 2021 Alfi Maulana
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "dienen_sim/movement_plugin.hpp"
#include <gazebo/physics/physics.hh>
#include <gazebo_ros/node.hpp>

namespace dienen_sim
{

MovementPlugin::MovementPlugin()
{
}

void MovementPlugin::Load(gazebo::physics::ModelPtr model, sdf::ElementPtr sdf)
{
  node = gazebo_ros::Node::Get(sdf);

  for (auto const & joint : model->GetJoints()) {
    joints[joint->GetName()] = joint;
  }

  if (joints.size() > 0) {
    RCLCPP_INFO(node->get_logger(), "Found joints:");
    for (auto const & joint : joints) {
      RCLCPP_INFO_STREAM(node->get_logger(), joint.first);
    }
  } else {
    RCLCPP_WARN(node->get_logger(), "No joints were found!");
  }
}

void MovementPlugin::Update()
{
}

GZ_REGISTER_MODEL_PLUGIN(MovementPlugin)

}  // namespace dienen_sim
