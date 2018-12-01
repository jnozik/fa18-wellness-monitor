#ifndef __ARRAY_H__
#define __ARRAY_H__

#define DIMENSIONS 3         // number of channels going into the PCA
#define FEATURES 1           // number of reduced dimensions going into the SVM
#define SUPPORTS 10           // number of support vectors for SVM
#define CLASSIFIERS 1        // number of classifiers created

#define NUMTAPS 6         // number of filter taps, for output adjustment
#define WINDOW 32         // number of lanes/bins/window, for output adjustment

#define DATA_WIDTH 32         // total bit size
#define DATA_BP 8         // number of fractional components

static double pcaVector[FEATURES][DIMENSIONS] = {{0.5431032698, 0.5818986773, 0.6053369043}};

static double SVMSupportVector[SUPPORTS][FEATURES] = {{-0.9158935467}, {-0.9155814039}, {-0.9153876406}, {-0.9151054178}, {-0.9149624295}, {-0.9147590469}, {-0.9142624858}, {-0.9138086068}, {-0.9137395282}, {-0.9137296489}};

static double SVMAlphaVector[CLASSIFIERS][SUPPORTS] = {{-1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0}};

static double SVMIntercept[CLASSIFIERS] = {6.6405560472};

static double in[] = {6.646, 6.1143, 5.8485, 6.1143, 1.0634, 1.8609, -0.53168, -0.79752, -0.26584, -2.3925, -4.7851, -1.8609, -1.0634, 0.0, 0.53168, -0.53168, -2.9242, -1.595, -1.595, 3.1901, 4.2534, 4.7851, 9.3044, 10.102, 12.76, 13.292, 15.419, 15.153, 17.545, 18.343, 16.748, 14.355, 15.419, 14.621, 12.76, 14.621, 17.014, 17.014, 21.267, 19.938, 18.343, 17.545, 15.95, 17.28, 17.014, 16.748, 15.153, 14.621, 12.229, 11.165, 11.697, 10.368, 7.7093, 12.494, 14.089, 16.748, 16.748, 16.748, 20.47, 21.799, 26.052, 27.381, 26.052, 31.369, 28.445, 28.179, 31.103, 32.166, 31.369, 31.901, 26.584, 23.925, 25.786, 22.065, 23.66, 22.596, 21.267, 19.406, 15.153, 11.697, 10.368, 8.5068, 4.2534, 1.0634, -0.79752, -4.5193, -7.1776, -12.494, -12.229, -13.026, -13.824, -12.494, -13.292, -18.077, -25.521, -27.116, -31.369, -29.242, -31.369, -30.571, -27.647, -27.381, -26.584, -22.862, -22.065, -25.255, -22.862, -22.33, -21.001, -17.014, -15.419, -24.989, -37.483, -54.231, -62.472, -69.65, -69.384, -67.789, -63.535, -67.789, -60.611, -51.573, -41.205, -37.217, -15.153, -8.7727, -7.4435, 2.6584, 1.595, -1.595, 11.697, 8.241, 6.3801, 15.153, 8.7727, 3.9876, 7.7093, 8.5068, -6.1143, -3.4559, -16.482, -26.584, -18.875, -26.85, -45.193, -44.129, -53.434, -60.08, -61.94, -65.928, -73.903, -82.144, -81.081, -82.41, -87.993, -93.044, -92.246, -93.044, -92.512, -91.449, -86.132, -82.41, -79.752, -73.371, -68.055, -60.877, -55.826, -49.18, -40.939, -32.166, -24.191, -19.672, -15.95, -12.76, -3.9876, -0.53168, 3.4559, 9.3044, 15.153, 19.406, 24.191, 29.508, 34.293, 35.888, 38.812, 39.344, 43.332, 47.585, 49.446, 51.307, 53.434, 54.763, 51.573, 53.168, 53.434, 52.636, 52.104, 51.307, 48.648, 49.18, 51.307, 52.37, 52.104, 53.965, 55.029, 54.231, 56.092, 56.624, 55.56, 51.839, 48.648, 47.585, 44.661, 37.483, 39.078, 36.686, 36.154, 32.698, 29.242, 28.711, 26.052, 25.255, 21.267, 17.545, 14.621, 14.089, 15.419, 12.76, 12.494, 8.5068, 5.0509, 5.0509, 4.2534, 4.2534, 1.8609, 0.53168, -1.3292, -5.0509, -7.4435, -5.3168, -6.9118, -5.5826, -5.5826, -7.9752, -4.2534, -6.1143, -8.241, -9.5702, -14.621, -14.887, -15.419, -16.216, -14.887, -13.824, -15.684, -17.811, -15.95, -14.355, -15.95, -16.216, -15.95, -18.609, -18.875, -22.065, -20.735, -23.128, -28.711, -31.103, -32.432, -38.015, -39.876, -45.193, -44.927, -44.927, -43.066, -42.268, -41.205, -43.863, -46.256, -47.585, -49.712, -49.712, -55.029, -53.965, -56.889, -56.092, -58.75, -62.206, -65.662, -63.27, -66.194, -62.472, -59.814, -54.763, -51.839, -49.978, -45.99, -47.851, -45.458, -44.395, -35.091, -28.976, -19.938, -14.089, -12.76, -11.697, -9.3044, -8.241, -6.9118, -8.5068, -10.102, -8.5068, -8.241, -10.368, -7.9752, -10.899, -8.7727, -5.0509, -2.9242, 0.0, 3.4559, 1.8609, 1.595, 1.8609, 3.9876, 8.5068, 12.76, 13.558, 15.684, 18.077, 21.533, 26.85, 28.445, 29.508, 31.103, 29.242, 27.116, 23.925, 20.204, 18.609, 16.482, 19.406, 14.887, 17.545, 18.343, 15.153, 18.343, 17.28, 14.089, 10.634, 6.3801, 2.1267, -1.3292, -2.6584, -5.8485, -8.5068, -13.558, -18.343, -23.925, -22.065, -20.735, -20.47, -21.267, -19.406, -15.684, -16.482, -16.748, -12.76, -9.836, -5.8485, -2.9242, -2.9242, 1.595, 4.2534, 6.3801, 9.836, 13.824, 15.419, 14.887, 15.95, 18.609, 20.735, 20.47, 23.925, 28.179, 26.584, 22.33, 24.457, 23.66, 21.533, 19.14, 16.482, 15.95, 12.76, 15.95, 12.76, 13.824, 13.824, 13.824, 18.343, 19.406, 21.001, 20.47, 18.609, 19.406, 15.419, 14.355, 16.482, 12.494, 13.292, 12.494, 10.102, 8.7727, 10.102, 10.634, 10.899, 13.292, 13.292, 12.229, 14.887, 17.28, 17.545, 20.47, 20.735, 19.672, 20.204, 22.862, 24.723, 24.989, 27.116, 29.774, 30.04, 28.711, 28.711, 26.85, 26.318, 28.445, 27.116, 30.04, 28.179, 27.381, 23.394, 21.533, 18.609, 14.621, 9.836, 11.165, 8.7727, 8.241, 3.4559, 6.9118, 7.4435, 7.9752, 11.697, 9.836, 4.5193, 2.1267, -0.53168, 1.595, -1.0634, -3.9876, -6.9118, -9.0385, -10.634, -6.9118, -9.0385, -10.368, -10.102, -11.165, -6.1143, -7.7093, -5.3168, -2.6584, -2.1267, 1.3292, 2.9242, 5.0509, 6.646, 5.5826, 9.3044, 10.368, 13.026, 12.494, 15.95, 15.419, 15.95, 19.406, 19.406, 15.684, 14.089, 11.697, 9.5702, 10.634, 10.368, 9.0385, 7.7093, 8.5068, 5.8485, 8.5068, 9.5702, 9.0385, 6.646, 1.0634, -1.0634, -5.8485, -6.646, -7.9752, -9.5702, -11.165, -10.634, -9.5702, -9.3044, -9.5702, -12.76, -13.824, -13.558, -8.7727, -5.0509, -2.6584, -1.3292, 6.1143, 7.9752, 12.229, 13.026, 14.355, 18.609, 19.938, 20.47, 20.47, 23.394, 26.052, 30.837, 32.432, 28.976, 24.723, 14.355, 1.595, -15.95, -28.711, -36.952, -42.8, -42.534, -42.003, -41.471, -35.091, -27.116, -19.672, -12.229, 1.0634, 13.292, 15.419, 20.735, 21.533, 18.609, 22.862, 22.33, 19.14, 33.23, 28.445, 19.14, 36.154, 14.621, 4.5193, 11.431, 8.241, -9.836, -4.7851, -13.026, -19.406, -13.824, -24.191, -31.369, -36.952, -45.458, -57.421, -66.194, -70.713, -73.903, -81.081, -79.22, -77.891, -78.688, -73.371, -63.27, -52.636, -43.598, -32.964, -25.255, -14.887, -1.3292, 7.7093, 17.811, 22.862, 33.23, 39.61, 42.8, 44.395, 51.839, 51.839, 54.497, 59.282, 64.067, 68.055, 69.384, 66.46, 66.194, 69.118, 67.257, 69.118, 72.308, 72.308, 69.65, 67.523, 66.46, 65.662, 60.877, 63.27, 63.535, 65.13, 64.865, 61.143, 63.535, 64.067, 62.206, 55.029, 54.497, 60.345, 52.37, 46.788, 36.952, 34.027, 28.976, 22.862, 21.267, 15.684, 16.216, 13.292, 14.621, 14.355, 12.76, 12.76, 11.165, 12.76, 15.684, 18.343, 21.799, 24.989, 27.381, 27.116, 24.457, 25.521, 26.584, 23.66, 22.596, 22.862, 26.052, 25.255, 23.128, 26.318, 27.647, 25.521, 28.179, 29.508, 27.647, 27.913, 30.306, 30.571, 31.369, 26.584, 29.508, 32.964, 35.091, 35.091, 31.103, 27.381, 27.647, 30.571, 30.04, 26.052, 15.95, 13.558, 14.887, 12.494, 9.5702, 10.102, 8.7727, 5.5826, 6.646, 4.7851, 2.3925, 1.3292, 0.79752, 0.0, 0.0, 1.595, 1.3292, 4.7851, 6.646, 13.292, 15.95, 19.938, 24.457, 25.786, 29.774, 26.85, 28.445, 27.116, 26.584, 26.584, 27.647, 28.179, 27.647, 25.521, 24.457, 24.989, 22.065, 23.128, 23.128, 25.786, 28.179, 30.04, 24.989, 24.723, 24.457, 25.521, 27.381, 24.989, 27.647, 32.166, 33.762, 31.369, 30.04, 26.318, 26.052, 27.647, 27.647, 32.432, 32.964, 35.622, 36.42, 38.812, 44.129, 45.193, 49.712, 52.902, 51.041, 51.307, 50.509, 48.648, 51.307, 52.902, 54.497, 56.358, 59.016, 60.877, 63.535, 61.409, 61.94, 57.421, 59.016, 57.953, 57.953, 55.826, 54.231, 52.902, 52.104, 55.294, 57.687, 58.75, 60.877, 61.675, 61.409, 58.75, 58.219, 57.953, 55.294, 58.485, 58.75, 56.624, 52.104, 49.446, 49.446, 52.902, 55.826, 56.358, 58.75, 59.282, 60.08, 63.27, 63.27, 63.004, 65.662, 67.789, 65.928, 61.94, 58.219, 55.294, 54.497, 53.699, 55.56, 58.219, 56.889, 58.75, 63.27, 58.75, 57.687, 61.409, 60.08, 60.611, 64.865, 70.447, 77.359, 76.827, 76.296, 77.359, 78.954, 78.157, 79.486, 79.752, 78.954, 77.625, 76.03, 78.157, 79.22, 80.815, 81.878, 85.068, 86.929, 85.334, 78.954, 73.637, 71.776, 70.979, 73.106, 74.169, 73.637, 74.169, 76.03, 77.625, 77.359, 73.371, 73.637, 74.701, 77.359, 76.562, 78.688, 78.422, 78.422, 76.827, 76.827, 76.827, 77.891, 77.891, 74.169, 73.106, 72.84, 70.713, 69.916, 70.447, 68.852, 67.523, 69.384, 70.181, 68.055, 68.586, 68.055, 66.991, 62.738, 64.333, 66.991, 65.662, 59.814, 58.75, 54.497, 52.104, 51.307, 53.699, 51.839, 56.358, 55.826, 56.358, 53.434, 49.446, 47.053, 50.244, 46.522, 47.319, 48.383, 46.788, 45.458, 47.053, 50.244, 55.826, 58.75, 64.599, 69.65, 72.308, 75.498, 75.498, 76.03, 74.967, 69.118, 68.055, 67.257, 67.789, 65.928, 68.055, 68.321, 69.118, 65.396, 65.928, 72.574, 73.903, 76.562, 78.422, 77.625, 79.22, 80.815, 81.347, 84.803, 84.803, 83.208, 86.132, 83.739, 82.41, 82.144, 80.815, 76.827, 77.625, 76.03, 74.169, 74.169, 67.523, 68.321, 63.27, 58.75, 56.358, 51.041, 51.839, 45.99, 42.534, 45.193, 43.863, 40.939, 39.61, 38.547, 39.61, 40.142, 38.015, 41.471, 41.471, 45.193, 40.673, 42.268, 41.737, 40.407, 34.027, 34.027, 32.698, 32.698, 34.293, 37.483, 38.812, 37.217, 36.154, 33.762, 35.622, 35.091, 34.027, 34.559, 35.888, 35.622, 32.698, 36.686, 36.154, 36.952, 33.496, 28.976, 26.318, 22.33, 18.343, 18.077, 22.862, 30.837, 35.091, 40.407, 40.939, 43.863, 44.927, 47.585, 44.661, 40.407, 42.003, 40.939, 42.534, 47.851, 43.863, 40.939, 43.066, 41.205};

static double ex[][2] = {{0.0, 401.3325739251385}, {0.0, 459.6499091283785}, {0.0, 590.1884234050505}, {0.0, 848.0319946418233}, {0.0, 1392.427479224405}, {0.0, 2112.8938638624318}, {0.0, 2415.3567529307293}, {0.0, 2092.210905164286}, {0.0, 1248.406056697989}, {0.0, 568.8750624281741}, {0.0, 465.1256734438194}, {0.0, 790.5700429752204}, {0.0, 1236.8645100603076}, {0.0, 1500.9421041040105}, {0.0, 1347.350714264717}, {0.0, 886.662187894539}, {0.0, 492.6968313460394}, {0.0, 379.39785551043775}, {0.0, 339.2102154766468}, {0.0, 283.88762536903215}, {0.0, 345.54507439539947}, {0.0, 538.2079457820174}, {0.0, 648.4831264887636}, {0.0, 615.7249611811314}, {0.0, 511.6607551747444}, {0.0, 384.31074023940664}, {0.0, 465.7816889874234}, {0.0, 724.4640786233828}, {0.0, 904.4896845302197}, {0.0, 1112.3478732864567}, {0.0, 1445.2410673965553}, {0.0, 1525.2243045241207}, {0.0, 1241.129316246602}, {0.0, 829.5223079447617}, {0.0, 648.6707533998439}, {0.0, 640.3057911995942}, {0.0, 634.6711470936822}, {0.0, 607.6375483664505}, {0.0, 556.997190793286}, {0.0, 546.760604095299}, {0.0, 542.917787114656}, {0.0, 534.3790958838739}, {0.0, 549.4062114943296}, {0.0, 573.3744638100582}, {0.0, 568.5795481266255}, {0.0, 628.0245895641297}, {0.0, 693.9891954875616}, {0.0, 693.1445305155225}, {0.0, 605.6688477852526}, {0.0, 642.0072499739431}, {0.0, 894.9835303715123}, {0.0, 1185.0662528984299}, {0.0, 1284.2986655663456}, {0.0, 1510.5172588311868}, {0.0, 2378.265960017357}, {0.0, 3321.4447970923597}, {0.0, 3763.513692938669}, {0.0, 3614.0194468646478}, {0.0, 3197.698086986267}};

#endif
