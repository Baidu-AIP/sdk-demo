let AipSpeech = require("baidu-aip-sdk").speech;
let fs = require('fs');

// 务必替换百度云控制台中新建百度语音应用的 Api Key 和 Secret Key
let client = new AipSpeech(0, '请填写Api Key', '请填写Secret Key');

let voice = fs.readFileSync('../assets/16k_test.pcm');

let voiceBase64 = new Buffer(voice);

// 识别本地语音文件
client.recognize(voiceBase64, 'pcm', 16000).then(function(result) {
    console.log('语音识别本地音频文件结果: ' + JSON.stringify(result));
}, function(err) {
    console.log(err);
});

// 识别远程语音文件
client.recognizeByUrl('http://bos.nj.bpc.baidu.com/v1/audio/8k.amr', 'http://yq01-ecom-holmes22-20150818112825.yq01.baidu.com:8492/aip/dump', 'amr', 8000).then(function(result) {
    console.log('语音识别远程音频文件结果: ' + JSON.stringify(result));
}, function(err) {
    console.log(err);
});

// 语音合成，保存到本地文件
client.text2audio('', {spd: 0, per: 4}).then(function(result) {
    if (result.data) {
        console.log('语音合成成功，文件保存到tts.mp3，打开听听吧');
        fs.writeFileSync('tts.mp3', result.data);
    } else {
        // 合成服务发生错误
        console.log('语音合成失败: ' + JSON.stringify(result));
    }
}, function(err) {
    console.log(err);
});

