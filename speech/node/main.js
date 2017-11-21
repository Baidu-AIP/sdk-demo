let AipSpeech = require("baidu-aip-sdk").speech;
let fs = require('fs');

let client = new AipSpeech(0, '请填写AK', '请填写SK');

let voice = fs.readFileSync('../assets/16k_test.pcm');

let voiceBase64 = new Buffer(voice);

client.recognize(voiceBase64, 'pcm', 16000).then(function(result) {
    console.log('<recognize>: ' + JSON.stringify(result));
}, function(err) {
    console.log(err);
});

client.recognizeByUrl('http://bos.nj.bpc.baidu.com/v1/audio/8k.amr', 'http://yq01-ecom-holmes22-20150818112825.yq01.baidu.com:8492/aip/dump', 'amr', 8000).then(function(result) {
    console.log('<recognizeByUrl>: ' + JSON.stringify(result));
}, function(err) {
    console.log(err);
});

client.text2audio('百度语音合成测试', {spd: 0, per: 4}).then(function(result) {
    fs.writeFileSync('tts.mp3', result.data);
}, function(err) {
    console.log(err);
});

