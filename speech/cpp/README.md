# 语音合成，语音识别 RESTFul API C++ sdk 使用示例代码

## 准备
1. 安装必要的依赖，curl（必须带ssl） jsoncpp openssl
2. 首先拷贝整个speech目录内容，务必包含assets目录下的文件
3. 从官网下载SDK包aip-cpp-sdk-x.x.x.zip，并解压到此目录下，并且修改main.cpp的include语句引用正确的speech.h头文件
4. 修改main.cpp文件里，填写您在百度云控制台新建应用的ak，sk，并且替换include部分代码代码，引入SDK包中的speech.h文件
5. sh build.sh 编译程序
6. 运行main可执行程序

## 说明
1. 如果语音合成调用后会保存二进制内容到tts.mp3文件，可直接播放。
1. 如果返回curl_error_code 1 则说明您安装的curl不带ssl，需要重新安装带ssl的curl。
