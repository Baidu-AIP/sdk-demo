# 语音合成，语音识别 RESTFul API nodejs sdk 使用示例代码

## 准备
1. 首先拷贝整个speech目录内容，务必包含assets目录下的文件
2. 进入node文件夹，运行 ```npm install``` 安装包依赖
3. 在main.js文件里填写您在百度云控制台新建应用的Api Key和Secret Key
4. 运行 ```node main.js``` 运行代码

## 说明
1. 语音合成调用如果后会保存二进制内容到tts.mp3文件，可直接播放。
2. 直接运行报错，因为main.js中没有设置Api Key和Secret Key，请先在百度云控制台新建语音服务应用获取后填入。
