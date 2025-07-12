#include "opencv2/opencv.hpp"

int main() {

    cv::Mat img = cv::imread("example.png", cv::IMREAD_UNCHANGED);
    cv::rectangle(img, cv::Point(0, 0), cv::Point(400, 200), cv::Scalar(0, 0, 0, 255), -1);
    cv::putText(img, "Transistor", cv::Point(50, 100), cv::FONT_ITALIC, 2.0,
                cv::Scalar(255, 255, 255, 255), 2);
    cv::imwrite("example_texts.png", img);

    return 0;
}
