# Copyright (c) 2021 Alfi Maulana
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess
import os
from scripts import GazeboRosPaths


def generate_launch_description():
    model_path, plugin_path, media_path = GazeboRosPaths.get_paths()

    env = {
        'GAZEBO_MODEL_PATH': model_path,
        'GAZEBO_PLUGIN_PATH': plugin_path,
        'GAZEBO_RESOURCE_PATH': media_path,
    }

    package_prefix = get_package_share_directory('dienen_gazebo_sim')
    world_file = os.path.join(package_prefix, 'worlds', 'default.world')

    return LaunchDescription(
        [
            ExecuteProcess(
                cmd=['gazebo', '--verbose', world_file],
                output='screen',
                additional_env=env,
            ),
        ]
    )
