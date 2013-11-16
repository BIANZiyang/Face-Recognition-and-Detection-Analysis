/* CSCI435 Computer Vision
 * Project: Facial Recognition
 * Paul Foster - 3648370
 */
#ifndef PARAMS_HPP
#define PARAMS_HPP


// This is where all the paramaters that I can tweak are located.
// They are put in one place so it is easier to play with them.
//
// Note that variables declared as const and not explicitly delared extern have internal linkage
// meaning we won't get duplicate symbols when linking translation units.
namespace params
{
    namespace training
    {
        // The faces must be broken up into training images and images used to measure performance
//        const double trainingToValidationRatio = 2/3.0f; // 66.66% of the images will be used for training
        const double trainingToValidationRatio = 0.7f; // FIXME: This is a test
    }
    namespace eigenFace
    {
        const int numComponents = 0; // This being 0 is by far the best // FIXME: TOO MANY COMPONENETS, but only numComponents=1 gave good distances but crappy performance. GO WITH 0!!
//        const int numComponents = 1; // This being 0 is by far the best // FIXME: TOO MANY COMPONENETS // 5 too low, 20 too high, 15 too high, 10 is too high, still bad results, 8 same, 7 same, 5 too high, 3 too high, 2 even too high
//        const int numComponents = 150; // FIXME: 0=>35.9551%, 10=>43.8202%, 100=> 38.2022%, 150=>35.9551
//        const int numComponents = 3;
        // const double threshold = 10.0;
        // FIXME: Below are the good params
//        const int numComponents = 0; // Setting this to 0 means the algorithm will automatically pick c-1 // FIXME: WHY IS THIS STILL CRASHING!!?? // Still crash with 8 and 5 and 4 and 3 and 2. Only 1 works. WHY??? I get "killed" message. HUH??!?? Even TRAINING data is failing!!
//        const double threshold = 50.0;
//        const double threshold = DBL_MAX; // FIXME: There is a BIG BUG in your code. Your distances for eigen and fisher are WAY too big.
        const double threshold = 4710.0f; // FIXME: I know this is WAY too big, but it gets good results
//        const double threshold = 100.0; // FIXME: This should NOT be DBL_MAX. I think that will mean it will ALWAYS classify a face (never return -1). Furthermore, reducing this WILL NOT reduce the training time / file size. This value needs to be tuned so that it correctly classifies faces but doesn't have false hits. Also must be able to say -1 for faces not in the training set.
    }
    namespace fisherFace
    {
        const int numComponents = 0; // FIXME: 0 is best
        const double threshold = DBL_MAX;
//        const double threshold = 10.0;
    }
    namespace lbphFace
    {
        // FIXME: Start current best
        // FIXME: End current best
        const int radius = 1;
        const int neighbors = 8;
        const int gridX = 7; // 7,7 is by far the best
        const int gridY = 7; // FIXME: 7 better than 8 7=>11.236%
        // FIXME: Note that if you used weighted LBP, it wouldn't matter what the grid size was - you could just train any grid to be good - the important regions would have a greater weight

//        const int radius = 4;
//        const int neighbors = 28; // FIXME: This is too big
//        const int neighbors = 10; // FIXME: This is too big
        // // FIXME: These next ones were the ones in the paper - But they actually suck (58.427%)
        // const int radius = 2;
        // const int neighbors = 8;
        // // const int gridX = 18;
        // // const int gridY = 21; // FIXME: 7 better than 8 7=>11.236%
        // // FIXME: Defaults below
        // // const int radius = 1;
        // // const int neighbors = 8;
        // const int gridX = 8;
        // const int gridY = 8;
        const double threshold = DBL_MAX;
    }
    namespace lidFace
    {
        const int inradius = 1;
        const double threshold = DBL_MAX;
//        const double clustersAsPercentageOfKeypoints = 0.01f; // FIXME: Tweak
        const double clustersAsPercentageOfKeypoints = 0.9f; // FIXME: Tweak
    }
    namespace cascadeClassifier
    {
        const double scaleFactor = 1.01;
        const int minNeighbors = 9;
        const int flags = 0; // This is a legacy parameter and it will not do anything with our application

        // Chose not to have a min/max size so that we could handle close/far faces.
        const cv::Size minSize;
        const cv::Size maxSize; // Note: In OpenCV 2.4.2, this parameter does not work for haar
    }
    namespace sift
    {
        // There is a bug in 2.4.2 where this parameter does not work, so I have to leave it at 0
        const int nfeatures = 0; // Default 0
        const int nOctaveLayers = 5; // Default 3
        const double contrastThreshold = 0.06; // Default 0.04
        const double edgeThreshold = 10; // Default 10
        const double sigma = 3; // Default 1.6
    }
    namespace kmeans
    {
        const cv::TermCriteria termCriteria(cv::TermCriteria::COUNT + cv::TermCriteria::EPS, 1000, 0.01);
        const int attempts = 5;
        const int flags = cv::KMEANS_PP_CENTERS;
        // K (the number of clusters) is not specified here as it is determined by the number of
        // keypoints (and not a compile-time constant)
    }
}

#endif
