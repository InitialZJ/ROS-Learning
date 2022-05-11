# ROS-Learning

## 配置步骤

1. 创建ubuntu18.04虚拟机
2. 安装ROS melodic
3. 配置~/.bashrc，添加source /opt/ros/melodic/setup.bash --extend，使得程序能够找到ros的位置

## 学习资源

古月ROS入门21讲
https://www.bilibili.com/video/BV1zt411G7Vn

## 知识点

1. 创建工作区：mkdir -p ~/catkin_ws/src

2. 初始化工作区：catkin_init_workspace

3. 编译：catkin_make

4. 添加工作区资源：source devel/setup.bash

5. 创建功能包：catkin_create_pkg learning_topic roscpp rospy std_msgs geometry_msgs turtlesim

6. 在功能包下添加功能：
   
   - cpp: 在src下创建.cpp文件，修改CMakeLists，重新执行catkin_make进行编译
   
   - py: 在scripts下创建.py文件，执行命令chmod +x ....py授予执行权限，无需重新编译

7. 运行：rosrun learning_topic velocity_publisher(.py)
