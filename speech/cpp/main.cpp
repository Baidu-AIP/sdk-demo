// 请替换您下载的C++SDK路径
#include "aip-cpp-sdk-x.x.x/speech.h"

void ASR(aip::Speech* client);

void ASR_url(aip::Speech* client);

void TTS(aip::Speech* client);

int main()
{
    // 务必替换百度云控制台中新建百度语音应用的 Api Key 和 Secret Key
    aip::Speech * client = new aip::Speech("填写appid", "请填写Api Key", "请填写Secret Key");
    
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
    std::cout << "语音识别本地文件结果:" << std::endl << result.toStyledString();
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
    std::cout << "语音识别远程文件结果:" << std::endl << result.toStyledString();
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
    ofile.open("./tts.mp3", std::ios::out | std::ios::binary);
    Json::Value result = client->text2audio("百度语音合成测试", options, file_ret);
    // 如果file_ret为不为空则说明合成成功，返回mp3文件内容
    if (!file_ret.empty())
    {
        // 合成成功保存文件
        ofile << file_ret;
        std::cout << "语音合成成功，打开目录下的tts.mp3文件听听看" << std::endl;
    } else {
        // 合成出错，打印错误信息
        std::cout << result.toStyledString();
    }
}
