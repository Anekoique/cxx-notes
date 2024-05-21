#include"add.h"
#define USE_CUDA true
string model_path = "./models/bestv5.onnx";
string model_path_circle = "./models/best_circle.onnx";

bool readModel(Net &net, string &netPath, bool isCuda = false)
{
	try
	{
		net = readNet(netPath);
	}
	catch (const std::exception & e)
    {
        // 处理std::exception类型的异常
        RCLCPP_ERROR(this->get_logger(), "Standard exception caught: %s", e.what());
    }

    catch (const cv::Exception & e)
    {
        // 专门处理cv::Exception类型的异常
        RCLCPP_ERROR(this->get_logger(), "OpenCV exception caught: %s", e.what());
        return false;
    }
	// cuda
	if (isCuda)
	{
		net.setPreferableBackend(cv::dnn::DNN_BACKEND_CUDA);
		net.setPreferableTarget(cv::dnn::DNN_TARGET_CUDA);
	}
	// cpu
	else
	{
		net.setPreferableBackend(cv::dnn::DNN_BACKEND_DEFAULT);
		net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
	}
	return true;
}

int main()
{
    cout << "helloworld" << endl;
    int a = 1, b = 2;
    int c = add(a, b);
    cout << endl;
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;
    Net net1, net2;
    if (readModel(net1, model_path, USE_CUDA))
    {
        cout << "read net1 ok!" << endl;
    }else{
        cout << "read onnx1 model failed!";
    }
    if (readModel(net2, model_path_circle, USE_CUDA))
    {
        cout << "read net2 ok!" << endl;
    }else{
        cout << "read onnx2 model failed!";
    }
    return 0;
}
