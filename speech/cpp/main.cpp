#include "aip-cpp-sdk-x.x.x/speech.h"

void ASR(aip::Speech* client);

void ASR_url(aip::Speech* client);

void TTS(aip::Speech* client);

int main()
{
    aip::Speech * client = new aip::Speech("填写appid", "请填写ak", "请填写sk");
    
    ASR(client);
    
    ASR_url(client);

    TTS(client);
    
    return 0;
}

/**
 * ASR语音识别示例
 */
void ASR(aip::Speech* client) {
    std::map<std::string, std::string> options;
    options["lan"] = "ZH";
    std::string file_content;
    aip::get_file_content("../assets/16k_test.pcm", &file_content);
    Json::Value result = client->recognize(file_content, "pcm", 16000, options);
    std::cout << result.toStyledString();
}

/**
 * ASR语音识别示例,使用远程文件地址
 */
void ASR_url(aip::Speech* client) {
    std::map<std::string, std::string> options;
    options["lan"] = "zh";
    Json::Value result =
    client->recognize_url("http://bos.nj.bpc.baidu.com/v1/audio/8k.amr",
                          "http://your_site/dump",
                          "amr", 8000, options);
    std::cout << result.toStyledString();
}

/**
 * TTS语音合成示例
 */
void TTS(aip::Speech* client) {
    std::ofstream ofile;
    std::string file_ret;
    std::map<std::string, std::string> options;
    options["spd"] = "5";
    options["per"] = "2";
    ofile.open("./tts.mp3");
    Json::Value result = client->text2audio("百度语音合成测试", options, file_ret);
    // 如果error_code字段为空则说明合成成功，返回mp3文件内容
    if (result["error_code"] == Json::nullValue)
    {
        ofile << file_ret;
    }
    std::cout << result.toStyledString();
}
