#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std::chrono;
using namespace std;

int main() {
    // Citirea imaginii de intrare
    cv::Mat image = cv::imread("C:/Users/Ersilia/Desktop/ProiectAPD/input.jpg");

    // Verificarea daca imaginea a fost citita corect
    if (!image.data) {
        std::cout << "Could not open or find the image!" << std::endl;
        return -1;
    }
    // Măsurarea timpului de început
    auto start = high_resolution_clock::now();
    // Redimensionarea imaginii
    cv::Mat resizedImage;
    cv::resize(image, resizedImage, cv::Size(320, 240));

    // Verificarea daca imaginea a fost redimensionata corect
    if (!resizedImage.data) {
        std::cout << "Could not resize the image!" << std::endl;
        return -1;
    }
    // Măsurarea timpului de final
    auto stop = high_resolution_clock::now();

    // Calcularea timpului total de rulare
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Timpul total de rulare: " << duration.count() << " milisecunde." << endl;

    // Salvarea imaginii redimensionate
    bool success = cv::imwrite("C:/Users/Ersilia/Desktop/ProiectAPD/output.jpg", resizedImage);

    // Verificarea daca imaginea a fost salvata cu succes
    if (success) {
        std::cout << "Image resized and saved successfully!" << std::endl;
    }
    else {
        std::cout << "Could not save the resized image!" << std::endl;
        return -1;

        // Afisarea dimensiunilor imaginii redimensionate
        std::cout << "Resized image dimensions: " << resizedImage.cols << "x" << resizedImage.rows << std::endl;

        return 0;
    }
}
