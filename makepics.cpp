#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>

using namespace std;
using namespace cv;
using namespace cv::ml;

int main(int argc, char** argv)
{



    const char* keys =
    {
        "{help h|     | show help message}"
        "{path    |     | path of directory where to save the images/frames}"
        "{type    |     | type of the images you want to save i.e jpg,jpeg,png etc}"
        "{vid    |     | video file from which to extract images/frames}"
    };

CommandLineParser parser( argc, argv, keys );

    if ( parser.has( "help" ) )
    {
        parser.printMessage();
        cout<<"Example usage:\n"<<"./makepics --path=./myDirectory/ --type=png --vid=myVideoFile.mp4 \n"<<endl;
        exit( 0 );
    }

String path = parser.get<String>("path");
String type = parser.get<String>("type");
String vid = parser.get<String>("vid");





    Mat frame;    
    VideoCapture cap(vid);

  int totalFrames= cap.get(CAP_PROP_FRAME_COUNT);



  

   for( size_t i=0; i<=totalFrames; i++)
   {
       cap>>frame;

      if(frame.empty() )
         break;
       
       String pictureName="pic";
       pictureName += to_string(i)+"."+type;
       cout<<"Writing: "<<pictureName<<endl;
       imwrite(path+pictureName,frame);
      
   

   }


    

}
